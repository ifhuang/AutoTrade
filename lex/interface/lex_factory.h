#ifndef LEX_INTERFACE_LEX_FACTORY_H_
#define LEX_INTERFACE_LEX_FACTORY_H_

#include "lex_interface.h"

class LexFactory
{
public:
    static LexInterface* CreateLexInterface();
};

#endif  // LEX_INTERFACE_LEX_FACTORY_H_
