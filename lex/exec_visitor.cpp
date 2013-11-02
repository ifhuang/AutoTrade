#include "exec_visitor.h"

#include <string>
using namespace std;

#include "execution.h"
#include "operator.h"
#include "tree.h"

namespace lex
{
    ExecVisitor::ExecVisitor(AbstractExecutor &exe) :exe_(exe) {}

    void ExecVisitor::operator()(const if_stmt & is) const
    {
        bool con = exe_.CheckGetValue<bool>(is.con);
        exe_.Exec(con ? is.then : is.then);
    }

    void ExecVisitor::operator()(const once_stmt & os) const
    {
        bool & once = exe_.CheckGetVar<bool>(os.con_position);
        if (!once)return;
        bool con = os.con == -1 || exe_.CheckGetValue<bool>(os.con);
        if (con)
        {
            once = false;
            exe_.Exec(os.stmt);
        }
    }

    void ExecVisitor::operator()(const for_stmt & fs) const
    {

    }

    void ExecVisitor::operator()(const while_stmt & ws) const
    {
        if (ws.type == 0)
        {
            while (exe_.CheckGetValue<bool>(ws.con))
            {
                exe_.ExecStmts(ws.stmts);
            }
        }
        else
        {
            do
            {
                exe_.ExecStmts(ws.stmts);
            } while (!exe_.CheckGetValue<bool>(ws.con));
        }
    }

    void ExecVisitor::operator()(const switch_stmt & ws) const
    {

    }

    void ExecVisitor::operator()(const order_stmt & os) const
    {

    }

    void ExecVisitor::operator()(const func_stmt & fs) const
    {

    }

    void ExecVisitor::operator()(const asm_stmt & as) const
    {
        const ast &var = exe_.GetAst(as.var);
        Value &lhs = exe_.GetVar(var.idx);
        Value v = exe_.GetValue(as.exp);
        switch (as.type)
        {
        case AsmType::kEQ:
            lhs = v;
            break;
        case AsmType::kADD:
            lhs = boost::apply_visitor(add_visitor(), lhs, v);
            break;
        case AsmType::kSUB:
            lhs = boost::apply_visitor(sub_visitor(), lhs, v);
            break;
        case AsmType::kMUL:
            lhs = boost::apply_visitor(mul_visitor(), lhs, v);
            break;
        case AsmType::kDIV:
            lhs = boost::apply_visitor(div_visitor(), lhs, v);
            break;
        default:
            throw RuntimeException();
        }
    }

    void ExecVisitor::operator()(const block_stmt & bs) const
    {
        exe_.ExecStmts(bs.stmts);
    }

    void ExecVisitor::operator()(const var_stmt & vs) const
    {
        /* do nothing */
    }
}  // namespace lex
