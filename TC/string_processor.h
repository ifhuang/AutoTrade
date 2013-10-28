#ifndef TC_STRING_PROCESSOR_H_
#define TC_STRING_PROCESSOR_H_

#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "global.h"
#include "OrderItem.h"
#include "Position.h"
#include "PriceItem.h"
#include "TradeItem.h"

class Spliter
{
public:
    Spliter() {}
    Spliter(std::string str, const char *s = ",");

    //void CopyFrom(const Spliter &another);

    bool Exists(size_t idx);

    template<class T>
    T Get(size_t idx);

    Spliter Sub(size_t idx);

private:
    Spliter(std::vector<std::string> message_split);

    std::vector<std::string> message_split_;
};

class Joiner
{
public:
    Joiner(std::string str) : str_(str) {}

    template<class T>
    Joiner& Put(T item)
    {
        items_.push_back(boost::lexical_cast<std::string>(item));
        return *this;
    }

    std::string Join() const;

private:
    std::vector<std::string> items_;
    std::string str_;
    DISALLOW_COPY_AND_ASSIGN(Joiner);
};

class StringProcessor
{
public:

    /// <summary>   4102 string to price item. </summary>
    ///
    /// <param name="price_str"> The 4102 string. </param>
    /// <returns>   null if it fails, else a PriceItem*. </returns>
    static PriceItem* StringToPriceItem(Spliter spliter);

    /// <summary>   9901 string to position. </summary>
    ///
    /// <param name="order_str">    The order string. </param>
    /// <returns>   null if it fails, else a Position*. </returns>
    static Position* StringToPosition(Spliter spliter);

    /// <summary>   3103 strint to order item. </summary>
    ///
    /// <param name="order_str">    The order string. </param>
    /// <returns>   null if it fails, else an OrderItem*. </returns>
    static OrderItem* StrintToOrderItem(Spliter spliter);

    static std::string OrderItemToString(OrderItem* po, const std::string &account_no);

    /// <summary>   3109 string to trade item. </summary>
    ///
    /// <param name="trade_str">    The trade string. </param>
    /// <returns>   null if it fails, else a TradeItem*. </returns>
    static TradeItem* StringToTradeItem(Spliter spliter);
};

#endif  // TC_STRING_PROCESSOR_H_
