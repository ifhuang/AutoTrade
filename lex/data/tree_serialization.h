#ifndef LEX_TREE_SERIALIZATION_H_
#define LEX_TREE_SERIALIZATION_H_

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/serialization/vector.hpp>

#include "../type.h"
#include "ast_serialization.h"

namespace boost {
    namespace serialization {

        using namespace lex;

        template<class Archive>
        void serialize(Archive &ar, if_stmt &is, const unsigned int version)
        {
            ar & is.con;
            ar & is.then;
            ar & is.els;
        }

        template<class Archive>
        void serialize(Archive &ar, once_stmt &os, const unsigned int version)
        {
            ar & os.con;
            ar & os.con_position;
            ar & os.stmt;
        }

        template<class Archive>
        void serialize(Archive &ar, for_stmt &fs, const unsigned int version)
        {
            ar & fs.var;
            ar & fs.type;
            ar & fs.from;
            ar & fs.to;
            ar & fs.block;
        }

        template<class Archive>
        void serialize(Archive &ar, while_stmt &ws, const unsigned int version)
        {
            ar & ws.type;
            ar & ws.con;
            ar & ws.stmts;
        }

        template<class Archive>
        void serialize(Archive &ar, switch_stmt &ss, const unsigned int version)
        {
            ar & ss.con;
            ar & ss.sections;
        }

        template<class Archive>
        void serialize(Archive &ar, order_stmt &os, const unsigned int version)
        {
            ar & os.op;
            ar & os.name;
            ar & os.num;
            ar & os.time;
            ar & os.type;
            ar & os.price;
        }

        template<class Archive>
        void serialize(Archive &ar, func_stmt &fs, const unsigned int version)
        {
            ar & fs.func;
        }

        template<class Archive>
        void serialize(Archive &ar, asm_stmt &as, const unsigned int version)
        {
            ar & as.var;
            ar & as.type;
            ar & as.type_loc;
            ar & as.exp;
        }

        template<class Archive>
        void serialize(Archive &ar, var_stmt &vs, const unsigned int version)
        {
            ar & vs.type;
            ar & vs.vars;
        }

        template<class Archive>
        void serialize(Archive &ar, block_stmt &bs, const unsigned int version)
        {
            ar & bs.stmts;
        }

        template<class Archive>
        void serialize(Archive &ar, print_stmt &ps, const unsigned int version)
        {
            ar & ps.location;
            ar & ps.list;
        }
    } // namespace serialization
} // namespace boost

namespace lex{
    std::string save(Program &p);

}

#endif  // LEX_TREE_SERIALIZATION_H_
