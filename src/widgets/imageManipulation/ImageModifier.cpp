//
// Created by guilherme on 18/11/24.
//

#include "ImageModifier.h"

#include <imgui.h>
#include <ostream>
#include <c++/11/iostream>
#include <GL/glew.h>

void ImageModifier::render() {
    for(auto& child : this->childrens) {
        child->render();
    }
    ImGui::Begin("Modify Image");
    if (ImGui::Button("Apply")) {
        modify();
    }

    ImGui::End();
}

void ImageModifier::modify() {
    unsigned char* originalData = new unsigned char[image->get_width() * image->get_height() * 3];
    glBindTexture(GL_TEXTURE_2D, image->getTextute());
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, originalData);
    unsigned char* newRGBData = new unsigned char[image->get_width() * image->get_height() * 3];


    for (int y = 0; y < image->get_height(); ++y) {
        for (int x = 0; x < image->get_width(); ++x) {
            int index = (y * image->get_width() + x) * 3;
            unsigned char r = originalData[index];
            unsigned char g = originalData[index + 1];
            unsigned char b = originalData[index + 2];

            unsigned char gray = static_cast<unsigned char>(0.2126f * r + 0.7152f * g + 0.0722f * b);

            newRGBData[index] = gray;
            newRGBData[index + 1] = gray;
            newRGBData[index + 2] = gray;
        }
    }

    glBindTexture(GL_TEXTURE_2D, image->getTextute());
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, image->get_width(), image->get_height(), GL_RGB, GL_UNSIGNED_BYTE, newRGBData);

    delete[] originalData;
    delete[] newRGBData;

}