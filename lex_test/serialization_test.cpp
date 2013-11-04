#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../lex/vv.h"
#include "../lex/data/program_serialization.h"

#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;
using namespace lex;

class A
{
public:
    int i;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int)
    {
        ar & i;
    }
};

namespace lex_test
{

    TEST_CLASS(SerializationTest)
    {
    public:
        TEST_METHOD(TestPointer)
        {
            stringstream ss;
            boost::archive::text_oarchive oa(ss);
            A *a = new A();
            a->i = 1;
            oa << a;
            boost::archive::text_iarchive ia(ss);
            A *b;
            ia >> b;
            Assert::AreEqual(1, b->i);
            delete a;
            delete b;
        }

        TEST_METHOD(TestSetUpEnviroment)
        {
            SetUpEnviroment sue;
            Initialize ini = { 0, 1 };
            sue.initialize_list.push_back(ini);
            ofstream ofs("test1");
            boost::archive::text_oarchive oa(ofs);
            oa << sue;
            Assert::AreEqual(1, 1);
        }

        TEST_METHOD(TestVV)
        {
            VV<int> vv("test1");
            vv.put(1);
            vv.put(2);
            vv.create();
            stringstream ss;
            boost::archive::text_oarchive oa(ss);
            oa << vv;
            VV<int> *vvp = &vv;
            oa << vvp;
            boost::archive::text_iarchive ia(ss);
            VV<int> devv;
            ia >> devv;
            Assert::AreEqual(1, devv[0]);
            Assert::AreEqual(2, devv[1]);
            Assert::AreEqual(0, devv[2]);
            
            VV<int> *devvp;
            ia >> devvp;
            Assert::AreEqual(1, (*devvp)[0]);
            Assert::AreEqual(2, (*devvp)[1]);
            Assert::AreEqual(0, (*devvp)[2]);
        }
    };
}