#ifndef TC_STRING_PROCESSOR_H_
#define TC_STRING_PROCESSOR_H_

#include <string>
#include "Position.h"
#include "PriceItem.h"

class StringProcessor
{
public:

    /// <summary>   4102 string to price item. </summary>
    ///
    /// <param name="price_str"> The 4102 string. </param>
    /// <returns>   a PriceItem*. </returns>
    static PriceItem* StringToPriceItem(std::string price_str);

    /// <summary>   9901 string to position. </summary>
    ///
    /// <param name="order_str">    The order string. </param>
    /// <returns>   null if it fails, else a Position*. </returns>
    static Position* StringToPosition(std::string order_str);
};

#endif  // TC_STRING_PROCESSOR_H_
