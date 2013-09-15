#include "exec_visitor.h"

#include <string>
#include <boost/variant.hpp>
using namespace std;

#include "execution.h"
#include "operator.h"
using namespace lex;

exec_visitor::exec_visitor(lex::Executor *exe) :exe_(exe)
{

}


void exec_visitor::operator()(if_stmt & is) const
{
    bool con = exe_->check_value<bool>(is.con);
    exe_->exec(con ? is.then : is.then);
}

void exec_visitor::operator()(once_stmt & os) const
{
    bool & once = boost::get<bool>(exe_->rte_->GetVar(os.con_position));
    if (!once)return;
    bool con = os.con == -1 || exe_->check_value<bool>(os.con);
    if (con)
    {
        once = false;
        exe_->exec(os.stmt);
    }
}

void exec_visitor::operator()(for_stmt & fs) const
{

}

void exec_visitor::operator()(while_stmt & ws) const
{
    if (ws.type == 0)
    {
        while (exe_->check_value<bool>(ws.con))
        {
            exe_->exec(ws.block);
        }
    }
    else
    {
        do
        {
            exe_->exec(ws.block);
        } while (exe_->check_value<bool>(ws.con));
    }
}

void exec_visitor::operator()(switch_stmt & ws) const
{

}

void exec_visitor::operator()(order_stmt & os) const
{

}

void exec_visitor::operator()(func_stmt & fs) const
{

}

void exec_visitor::operator()(asm_stmt & as) const
{
    ast &var = astV[as.var];
    Value &lhs = exe_->rte_->GetVar(var.idx);
    Value v = exe_->value(as.exp);
    switch (as.type)
    {
    case kEQ:
        lhs = v;
        break;
    case kADD:
        lhs = boost::apply_visitor(add_visitor(), lhs, v);
        break;
    case kSUB:
        lhs = boost::apply_visitor(sub_visitor(), lhs, v);
        break;
    case kMUL:
        lhs = boost::apply_visitor(mul_visitor(), lhs, v);
        break;
    case kDIV:
        lhs = boost::apply_visitor(div_visitor(), lhs, v);
        break;
    default:
        throw RuntimeException();
    }
}

void exec_visitor::operator()(block_stmt & bs) const
{
    exe_->exec_stmts(bs.stmts);
}

void exec_visitor::operator()(var_stmt & vs) const
{
    /* do nothing */
}

