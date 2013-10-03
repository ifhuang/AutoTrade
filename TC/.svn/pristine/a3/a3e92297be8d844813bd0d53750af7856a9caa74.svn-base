#include "DispatcherFactory.h"


DispatcherFactory::DispatcherFactory(void)
{
}


DispatcherFactory::~DispatcherFactory(void)
{
}

Dispatcher* DispatcherFactory::createDispatcher(PlatformInfo& platformInfo)
{
	if (platformInfo.platformName == SPTRADER) {
		static SPTrader sptrader(platformInfo);
		return &sptrader;
	}
	return NULL;
}