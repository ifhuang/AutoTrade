#include "check_visitor.h"

#include "bison/front.h"
#include "table.h"
#include "type.h"
using namespace std;
using namespace lex;

namespace lex
{
    void CheckVisitor::operator()(if_stmt & is) const
    {
        if (checker_.GetType(is.con) != VType::TF)throw LogicalExpressionExpected(GetLocation(is.con));
        checker_.Check(is.then);
        checker_.Check(is.els);
    }

    void CheckVisitor::operator()(once_stmt & os) const
    {
        if (~os.con && checker_.GetType(os.con) != VType::TF)
            throw LogicalExpressionExpected(GetLocation(os.con));
        checker_.Check(os.stmt);
        os.con_position = checker_.ReserverTrue();
    }

    void CheckVisitor::operator()(for_stmt & fs) const
    {
        Table &table = checker_.GetTable();
        string name = checker_.GetVar(fs.var);
        VSource source = table.FindName(name);
        if (source != VSource::Variable)
        {
            throw SemanticError("array or varable expected", GetLocation(fs.var));
        }
        Variable var = table.GetVariable(name);
        if (var.type != VType::NUMERIC)
        {
            throw InvalidTypeOperation(GetLocation(fs.var));
        }
        VType ft = checker_.GetType(fs.from);
        if (ft == VType::TEXT)throw TypesNotCompatible(GetLocation(fs.from));
        VType tt = checker_.GetType(fs.to);
        if (tt == VType::TEXT)throw TypesNotCompatible(GetLocation(fs.to));
        checker_.Check(fs.block);
    }

    void CheckVisitor::operator()(while_stmt & ws) const
    {
        if (checker_.GetType(ws.con) != VType::TF)
            throw LogicalExpressionExpected(GetLocation(ws.con));
        checker_.CheckStmts(ws.stmts);
    }

    void CheckVisitor::operator()(switch_stmt & ws) const
    {

    }

    void CheckVisitor::operator()(order_stmt & os) const
    {

    }

    void CheckVisitor::operator()(func_stmt & fs) const
    {
        checker_.GetType(fs.func);
    }

    void CheckVisitor::operator()(asm_stmt & as) const
    {
        string name = checker_.GetVar(as.var);
        VSource source = checker_.GetTable().FindName(name);
        switch (source)
        {
        case VSource::Variable:
            check_asm_variable(name, as);
            break;
        default:
            throw SemanticError("array or varable expected", GetLocation(as.var));
        }
    }

    void CheckVisitor::operator()(block_stmt & bs) const
    {
        checker_.CheckStmts(bs.stmts);
    }

    void CheckVisitor::operator()(var_stmt & vs) const
    {
        for (ast_t idx : astsV[vs.vars])
        {
            ast &var = astV[idx];
            string name = checker_.GetVar(var.left);
            VSource source = checker_.GetTable().FindName(name);
            if (source != VSource::Undefined)
            {
                throw SemanticError("this word has already been defined", GetLocation(var.left));
            }
            VType type = checker_.GetType(var.right);
            checker_.GetTable().DeclareVar(name, type, var.right);
        }
    }

    void CheckVisitor::operator()(print_stmt & ps) const
    {
        if (~ps.list)
        {
            for (ast_t item : astsV[ps.list])
            {
                ast &print = astV[item];
                VType l_type = checker_.GetType(print.left);
                int nm = check_n_m(print);
                switch (l_type)
                {
                case VType::NUMERIC:
                    break;
                case VType::TF:
                case VType::TEXT:
                    if (nm == 2)throw SemanticError("m cannot apply to this type", GetLocation(print.right));
                    break;
                default:
                    throw SemanticError();
                }
            }
        }
    }

    void CheckVisitor::check_asm_variable(string name, asm_stmt &as) const
    {
        Variable variable = checker_.GetTable().GetVariable(name);
        switch (variable.type)
        {
        case VType::NUMERIC:
            break;
        case VType::TEXT:
            if (as.type != AsmType::kEQ && as.type != AsmType::kADD)
                throw InvalidTypeOperation(&as.type_loc);
            break;
        case VType::TF:
            if (as.type != AsmType::kEQ)throw InvalidTypeOperation(&as.type_loc);
            break;
        }
        VType rightType = checker_.GetType(as.exp);
        if (variable.type != rightType)
        {
            throw TypesNotCompatible(&as.type_loc);
        }
        ast &var = astV[as.var];
        var.idx = variable.position;
    }

    int CheckVisitor::check_n_m(ast &print) const
    {
        if (print.mid == -1)return 0;
        if (checker_.GetType(print.mid) != VType::NUMERIC)
            throw SemanticError("n must be numeric", GetLocation(print.mid));
        if (print.right == -1)return 1;
        if (checker_.GetType(print.right) != VType::NUMERIC)
            throw SemanticError("m must be numeric", GetLocation(print.right));
        return 2;
    }
}
