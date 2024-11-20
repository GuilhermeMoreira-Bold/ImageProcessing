//
// Created by guilherme on 19/11/24.
//

#ifndef LOG_H
#define LOG_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <c++/11/vector>
#include "../observers/LogObserver.h"

enum LogLevel {DEBUG, INFO, WARNING,ERROR,CRITICAL};

class Log {

public:
    static Log* getInstance();
    void log(LogLevel level, const std::string& message);
    void addObserver(LogObserver* observer);

    ~Log() {logFile.close();}

private:
    void notifyAll(std::string* log);
    std::vector<LogObserver*> observers;
    static Log* instance;
    Log() = default;
    std::string path = std::filesystem::current_path() / "../logs/log.log";
    std::ofstream logFile;
    std::string levelToString(LogLevel level);
};



#endif //LOG_H
