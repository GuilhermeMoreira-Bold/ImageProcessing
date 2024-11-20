//
// Created by guilherme on 20/11/24.
//

#include "MenuBar.h"

#include <imgui.h>

void MenuBar::render() {
    ImGui::BeginMainMenuBar();
       for(auto& child : this->childrens) {
           child->render();
       }
    ImGui::EndMainMenuBar();

}
