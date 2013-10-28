#include "DispatcherFactory.h"

#include "SPTrader.h"

DispatcherFactory::DispatcherFactory(void)
{
}


DispatcherFactory::~DispatcherFactory(void)
{
}

Dispatcher* DispatcherFactory::createDispatcher(PlatformInfo& platformInfo)
{
	if (platformInfo.platformName == SPTRADER) {
		SPTrader *sptrader = SPTrader::GetSPTrader(platformInfo);
		return sptrader;
	}
	return nullptr;
}
