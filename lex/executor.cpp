#include "executor.h"

#include <vector>
#include <boost/variant.hpp>
using namespace std;

#include "exec_visitor.h"
#include "operator.h"

namespace lex{
    Executor::Executor(const SetUpEnviroment & sue) :sue_(sue)
    {

    }

    Executor::~Executor()
    {
        if (rte_)delete rte_;
    }

    Value Executor::value(ast_t idx)
    {
        ast &n = astV[idx];
        switch (n.type)
        {
        case NodeType::ADD:
            return boost::apply_visitor(add_visitor(), value(n.left), value(n.right));
        case NodeType::SUB:
            return boost::apply_visitor(sub_visitor(), value(n.left), value(n.right));
        case NodeType::MUL:
            return boost::apply_visitor(mul_visitor(), value(n.left), value(n.right));
        case NodeType::DIV:
            return boost::apply_visitor(div_visitor(), value(n.left), value(n.right));
        case NodeType::AND:
            return boost::apply_visitor(and_visitor(), value(n.left), value(n.right));
        case NodeType::OR:
            return boost::apply_visitor(or_visitor(), value(n.left), value(n.right));
        case NodeType::NOT:
            return boost::apply_visitor(not_visitor(), value(n.left));
        case NodeType::BAR:
            return boost::apply_visitor(or_visitor(), value(n.left), value(n.right));
        case NodeType::UMINUS:
            return boost::apply_visitor(not_visitor(), value(n.left));
        case NodeType::NUMERIC:
            return n.dv;
        case NodeType::TF:
            return n.bv;
        case NodeType::TEXT:
            return strVector[n.idx];
        case NodeType::EQ:
            return boost::apply_visitor(eq_visitor(), value(n.left), value(n.right));
        case NodeType::NE:
            return boost::apply_visitor(ne_visitor(), value(n.left), value(n.right));
        case NodeType::GT:
            return boost::apply_visitor(gt_visitor(), value(n.left), value(n.right));
        case NodeType::LT:
            return boost::apply_visitor(gt_visitor(), value(n.right), value(n.left));
        case NodeType::GE:
            return boost::apply_visitor(ge_visitor(), value(n.left), value(n.right));
        case NodeType::LE:
            return boost::apply_visitor(ge_visitor(), value(n.right), value(n.left));
        case NodeType::CA:
            return boost::apply_visitor(ca_visitor(), value(n.left), value(n.right));
        case NodeType::CB:
            return boost::apply_visitor(ca_visitor(), value(n.right), value(n.left));
        case NodeType::FUNC:
            //return check_func(idx);
        case NodeType::VAR:
            return rte_->GetVar(n.idx);
        default:
            throw RuntimeException();
        }
        return double(0.0);
    }

    void Executor::exec_stmts(stmts_t idx)
    {
        for (stmt_t stmt : stmtsV[idx])
        {
            exec(stmt);
        }
    }

    void Executor::exec(stmt_t stmt)
    {
        if (stmt == -1)return;
        boost::apply_visitor(exec_visitor(this), stmtV[stmt]);
    }

    void Executor::SetUp()
    {
        if (!rte_)
        {
            int n = sue_.initialize_list.size();
            vector<RteInitialize> rte_list(n);
            for (int i = 0; i < n; i++)
            {
                const Initialize &init = sue_.initialize_list[i];
                rte_list[i].size = init.size;
                rte_list[i].value = value(init.exp);
            }
            rte_ = new RunTimeEnvironment(rte_list);
        }
    }

    void Executor::execute()
    {
        SetUp();
        exec_stmts(root);
    }

}  // namespace lex
