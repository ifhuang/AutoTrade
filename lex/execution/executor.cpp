#include "executor.h"

#include <vector>
#include <boost/variant.hpp>
using namespace std;

#include "operator.h"

namespace lex
{
    Executor::Executor(const Program *program) : visitor_(*this), program_(program),
        sue_(program->sue), strVector_(*program->strVector),
        astV_(*program->astV), astsV_(*program->astsV),
        stmtV_(*program->stmtV), stmtsV_(*program->stmtsV), rte_(*program) {}

    Executor::~Executor()
    {
        
    }

    vector<Value> Executor::exec_paras(asts_t idx)
    {
        vector<Value> r;
        if (idx < 0)
        {
            return r;
        }
        const vector<ast_t> &args = astsV_[idx];
        for (size_t i = 0; i < args.size(); i++)
        {
            r.push_back(GetValue(args[i]));
        }
        return r;
    }

    Value Executor::exec_func(ast_t idx)
    {
        const ast &func = astV_[idx];
        string name = get_var(func.left);
        const StdFunction *function = table_.GetStdFunction(name);
        vector<Value> args = exec_paras(func.right);
        return function->call(0, args);
    }

    Value Executor::GetValue(ast_t idx)
    {
        const ast &n = astV_[idx];
        switch (n.type)
        {
        case NodeType::ADD:
            return boost::apply_visitor(add_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::SUB:
            return boost::apply_visitor(sub_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::MUL:
            return boost::apply_visitor(mul_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::DIV:
            return boost::apply_visitor(div_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::AND:
            return boost::apply_visitor(and_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::OR:
            return boost::apply_visitor(or_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::NOT:
            return boost::apply_visitor(not_visitor(), GetValue(n.left));
        case NodeType::BAR:
            return boost::apply_visitor(or_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::UPLUS:
            return CheckGetValue<double>(n.left);
        case NodeType::UMINUS:
            return boost::apply_visitor(not_visitor(), GetValue(n.left));
        case NodeType::NUMERIC:
            return n.dv;
        case NodeType::TF:
            return n.bv;
        case NodeType::TEXT:
            return strVector_[n.idx];
        case NodeType::EQ:
            return boost::apply_visitor(eq_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::NE:
            return boost::apply_visitor(ne_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::GT:
            return boost::apply_visitor(gt_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::LT:
            return boost::apply_visitor(gt_visitor(), GetValue(n.right), GetValue(n.left));
        case NodeType::GE:
            return boost::apply_visitor(ge_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::LE:
            return boost::apply_visitor(ge_visitor(), GetValue(n.right), GetValue(n.left));
        case NodeType::CA:
            return boost::apply_visitor(ca_visitor(), GetValue(n.left), GetValue(n.right));
        case NodeType::CB:
            return boost::apply_visitor(ca_visitor(), GetValue(n.right), GetValue(n.left));
        case NodeType::FUNC:
            return exec_func(idx);
        case NodeType::VAR:
            return rte_.GetVar(n.idx);
        case NodeType::INPUT:
            return GetValue(rte_.GetInput(n.idx));
        default:
            throw RuntimeException();
        }
        return double(0.0);
    }

    void Executor::ExecStmts(stmts_t idx)
    {
        if (idx == -1)return;
        for (stmt_t stmt : stmtsV_[idx])
        {
            Exec(stmt);
        }
    }

    void Executor::Exec(stmt_t stmt)
    {
        if (stmt == -1)return;
        boost::apply_visitor(visitor_, stmtV_[stmt]);
    }

    void Executor::SetUp()
    {
        if (!rte_.Initialized())
        {
            int n = sue_.initialize_list.size();
            vector<RteInitialize> rte_list(n);
            for (int i = 0; i < n; i++)
            {
                const Initialize &init = sue_.initialize_list[i];
                rte_list[i].size = init.size;
                rte_list[i].value = GetValue(init.exp);
            }
            rte_.Initialize(rte_list);
        }
    }

    void Executor::execute()
    {
        SetUp();
        ExecStmts(program_->root);
    }

    std::string Executor::get_var(ast_t idx)
    {
        const ast &node = astV_[idx];
        if (node.type != NodeType::VAR)throw RuntimeException("Internal get_var");
        return strVector_[node.idx];
    }

    const ast& Executor::GetAst(ast_t idx)
    {
        return astV_[idx];
    }

    const std::vector<ast_t>& Executor::GetAsts(asts_t idx)
    {
        return astsV_[idx];
    }

    Value& Executor::GetVar(int position)
    {
        return rte_.GetVar(position);
    }
}  // namespace lex
