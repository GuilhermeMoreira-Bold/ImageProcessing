//
// Created by guilherme on 20/11/24.
//

#include "ImageViewerCreator.h"
#include "../../log/Log.h"
#include <imgui.h>
#include <thread>

void ImageViewerCreator::pop(bool canPop) {
    this->canPop = canPop;
}

void ImageViewerCreator::render() {
    static char viewerName[1024] = "";
    static std::string imagePath = "Image Path:";
    static bool isDialogOpen = false;
    if(canPop) {
        ImGui::OpenPopup("Create Image Viewer");
        if(ImGui::BeginPopupModal("Create Image Viewer",nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::InputText("Viewer name",viewerName, IM_ARRAYSIZE(viewerName));
            if(ImGui::Button("Search image") && !isDialogOpen) {
                isDialogOpen = true;
                std::thread([this]() {
                    imagePath.append(imagePathAdapter->getPath());
                    isDialogOpen = false;
                }).detach();
            }

            ImGui::Text("%s", imagePath.c_str());


            if(ImGui::Button("Create") && !isDialogOpen) {
                ImGui::CloseCurrentPopup();
                imagePath = "Image Path:";
                canPop = false;
            }

            if(ImGui::Button("Exit") && !isDialogOpen) {
                ImGui::CloseCurrentPopup();
                canPop = false;
            }
            ImGui::EndPopup();
        }
    }


}
