#include "exec_visitor.h"

#include <string>
using namespace std;

#include "execution.h"
using namespace Execution;

namespace{
    int get_n_m(ast_t idx)
    {
        if (idx == -1)return -1;
        double dv = check_value<double>(idx);
        return (int)dv;
    }

    class print_visitor : public boost::static_visitor<int>
    {
    public:
        print_visitor() {}

        void Print(ast & node)
        {
            n_ = get_n_m(node.mid);
            m_ = get_n_m(node.right);
            if (remain == -1)return;
            int g = boost::apply_visitor(*this, value(node.left));
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
}  // namespace

void exec_visitor::operator()(if_stmt & is) const
{
    bool con = check_value<bool>(is.con);
    exec(con ? is.then : is.then);
}

void exec_visitor::operator()(once_stmt & os) const
{
    bool con = os.con == -1 || check_value<bool>(os.con);
    if (con)exec(os.stmt);
}

void exec_visitor::operator()(for_stmt & fs) const
{

}

void exec_visitor::operator()(while_stmt & ws) const
{
    if (ws.type == 0)
    {
        while (check_value<bool>(ws.con))
        {
            exec(ws.block);
        }
    }
    else
    {
        do
        {
            exec(ws.block);
        } while (check_value<bool>(ws.con));
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
    exec_stmts(bs.stmts);
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
            ast &print = astV[item];
            pv.Print(print);
        }
        cout << pv.ToString();
    }
    cout << endl;
}
