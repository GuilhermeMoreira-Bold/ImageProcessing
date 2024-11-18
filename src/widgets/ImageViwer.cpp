//
// Created by guilherme on 18/11/24.
//

#include "ImageViwer.h"

#include <cstdint>
#include <imgui.h>


void ImageViwer::render() {
    ImGui::Begin("Image Viewer");
    ImGui::Image(image->getTextute(), ImVec2(width,height));
    ImGui::End();
}
