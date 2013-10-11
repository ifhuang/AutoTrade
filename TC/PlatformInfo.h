#ifndef __PLATFORMINFO__
#define __PLATFORMINFO__

#include <string>
using namespace std;

struct PlatformInfo
{
	int platformName;
	int orderPort, pricePort, tickPort;
	string server, accountNo, password;
};
#endif
