#ifndef LEX_TYPE_CHECKER_H_
#define LEX_TYPE_CHECKER_H_

#include "check_visitor.h"
#include "global.h"
#include "table.h"
#include "program.h"
#include "type_checker_interface.h"

namespace lex
{
    class TypeChecker : public TypeCheckerInterface
    {
    public:
        TypeChecker();
        void Check();
        virtual VType GetType(ast_t idx) override;
        virtual std::string GetVar(ast_t idx) override;
        virtual void Check(stmt_t stmt) override;
        virtual void CheckStmts(stmts_t idx) override;
        virtual int Reserve(ast_t exp) override;
        virtual int ReserverTrue() override;
        virtual Table& GetTable();
        Program GetProgram() const;

    private:
        VType CheckFunc(ast_t idx);
        void CheckInput();
        void CheckParas(const StdFunction *function, asts_t idx,
            const YYLTYPE *loc);

        CheckVisitor visitor_;
        Table table_;
        const int kAstTrue_;
        bool is_input_;
        DISALLOW_COPY_AND_ASSIGN(TypeChecker);
    };
}
#endif  // LEX_TYPE_CHECKER_H_
