#include "interface/lex_factory.h"

#include "lex_impl.h"

LexInterface* LexFactory::CreateLexInterface()
{
    return new LexImpl();
}
