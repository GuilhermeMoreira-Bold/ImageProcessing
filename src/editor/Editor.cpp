//
// Created by guilherme on 18/11/24.
//

#include "Editor.h"


#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl2.h"



void Editor::render() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport();
    for(auto& comp : childrens) {
        comp->render();
    }

    ImGui::Render();

}


void Editor::shutdown() {
}
