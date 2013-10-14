#ifndef __ORDERITEM__
#define __ORDERITEM__

#include <string> 

class OrderItem
{
private:
    int tradePlatform;
    std::string quoteId;
    int action;
    double submitPrice;
    double qty;
    double tradedQty;
    char buysell;
    int orderType;
    int validType;
    int status;
    int orderNo;
    long orderRefId;
    std::string openclose;
    double originalPrice;
    double originalQty;
    int returnCode;
    std::string returnMessage;
    long comboRefId;
    int parentRefId;
    long counter;
    int submitter;
    int traderId;
    std::string account;
    time_t validTime;


public:

    OrderItem() {}

    OrderItem(int tradePlatform, std::string quoteId, double submitPrice, double qty,
        char buysell, int orderType, int validType, std::string openclose);

    void setAccount(std::string account)
    {
        this->account = account;
    }

    std::string getAccount()
    {
        return this->account;
    }

    void setTraderId(int traderId)
    {
        this->traderId = traderId;
    }

    int getTraderId()
    {
        return this->traderId;
    }

    void addCounter()
    {
        this->counter++;
    }

    long getCounter()
    {
        return this->counter;
    }

    void addTradedQty(double qty)
    {
        this->tradedQty += qty;
    }

    double getTradedQty()
    {
        return this->tradedQty;
    }

    void setSubmitter(int submitter)
    {
        this->submitter = submitter;
    }

    int getSubmitter()
    {
        return this->submitter;
    }

    int getParentRefId()
    {
        return this->parentRefId;
    }

    void setParentRefId(int parentRefId)
    {
        this->parentRefId = parentRefId;
    }

    void setComboRefId(long refId)
    {
        this->comboRefId = refId;
    }

    long getComboRefId()
    {
        return this->comboRefId;
    }

    void setReturnCode(int returnCode)
    {
        this->returnCode = returnCode;
    }

    int getReturnCode()
    {
        return this->returnCode;
    }

    void setReturnMessage(std::string message)
    {
        this->returnMessage = message;
    }

    std::string getReturnMessage()
    {
        return this->returnMessage;
    }

    void setOriginalPrice(double originalPrice)
    {
        this->originalPrice = originalPrice;
    }

    double getOriginalPrice()
    {
        return this->originalPrice;
    }

    void setOriginalQty(double originalQty)
    {
        this->originalQty = originalQty;
    }

    double getOriginalQty()
    {
        return this->originalQty;
    }

    void setTradePlatform(int tradePlatform)
    {
        this->tradePlatform = tradePlatform;
    }

    int getTradePlatform()
    {
        return this->tradePlatform;
    }

    void setQuoteId(std::string quoteId)
    {
        this->quoteId = quoteId;
    }

    void setAction(int action)
    {
        this->action = action;
    }

    void setSubmitPrice(double submitPrice)
    {
        this->submitPrice = submitPrice;
    }

    void setQty(double qty){
        this->qty = qty;
    }

    void setBuySell(char buysell)
    {
        this->buysell = buysell;
    }

    void setOrderType(int orderType)
    {
        this->orderType = orderType;
    }

    void setValidType(int validType)
    {
        this->validType = validType;
    }
    void setStatus(int status)
    {
        this->status = status;
    }
    void setOrderNo(int orderNo)
    {
        this->orderNo = orderNo;
    }

    void setOrderRefId(long orderRefId)
    {
        this->orderRefId = orderRefId;
    }

    void setOpenClose(std::string openclose)
    {
        this->openclose = openclose;
    }

    std::string getQuoteId()
    {
        return this->quoteId;
    }

    int getAction()
    {
        return this->action;
    }

    double getSubmitPrice()
    {
        return this->submitPrice;
    }

    double getQty(){
        return this->qty;
    }

    char getBuySell()
    {
        return this->buysell;
    }

    int getOrderType()
    {
        return this->orderType;
    }

    int getValidType()
    {
        return this->validType;
    }

    int getStatus()
    {
        return this->status;
    }

    int getOrderNo()
    {
        return this->orderNo;
    }

    long getOrderRefId()
    {
        return this->orderRefId;
    }

    std::string getOpenClose()
    {
        return this->openclose;
    }

    time_t getValidTime() const {
        return this->validTime;
    }

    void setValidTime(time_t t) {
        this->validTime = t;
    }

    void log() const;
};
#endif
