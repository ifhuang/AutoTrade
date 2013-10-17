#include "lex_impl.h"

#include "bison/front.h"
#include "data/data_repository.h"
#include "type.h"

namespace lex
{
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
        FILE *f = fopen(study_name.c_str(), "r");
        if (!f)
        {
            printf("file open failed.");
            return;
        }
        int g = elparse(f);
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
            printf("(%s): error: ", location_print(e.loc_).c_str());
            printf("%s\n", e.what());
            return;
        }
    }
}
