#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../TC/string_processor.h"

#include <string>
using namespace std;

namespace TC_test
{		
    TEST_CLASS(StringProcessorTest)
	{
	public:
		
        TEST_METHOD(TestStringToPriceItem)
		{
            string test_string = "4102,0,NQZ3,2013-12,1,20,1387468800,N\
Q,,0,-,,3207.25,8,3207,5,3206.75,5,3206.5,3,3206.25,6,3207.5,7,3207.75,1,3208,\
1,3208.25,8,3208.5,6,3207.5,1,3207.5,9,3207.5,4,3207.25,4,3207.25,2,0,0,9546,3\
207.5,3207.5,3205,3205,3210.25,3195,3225.5,0,0,0";
            PriceItem* pi = StringProcessor::StringToPriceItem(test_string);
            Assert::AreEqual(string("NQZ3"), pi->quoteId);
            Assert::AreEqual(1, pi->qouteType);
            Assert::AreEqual(20, pi->contractSize);
            Assert::AreEqual(1387468800, pi->ExpiryDate);
            Assert::AreEqual(3205.0, pi->openD);
            Assert::AreEqual(3210.25, pi->highD);
            Assert::AreEqual(3195.0, pi->lowD);
		}

	};
}