#ifndef TC_STRING_PROCESSOR_H_
#define TC_STRING_PROCESSOR_H_

#include <string>
#include "PriceItem.h"

class StringProcessor
{
public:

    /// <summary>   4102 string to price item. </summary>
    ///
    /// <param name="priceStr"> The 4102 string. </param>
    /// <returns>   a PriceItem*. </returns>
    static PriceItem* StringToPriceItem(std::string priceStr);
};

#endif  // TC_STRING_PROCESSOR_H_
