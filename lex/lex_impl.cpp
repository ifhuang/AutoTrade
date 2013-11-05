#include "lex_impl.h"

#include "bison/front.h"
#include "data/data_repository.h"
#include "lex_runner.h"
#include "type.h"

namespace lex
{
    std::vector<LexStudy> LexImpl::ListStudies()
    {
        return DataRepository::ListStudies();
    }

    LexRunnerInterface* LexImpl::New(std::string signal_name,
        SignalDetail details, TCBarInterface *tc_bar)
    {
        throw std::exception("The method or operation is not implemented.");
    }

    SignalDetail LexImpl::GetSignalDetail(std::string signal_name)
    {
        SignalDetail sd;
        return sd;
    }

    void LexImpl::Compiler(std::string study_name)
    {
        FILE *f = fopen(study_name.c_str(), "r");
        if (!f)
        {
            printf("file open failed.");
            return;
        }
        int g = ElParse(f);
        fclose(f);
        if (g)
        {
            printf("%s\n", errorMessage.c_str());
            return;
        }

        try
        {
            type_check();
        }
        catch (SemanticError e)
        {
            printf("(%s): error: ", LocationPrint(e.loc_).c_str());
            printf("%s\n", e.what());
            return;
        }
    }

    std::unique_ptr<SignalRunnerInterface> LexImpl::NewSignal(std::string signal_name,
        SignalDetail details, TCBarInterface *tc_bar)
    {
        Program p = DataRepository::LoadProgram();
        LexRunner *runner = new LexRunner(p, tc_bar);
        return std::unique_ptr<SignalRunnerInterface>(runner);
    }

}  // namespace lex
