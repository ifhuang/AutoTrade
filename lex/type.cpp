#include "type.h"

#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;

#include "check_visitor.h"
#include "table.h"

namespace lex
{
    int kAstTrue;

    SetUpEnviroment enviroment;

    int SetUpEnviroment::ReserveSpace(ast_t exp, int size /*= 1*/)
    {
        int position = num_variables;
        num_variables += size;
        Initialize init;
        init.size = size;
        init.exp = exp;
        initialize_list.push_back(init);
        return position;
    }

    string get_var(ast_t idx)
    {
        ast &node = astV[idx];
        if (node.type != NodeType::VAR)throw SemanticError("Internal get_var", &kDefaultLocation);
        return strVector[node.idx];
    }

    void check_paras(const StdFunction *function, asts_t idx, const YYLTYPE *loc, bool is_input = false)
    {
        auto &paras = function->paras;
        if (idx < 0)
        {
            if (!paras.empty() && function->min != 0)
            {
                throw SemanticError("invalid number of parameters", loc);
            }
            return;
        }
        vector<ast_t> &args = astsV[idx];
        if (function->min == -1 && paras.size() != args.size()
            || function->min != -1 && paras.size() < args.size())
        {
            throw SemanticError("invalid number of parameters", loc);
        }
        for (size_t i = 0; i < args.size(); i++)
        {
            VType at = get_type(args[i], is_input);
            if (at != paras[i])
            {
                throw SemanticError("incorrect argument type", loc);
            }
        }
    }

    VType check_func(ast_t &idx, bool is_input /*= false*/)
    {
        ast &func = astV[idx];
        auto loc = GetLocation(func.left);
        string name = get_var(func.left);
        VSource source = find_name(name);
        switch (source)
        {
        case VSource::StdFunction: {
            const StdFunction *function = funcTable.at(name);
            check_paras(function, func.right, loc, is_input);
            return function->result;
                                   }
        case VSource::Input: {
            if (is_input)throw SemanticError("input cannot contain input", loc);
            if (func.right != -2)throw SemanticError("not a function, is input", loc);
            Input input = inputTable[name];
            idx = input.exp;
            return input.type;
                             }
        case VSource::Variable:	{
            if (is_input)throw SemanticError("input cannot contain variable", loc);
            if (func.right != -2)throw SemanticError("not a function, is variable", loc);
            Variable variable = varTable[name];
            func.type = NodeType::VAR;
            func.idx = variable.position;
            return variable.type;
                                }
        case VSource::Undefined: {
            string es = "'" + name + "' : undeclared identifier";
            throw SemanticError(es.c_str(), loc);
                                 }
        default:
            throw SemanticError();
        }
    }

    VType get_type(ast_t &idx, bool is_input /*= false*/)
    {
        ast &node = astV[idx];
        auto loc = GetLocation(idx);
        switch (node.type)
        {
            VType l, r;
        case NodeType::ADD:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l != r)throw TypesNotCompatible(loc);
            if (l == VType::NUMERIC || l == VType::TEXT)return l;
            throw InvalidTypeOperation(loc);
        case NodeType::SUB:
        case NodeType::MUL:
        case NodeType::DIV:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l != r)throw TypesNotCompatible(loc);
            if (l == VType::NUMERIC)return l;
            throw InvalidTypeOperation(loc);
        case NodeType::AND:
        case NodeType::OR:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l != r)throw TypesNotCompatible(loc);
            if (l == VType::TF)return l;
            throw InvalidTypeOperation(loc);
        case NodeType::NOT:
            l = get_type(node.left);
            if (l == VType::TF)return l;
            throw InvalidTypeOperation(loc);
        case NodeType::BAR:
            l = get_type(node.left);
            r = get_type(node.right);
            if (r == VType::TEXT)throw InvalidTypeOperation(loc);
            return l;
        case NodeType::UMINUS:
        case NodeType::UPLUS:
            l = get_type(node.left);
            if (l == VType::NUMERIC)return l;
            throw InvalidTypeOperation(loc);
        case NodeType::NUMERIC:
            try
            {
                node.dv = boost::lexical_cast<double>(strVector[node.idx]);
            }
            catch (boost::bad_lexical_cast)
            {
                throw SemanticError("bad numeric", loc);
            }
            return VType::NUMERIC;
        case NodeType::TF:
            return VType::TF;
        case NodeType::TEXT:
            return VType::TEXT;
        case NodeType::EQ:
        case NodeType::NE:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l == r)return VType::TF;
            throw TypesNotCompatible(loc);
        case NodeType::GT:
        case NodeType::LT:
        case NodeType::GE:
        case NodeType::LE:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l != r)throw TypesNotCompatible(loc);
            if (l == VType::NUMERIC || l == VType::TEXT)return VType::TF;
            throw InvalidTypeOperation(loc);
        case NodeType::CA:
        case NodeType::CB:
            l = get_type(node.left);
            r = get_type(node.right);
            if (l != r)throw TypesNotCompatible(loc);
            if (l == VType::NUMERIC)return VType::TF;
            throw InvalidTypeOperation(loc);
        case NodeType::FUNC:
            return check_func(idx, is_input);
        default:
            throw SemanticError();
        }
    }

    void check_stmts(stmts_t idx)
    {
        for (stmt_t stmt : stmtsV[idx])
        {
            check(stmt);
        }
    }

    void check(stmt_t stmt)
    {
        if (stmt == -1)return;
        boost::apply_visitor(check_visitor(), stmtV[stmt]);
    }

    void check_input()
    {
        for (ast_t idx : inputVector)
        {
            ast &input = astV[idx];
            auto loc = GetLocation(idx);
            if (input.type == NodeType::IBPVARDEC)
            {
                throw SemanticError("This attribute can be applied only for variables", loc);
            }
            string name = get_var(input.left);
            VSource source = find_name(name);
            if (source != VSource::Undefined)
            {
                throw SemanticError("this word has already been defined", loc);
            }
            VType type = get_type(input.right, true);
            Input in{ name, type, input.right };
            //in.name = name;
            //in.type = type;
            //in.exp = input.right;
            inputTable[name] = in;
            enviroment.inputs.push_back(in);
        }
    }

    void init()
    {
        kAstTrue = newtf(kDefaultLocation, true);
    }

    void storage()
    {
        Program p = { enviroment, strVector, astV, astsV, stmtV, stmtsV };
    }

    void type_check()
    {
        init();
        check_input();
        check_stmts(root);
    }
}  // namespace lex
