#ifndef LEX_AST_SERIALIZATION_H_
#define LEX_AST_SERIALIZATION_H_

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/serialization/vector.hpp>

#include "../ast.h"

namespace boost {
    namespace serialization {

        template<class Archive>
        void save_construct_data(Archive & ar, ast *t, const unsigned int file_version)
        {
            ar << t->type;
            ar << t->loc;
        }

        template<class Archive>
        void load_construct_data(Archive & ar, ast *t, const unsigned int file_version)
        {
            NodeType type;
            ar >> type;
            YYLTYPE loc;
            ar >> loc;
            ::new(t)ast(type, loc);
        }

        template<class Archive>
        void serialize(Archive &ar, ast &node, const unsigned int version)
        {
            ar & binary_object(&node.dv, 3 * sizeof(ast_t));
        }

        template<class Archive>
        void serialize(Archive &ar, YYLTYPE &loc, const unsigned int version)
        {
            ar & loc.first_line;
            ar & loc.first_column;
            ar & loc.last_line;
            ar & loc.last_column;
        }

    } // namespace serialization
} // namespace boost

#endif  // LEX_AST_SERIALIZATION_H_
