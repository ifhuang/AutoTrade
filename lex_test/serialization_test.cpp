#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../lex/data/type_serialization.h"

#include <fstream>
using namespace std;
using namespace lex;

namespace lex_test
{
    TEST_CLASS(SerializationTest)
    {
    public:

        TEST_METHOD(TestSetUpEnviroment)
        {
            SetUpEnviroment sue;
            sue.initialize_list.push_back(Initialize{ 0, 1 });
            ofstream ofs("test1");
            boost::archive::text_oarchive oa(ofs);
            oa << sue;
            Assert::AreEqual(1, 1);
        }

    };
}