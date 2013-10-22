#ifndef __DISPATCHER_FACTORY__
#define __DISPATCHER_FACTORY__
#include "TradeCube.h"
#include "SPTrader.h"
#include "Dispatcher.h"

class DispatcherFactory
{
public:
	static Dispatcher* createDispatcher(PlatformInfo& platformInfo);
	~DispatcherFactory(void);
private:
	DispatcherFactory(void);
};
#endif