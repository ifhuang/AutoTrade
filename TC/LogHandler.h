#ifndef __LOGHANDLER__
#define __LOGHANDLER__
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;

// by xie
class LogHandler {
public:
	static LogHandler& getLogHandler() {
		static LogHandler handler;
		return handler;
	}
	
	void alert(int level, string brief, string msg) {
		string currentTime = getCurrentTime();
		logFile << currentTime << "[Error]: " << msg << endl;
		cerr << msg << endl;
	}

	void log(string msg) {
		string currentTime = getCurrentTime();
		logFile << currentTime << ": " << msg << endl;
		cout << msg << endl;
	}

	~LogHandler() {
		if (logFile.is_open()) {
			logFile.close();
		}
	}
private:
    string getCurrentTime() const {
        return boost::posix_time::to_iso_extended_string(boost::posix_time::second_clock::local_time());
    }

    string getCurrentDate() const {
        return boost::gregorian::to_iso_extended_string(boost::gregorian::day_clock::local_day());
    }

	LogHandler() {
		if (access("Log",0)) {
			if (!mkdir("Log")) {
				cerr << "log folder fail to create" << endl;
				exit(1);
			}
		}
		string filename = "Log\\";
        filename.append(getCurrentDate());
		filename.append(".log");
		logFile.open(filename.c_str(), ios::out /*| ios::app*/);
		if (!logFile.is_open()) {
			cerr << "log file open failed" << endl;
			exit(1);
		}
	}
	ofstream logFile;
};

#endif