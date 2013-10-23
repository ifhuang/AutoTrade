#ifndef __PLATFORMINFO__
#define __PLATFORMINFO__

#include <string>

struct PlatformInfo
{
	int platformName;
	int orderPort, pricePort, tickPort;
	std::string server, accountNo, password;
};
#endif
