#include "lex_impl.h"

#include "data/data_repository.h"

std::vector<LexStudy> LexImpl::ListStudies()
{
    return DataRepository::ListStudies();
}

LexRunnerInterface* LexImpl::New(std::string signal_name, LexSignalDetail details, TCBarInterface *tc_bar)
{
    throw std::exception("The method or operation is not implemented.");
}

LexSignalDetail LexImpl::GetSignalDetail(std::string signal_name)
{
    throw std::exception("The method or operation is not implemented.");
}

void LexImpl::Compiler(std::string study_name)
{
    throw std::exception("The method or operation is not implemented.");
}
