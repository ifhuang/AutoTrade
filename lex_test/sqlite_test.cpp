#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../lex/data/data.h"
using namespace std;
using lex::Data;

namespace lex_test
{		
	TEST_CLASS(SqliteTest)
	{
	public:

        TEST_METHOD(TestSelectStudies)
        {
            Data d("lex_test.db");
            auto studies = d.SelectStudies();
            Assert::AreEqual(1U, studies.size());
            auto study = studies[0];
            Assert::AreEqual(string("test"), study.get<0>());
            Assert::AreEqual(true, study.get<1>());
        }

        TEST_METHOD(TestSelectStudiesEmpty)
        {
            Data d("lex_test_empty.db");
            auto studies = d.SelectStudies();
            Assert::AreEqual(0U, studies.size());
        }
	};


}