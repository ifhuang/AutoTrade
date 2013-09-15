#include "exec_visitor.h"

#include <string>
using namespace std;

#include "execution.h"
using namespace lex;


int exec_visitor::get_n_m(ast_t idx) const
{
    if (idx == -1)return -1;
    double dv = exe_->check_value<double>(idx);
    return (int)dv;
}

class print_visitor : public boost::static_visitor<int>
{
public:
    print_visitor() {}

    void Print(Value v, int n, int m)
    {
        n_ = n;
        m_ = m;
        if (remain == -1)return;
        int g = boost::apply_visitor(*this, v);
        if (~g)
        {
            buffp += g;
            remain -= g;
        }
        else
        {
            remain = -1;
        }
    }

    string ToString()
    {
        return buff;
    }

    int operator()(double d)
    {
        if (~n_)
        {
            int m = ~m_ ? m_ : 6;
            int n = m ? n_ + 1 + m : n_;
            return _snprintf_s(buffp, remain, _TRUNCATE, "%*.*f", n, m, d);
        }
        else
        {
            return _snprintf_s(buffp, remain, _TRUNCATE, "%f", d);
        }
    }

    int operator()(bool d)
    {
        int n = ~n_ ? n_ : 0;
        return _snprintf_s(buffp, remain, _TRUNCATE, "%*s", n, d ? "true" : "false");
    }

    int operator()(const string & s)
    {
        int n = ~n_ ? n_ : 0;
        return _snprintf_s(buffp, remain, _TRUNCATE, "%*s", n, s.c_str());
    }

private:
    int n_, m_;
    char buff[256];
    char *buffp = buff;
    size_t remain = 256;
};



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
    bool con = os.con == -1 || exe_->check_value<bool>(os.con);
    if (con)exe_->exec(os.stmt);
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

}

void exec_visitor::operator()(block_stmt & bs) const
{
    exe_->exec_stmts(bs.stmts);
}

void exec_visitor::operator()(var_stmt & vs) const
{

}

void exec_visitor::operator()(print_stmt & ps) const
{
    if (~ps.list)
    {
        print_visitor pv;
        for (ast_t item : astsV[ps.list])
        {
            ast &node = astV[item];
            Value v = exe_->value(node.left);
            int n = get_n_m(node.mid);
            int m = get_n_m(node.right);
            pv.Print(v, n, m);
        }
        cout << pv.ToString();
    }
    cout << endl;
}
