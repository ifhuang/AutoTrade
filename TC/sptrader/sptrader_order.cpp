#include "sptrader_order.h"

#include <boost/date_time/posix_time/posix_time.hpp>

using std::string;

class OrderMessageProcessor : public SplitedMessageProcessor
{
public:
    OrderMessageProcessor(
        SPTrader &sptrader,
        SPTraderOrder &order)
        : sptrader_(sptrader), order_(order) {}

    virtual void Processor(Message &msg)
    {
        switch (msg.id)
        {
        case 3103:
            Process3103(msg.fileds);
            break;
        case 3109:
            Process3109(msg.fileds);
            break;
        case 3119:
            Process3119(msg.fileds);
            break;
        case 3183:
            Process3183(msg.fileds);
            break;
        case 3186:
            Process3186(msg.fileds);
            break;
        case 9000:
            Process9900(msg.fileds);
            break;
        case 9901:
            Process9901(msg.fileds);
            break;
        }
    }

private:
    void Process3103(Spliter &fileds)
    {
        OrderItem* po = StringProcessor::StrintToOrderItem(fileds);

        // 接收订单ORDER_ACCEPT_MSG
        sptrader_.returnOrder(po);
    }

    void Process3109(Spliter &fileds)
    {
        TradeItem* ti = StringProcessor::StringToTradeItem(fileds);
        sptrader_.confirmTradeInfo(ti->getTradeNo());
        //ti->log();
        // 订单完成TRADE_DONE_MSG
        sptrader_.returnTrade(ti);

        // added by xie, 内存问题， 在哪里释放以后要调好
        //doneTrades[ti->getOrderNo()] = ti;
        //if (doneTrades.size() == doneTradeCount) {
        //    SetEvent(doneTradeEvent);
       // }
    }

    void Process3119(Spliter &fileds)
    {
        //OrderItem* oi = sptrader_.str2UpdatedOrder(fileds);

        //currentOrders[oi->getOrderNo()] = oi;
        //if (currentOrders.size() == currentOrderCount) {
        //    SetEvent(curOrderEvent);
        //}
    }

    void Process3183(Spliter &fileds)
    {
        //doneTrades.clear();
        //doneTradeCount = 0;
        //int s = orderStr.find(",", 7);
        //int e = orderStr.length();
        //if (s != string::npos) {
        //    doneTradeCount = atoi(orderStr.substr(s + 1, e - s - 1).c_str());
        //    if (doneTradeCount == 0) {
        //        SetEvent(doneTradeEvent);
        //    }
        //}
    }

    void Process3186(Spliter &fileds)
    {
        /*currentOrders.clear();
        currentOrderCount = 0;
        int s = orderStr.find(",", 7);
        int e = orderStr.length();
        if (s != string::npos) {
            currentOrderCount = atoi(orderStr.substr(s + 1, e - s - 1).c_str());
            cout << "order count:" << currentOrderCount << endl;
            if (currentOrderCount == 0) {
                SetEvent(curOrderEvent);
            }
        }*/
    }

    void Process9900(Spliter &fileds)
    {
        if (fileds.Get<int>(1) == 0)
        {
            //LogHandler::getLogHandler().log(it->second + " is connected!");
        }
        else
        {
            sptrader_.setConnectStatus(false);
            string link = fileds.Get<string>(0);
            LogHandler::getLogHandler().alert(3, "Connection status", link + " is broken!");
            // 失去连接 
            //LogHandler::getLogHandler().alert(3, "Lost Connection!", "Lost Connection!");
            sptrader_.loseConnection();
        }
    }

    void Process9901(Spliter &fileds)
    {
        Position* pos = StringProcessor::StringToPosition(fileds);
        if (pos == nullptr)return;
        string quoteID = pos->getQuoteId();
        order_.postion_task_.Prepare(quoteID, *pos);
        delete pos;
    }

    SPTrader &sptrader_;
    SPTraderOrder &order_;
    std::set<std::string> product_set_;
};

SPTraderOrder::SPTraderOrder(boost::asio::io_service& io_service,
    tcp::resolver::iterator endpoint_iterator, SPTrader &sptrader)
    : io_service_(io_service),
    mp_(new OrderMessageProcessor(sptrader, *this)),
    sc_(io_service, *mp_)
{
    sc_.connect(endpoint_iterator);
}

SPTraderOrder::~SPTraderOrder()
{
    sc_.close();
    io_service_.post(
        [this]()
    {
        delete mp_;
    });
}

void SPTraderOrder::RequestLinkState(int link_id)
{
    string msg = "9000," + to_string(link_id) + "\r\n";
    io_service_.post(
        [this, msg]()
    {
        sc_.write(msg);
    });
}

int SPTraderOrder::Login(string user_id, string password, string server)
{
    string login_info = "3101,0," + user_id + "," + password + "," + server + "\r\n";
    sc_.sync_write(login_info);
    string msg = sc_.sync_read();
    Message message(msg);
    if (message.id == 3101){
        int return_code = message.fileds.Get<int>(0);
        return return_code;
    }
    return -1;
}

void SPTraderOrder::Do()
{
    sc_.do_read();
}

void SPTraderOrder::Send(std::string msg)
{
    sc_.write(msg);
}

Position SPTraderOrder::GetPosition(std::string quote_id, std::string acc_no)
{
    string msg = "9901,0," + acc_no + "," + acc_no + "\r\n";
    boost::posix_time::ptime current = postion_task_.GetTime();
    sc_.write(msg);
    Position item;
    postion_task_.Wait(quote_id, current, item);
    return item;
}
