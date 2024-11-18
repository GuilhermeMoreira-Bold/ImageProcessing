//
// Created by guilherme on 18/11/24.
//

#include "TestWidget.h"

#include <imgui.h>

void TestWidget::render() {
    ImGui::Begin("Hello",nullptr, ImGuiWindowFlags_AlwaysHorizontalScrollbar);
    ImGui::Text("Hello, world!");
    ImGui::BulletText("Hello, world!");
    if(ImGui::Button("Oi Athos")) {
        ImGui::Text("%s", "Oi Ahtumus");
    }
    ImGui::End();
}
