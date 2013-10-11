#ifndef __BAR_H__
#define __BAR_H__

class Bar
{
public:
    Bar(double open, double high, double low, double close, int period)
        :open(open), high(high), low(low), close(close), period(period) {}

    void setPeriod(int period)
    {
        this->period = period;
    }

    int getPeriod()
    {
        return this->period;
    }
    void setOpen(double open)
    {
        this->open = open;
    }
    void setHigh(double high)
    {
        this->high = high;
    }
    void setLow(double low)
    {
        this->low = low;
    }
    void setClose(double close)
    {
        this->close = close;
    }
    double getOpen()
    {
        return open;
    }
    double getHigh()
    {
        return high;
    }
    double getLow()
    {
        return low;
    }
    double getClose()
    {
        return close;
    }
    void log() const;
private:
    double open, high, low, close;
    int period; // unit=second
};
#endif