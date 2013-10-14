#ifndef __LOGHANDLER__
#define __LOGHANDLER__

#include <fstream>
#include <string>

// by xie
class LogHandler {
public:
	static LogHandler& getLogHandler();

    void alert(int level, std::string brief, std::string msg);
    void log(std::string msg);
	
private:
	LogHandler();
    ~LogHandler();

    std::string getCurrentTime() const;
    std::string getCurrentDate() const;

	std::ofstream logFile;
};

#endif