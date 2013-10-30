#ifndef LEX_INTERFACE_LEX_INTERFACE_H_
#define LEX_INTERFACE_LEX_INTERFACE_H_

#include <memory>
#include <string>
#include <vector>

#include "tc_bar_interface.h"

namespace lex
{
    struct LexStudy
    {
        std::string name;
        bool ready_status;
    };

    struct LexInput
    {
        std::string name;
        std::string value;
    };

    enum class BuySell { Buy, Sell, BuyToCover, SellShort };
    enum class OrderType { Market };

    struct OrderInfo
    {
        BuySell buy_sell;
        OrderType type;
    };

    struct OrderAction
    {
        double price;
        int qty;
    };

    struct SignalDetail
    {
        std::vector<LexInput> inputs;
    };

    class LexRunnerInterface
    {
    public:
        virtual ~LexRunnerInterface() {}
        virtual void Run() = 0;
    };

    class SignalRunnerInterface
    {
    public:
        virtual ~SignalRunnerInterface() {}
        virtual std::vector<OrderInfo> GetOrderInfo() = 0;
        virtual std::vector<OrderAction> Run() = 0;
    };

    /// <summary>   Main Lex Interface. </summary>
    ///
    /// <remarks>   TC should call this. Chaohui, 10/11/2013. </remarks>

    class LexInterface
    {
    public:
        virtual ~LexInterface() {}

        virtual std::vector<LexStudy> ListStudies() = 0;
        virtual void Compiler(std::string study_name) = 0;
        virtual SignalDetail GetSignalDetail(std::string signal_name) = 0;
        virtual LexRunnerInterface* New(std::string signal_name, SignalDetail details,
            TCBarInterface *tc_bar) = 0;

        virtual std::unique_ptr<SignalRunnerInterface> NewSignal(std::string signal_name,
            SignalDetail details, TCBarInterface *tc_bar) = 0;
    };
}  // namespace lex
#endif  // LEX_INTERFACE_LEX_INTERFACE_H_
