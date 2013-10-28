#ifndef __DISPATCHER_FACTORY__
#define __DISPATCHER_FACTORY__
#include "TradeCube.h"

class Dispatcher;

class DispatcherFactory
{
public:
	static Dispatcher* createDispatcher(PlatformInfo& platformInfo);
	~DispatcherFactory(void);
private:
	DispatcherFactory(void);
};
#endif