#ifndef TC_STRING_PROCESSOR_H_
#define TC_STRING_PROCESSOR_H_

#include <string>
#include "PriceItem.h"

class StringProcessor
{
public:

    /// <summary>   String to price item.  4102 string. </summary>
    ///
    /// <param name="priceStr"> The price item string. </param>
    /// <returns>   a PriceItem*. </returns>
    static PriceItem* StringToPriceItem(std::string priceStr);
};

#endif  // TC_STRING_PROCESSOR_H_
