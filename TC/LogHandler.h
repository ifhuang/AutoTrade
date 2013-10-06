#ifndef __LOGHANDLER__
#define __LOGHANDLER__
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <time.h> 
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
		char currentTime[256] = {0};
		time_t t = time(0); 
		strftime( currentTime, sizeof(currentTime), "%Y-%m-%d %H:%M:%S",localtime(&t)); 
		return currentTime;
	}

	LogHandler() {
		if (access("Log",0)) {
			if (!mkdir("Log")) {
				cerr << "log folder fail to create" << endl;
				exit(1);
			}
		}
		char day[256] = {0};
		time_t t = time(0); 
		strftime(day, sizeof(day), "%Y-%m-%d",localtime(&t)); 
		string filename = "Log\\";
		filename.append(day);
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