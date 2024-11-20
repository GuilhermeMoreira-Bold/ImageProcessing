//
// Created by guilherme on 18/11/24.
//

#ifndef IMAGEMODIFIER_H
#define IMAGEMODIFIER_H
#include "../Widget.h"
#include "../../components/GuigoImage.h"


class ImageModifier : public Widget {
    GuigoImage* image;
    public:
    template<typename ...Args>
    ImageModifier(GuigoImage* image,Args... args ): Widget(args...) {
        this->image = image;
    };
    void modify();
    void render() override;
};



#endif //IMAGEMODIFIER_H
