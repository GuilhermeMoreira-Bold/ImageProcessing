//
// Created by guilherme on 20/11/24.
//

#include "Console.h"

#include <imgui.h>

void Console::update(std::string *message) {
    logMessage.emplace_back(message);
}

void Console::render() {
    ImGui::Begin("Console");
    for(auto& texts : logMessage) {
        ImGui::Text("%s", texts->c_str());
    }
    ImGui::End();
}
