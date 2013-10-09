#ifndef LEX_TYPE_SERIALIZATION_H_
#define LEX_TYPE_SERIALIZATION_H_

#include "type.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace boost {
    namespace serialization {

        template<class Archive>
        void serialize(Archive & ar, SetUpEnviroment & sue, const unsigned int version)
        {
            ar & sue.inputs;
            ar & sue.initialize_list;
        }

        template<class Archive>
        void serialize(Archive & ar, Input & i, const unsigned int version)
        {
            ar & i.exp;
            ar & i.exp_string;
            ar & i.name;
            ar & i.type;
        }

        template<class Archive>
        void serialize(Archive & ar, Initialize & i, const unsigned int version)
        {
            ar & i.exp;
            ar & i.size;
        }

    } // namespace serialization
} // namespace boost

#endif  // LEX_TYPE_SERIALIZATION_H_
