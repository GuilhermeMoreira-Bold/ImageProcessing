//
// Created by guilherme on 20/11/24.
//

#include "ImageViewerCreator.h"
#include "../../log/Log.h"
#include <imgui.h>

void ImageViewerCreator::pop(bool canPop) {
    this->canPop = canPop;
}

void ImageViewerCreator::render() {
    static char viewerName[1024] = "";
    static char imagePath[1024] = "";

    if(canPop) {
        ImGui::OpenPopup("Create Image Viewer");
        if(ImGui::BeginPopupModal("Create Image Viewer", &canPop, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::InputText("Viewer name",viewerName, IM_ARRAYSIZE(viewerName));
            ImGui::Button("Search image");

            if(ImGui::Button("Create")) {
                ImGui::CloseCurrentPopup();
                canPop = false;
            }
            ImGui::EndPopup();
        }
    }


}
