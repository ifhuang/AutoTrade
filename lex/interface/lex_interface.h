#ifndef LEX_INTERFACE_LEX_INTERFACE_H_
#define LEX_INTERFACE_LEX_INTERFACE_H_

#include <string>
#include <vector>

#include "tc_bar_interface.h"

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

struct LexSignalDetail
{
    std::vector<LexInput> inputs;
};

class LexRunnerInterface
{
public:
    virtual ~LexRunnerInterface() {}
    virtual void Run() = 0;
};

/// <summary>   Main Lex Interface. </summary>
///
/// <remarks>   TC should call this. Chaohui, 10/11/2013. </remarks>

class LexInterface
{
public:
    virtual ~LexInterface() {}

    virtual std::vector<LexStudy> ListStudies() = 0;
    virtual LexSignalDetail GetSignalDetail(std::string signal_name) = 0;
    virtual LexRunnerInterface* New(std::string signal_name, LexSignalDetail details, TCBarInterface *tc_bar) = 0;
};

#endif  // LEX_INTERFACE_LEX_INTERFACE_H_
