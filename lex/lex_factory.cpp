#include "interface/lex_factory.h"

#include "lex_impl.h"

namespace
{
    lex::LexImpl lex_impl;
}  // namespace

namespace lex
{
    LexInterface* LexFactory::CreateLexInterface()
    {
        return &lex_impl;
    }
}  // namespace lex
