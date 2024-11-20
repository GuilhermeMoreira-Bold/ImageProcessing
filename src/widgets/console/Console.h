//
// Created by guilherme on 20/11/24.
//

#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>

#include "../Widget.h"
#include "../../observers/LogObserver.h"


class Console : public Widget,public LogObserver {
    std::vector<std::string*> logMessage;

public:
    void update(std::string *message) override;

    Console() = default;
    void render() override;
};
#endif //CONSOLE_H