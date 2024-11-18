//
// Created by guilherme on 18/11/24.
//

#include "HelloWidget.h"

#include <imgui.h>
#include <iostream>
#include <ostream>

static std::vector<std::string> messages;

void HelloWidget::render() {
    ImGui::Begin("Oi athos",nullptr, ImGuiWindowFlags_AlwaysHorizontalScrollbar);
    ImGui::Text("Hello, world!");
    ImGui::BulletText("Hello, world!");
    ImGui::End();
}
