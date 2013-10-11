#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../lex/data/data.h"

namespace lex_test
{		
	TEST_CLASS(SqliteTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            lex::Data d;
            d.test();
            Assert::AreEqual(1, 1);
		}

	};
}