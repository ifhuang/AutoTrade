#include "LogHandler.h"

#include <iostream>
#include <io.h>
#include <direct.h>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

LogHandler::LogHandler()
{
    if (_access("Log", 0)) {
        if (!_mkdir("Log")) {
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

LogHandler::~LogHandler()
{
    if (logFile.is_open()) {
        logFile.close();
    }
}

LogHandler& LogHandler::getLogHandler()
{
    static LogHandler handler;
    return handler;
}

std::string LogHandler::getCurrentDate() const
{
    date day = day_clock::local_day();
    return to_iso_extended_string(day);
}

std::string LogHandler::getCurrentTime() const
{
    ptime time = second_clock::local_time();
    return to_iso_extended_string(time);
}

void LogHandler::log(string msg)
{
    string currentTime = getCurrentTime();
    logFile << currentTime << ": " << msg << endl;
    cout << msg << endl;
}

void LogHandler::alert(int level, string brief, string msg)
{
    string currentTime = getCurrentTime();
    logFile << currentTime << "[Error]: " << msg << endl;
    cerr << msg << endl;
}
