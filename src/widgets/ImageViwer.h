//
// Created by guilherme on 18/11/24.
//

#ifndef IMAGEVIWER_H
#define IMAGEVIWER_H
#include "Widget.h"
#include "../components/GuigoImage.h"


class ImageViwer : public Widget {
GuigoImage *image;
    float width, height;

public:

void set_image(GuigoImage *image) {
    this->image = image;
}

void set_width(float width) {
    this->width = width;
}

void set_height(float height) {
    this->height = height;
}

template<typename ...Args>
    ImageViwer(int width, int height,GuigoImage* image ,Args... args) : Widget(args...) {
        this->width = width;
        this->height = height;
        this->image = image;
    };
    void render() override;
};



#endif //IMAGEVIWER_H
