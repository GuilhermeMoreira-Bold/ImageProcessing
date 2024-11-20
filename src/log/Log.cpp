//
// Created by guilherme on 19/11/24.
//

#include "Log.h"

void Log::log(LogLevel level, const std::string &message) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", timeinfo);
    std::ostringstream logEntry;
    logEntry << "[" <<   timestamp  << "] " << levelToString(level) << " " << message << "\n";
    std::cout << logEntry.str() << std::endl;

    logFile.open(path, std::ios::app);
    if(logFile.is_open()) {
        logFile << logEntry.str();
        logFile.flush();
        logFile.close();
        notifyAll(new std::string(logEntry.str()));

    }else {
        std::cerr << "Unable to open log file at:" << path << std::endl;
    }
}

void Log::addObserver(LogObserver *observer) {
    observers.emplace_back(observer);
}

void Log::notifyAll(std::string* log) {
    for(auto& observer : observers) {
        observer->update(log);
    }
}

std::string Log::levelToString(LogLevel level) {
    switch (level) {
        case INFO:
            return "INFO";
        case DEBUG:
            return "DEBUG";
        case ERROR:
            return "ERROR";
        case WARNING:
            return "WARNING";
        case CRITICAL:
            return "CRITICAL";
        default:
            return "NOVALIDLOGTYPE";
    }
}

Log* Log::instance = nullptr;
Log* Log::getInstance() {
    if(instance == nullptr) {
        instance = new Log();
    }
    return instance;
}
