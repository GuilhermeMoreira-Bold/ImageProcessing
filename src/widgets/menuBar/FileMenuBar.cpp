//
// Created by guilherme on 20/11/24.
//

#include "FileMenuBar.h"

#include <imgui.h>


void FileMenuBar::render() {
    if(ImGui::BeginMenu("File")) {
        if(ImGui::MenuItem("Create new image Viewer")) {
            viewerCreator->pop(true);
        }
        if(ImGui::MenuItem("Exit")) {

        }
        ImGui::EndMenu();
    }
}
