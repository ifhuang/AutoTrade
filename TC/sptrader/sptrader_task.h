#ifndef TC_SPTRADER_SPTRADER_TASK_H__
#define TC_SPTRADER_SPTRADER_TASK_H_

#include <condition_variable>
#include <map>
#include <mutex>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "../global.h"

template<class T>
class SPTraderTask
{
public:
    SPTraderTask() {}

    void Wait(std::string key, boost::posix_time::ptime at_least, T item)
    {
        std::unique_lock<std::mutex> lock(mut_);
        while (last_update_.count(key) == 0 || last_update_.at(key) < at_least)
        {
            cond_.wait(lock);
        }
        item = storage_[key];
    }

    void Prepare(std::string key, T item)
    {
        {
            std::lock_guard<std::mutex> _(mut_);
            last_update_[key] = GetTime();
            storage_[key] = item;
        }
        cond_.notify_all();
    }

    boost::posix_time::ptime GetTime()
    {
        return clock_.local_time();
    }

private:
    std::map<std::string, boost::posix_time::ptime> last_update_;
    std::map<std::string, T> storage_;
    std::condition_variable cond_;
    std::mutex mut_;
    boost::posix_time::microsec_clock clock_;
    DISALLOW_COPY_AND_ASSIGN(SPTraderTask);
};

#endif  // TC_SPTRADER_SPTRADER_TASK_H_
