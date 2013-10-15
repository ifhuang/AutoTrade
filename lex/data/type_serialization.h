#ifndef LEX_TYPE_SERIALIZATION_H_
#define LEX_TYPE_SERIALIZATION_H_

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/serialization/vector.hpp>

#include "../type.h"
#include "ast_serialization.h"
#include "tree_serialization.h"

namespace boost {
    namespace serialization {

        using namespace lex;

        template<class Archive>
        void serialize(Archive &ar, SetUpEnviroment &sue, const unsigned int version)
        {
            ar & sue.inputs;
            ar & sue.initialize_list;
        }

        template<class Archive>
        void serialize(Archive &ar, Input &i, const unsigned int version)
        {
            ar & i.exp;
            ar & i.exp_string;
            ar & i.name;
            ar & i.type;
        }

        template<class Archive>
        void serialize(Archive &ar, Initialize &i, const unsigned int version)
        {
            ar & i.exp;
            ar & i.size;
        }

        template<class Archive>
        void serialize(Archive &ar, Program &p, const unsigned int version)
        {
            ar & p.sue;
            ar & p.strVector;
            ar & p.astV;
            ar & p.astsV;
            ar & p.stmtV;
            ar & p.stmtsV;
        }

    } // namespace serialization
} // namespace boost

namespace lex{
    std::string save(const Program &p);
    Program load(const std::string &s);
}

#endif  // LEX_TYPE_SERIALIZATION_H_
