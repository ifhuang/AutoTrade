#ifndef TC_STRING_PROCESSOR_H_
#define TC_STRING_PROCESSOR_H_

#include <string>
#include "OrderItem.h"
#include "Position.h"
#include "PriceItem.h"
#include "TradeItem.h"

class StringProcessor
{
public:

    /// <summary>   4102 string to price item. </summary>
    ///
    /// <param name="price_str"> The 4102 string. </param>
    /// <returns>   null if it fails, else a PriceItem*. </returns>
    static PriceItem* StringToPriceItem(std::string price_str);

    /// <summary>   9901 string to position. </summary>
    ///
    /// <param name="order_str">    The order string. </param>
    /// <returns>   null if it fails, else a Position*. </returns>
    static Position* StringToPosition(std::string order_str);

    /// <summary>   3103 strint to order item. </summary>
    ///
    /// <param name="order_str">    The order string. </param>
    /// <returns>   null if it fails, else an OrderItem*. </returns>
    static OrderItem* StrintToOrderItem(std::string order_str);

    static std::string OrderItemToString(OrderItem* po, const std::string &account_no);

    /// <summary>   3109 string to trade item. </summary>
    ///
    /// <param name="trade_str">    The trade string. </param>
    /// <returns>   null if it fails, else a TradeItem*. </returns>
    static TradeItem* StringToTradeItem(std::string trade_str);
};

#endif  // TC_STRING_PROCESSOR_H_
