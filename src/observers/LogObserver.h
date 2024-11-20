//
// Created by guilherme on 20/11/24.
//

#ifndef LOGOBSERVER_H
#define LOGOBSERVER_H
#include <string>

class LogObserver {
    public:
    virtual void update(std::string* message) = 0;
};
#endif //LOGOBSERVER_H
