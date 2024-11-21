//
// Created by guilherme on 20/11/24.
//

#ifndef IMAGEVIEWERCREATOR_H
#define IMAGEVIEWERCREATOR_H
#include <atomic>

#include "../Widget.h"
#include "../../adpaters/ImagePathAdapter.h"


class ImageViewerCreator : public Widget {
    bool canPop = false;
    ImagePathAdapter* imagePathAdapter = nullptr;
    public:
    template<typename ...Args>
    ImageViewerCreator(ImagePathAdapter* image_path_adapter,Args... args) : Widget(args...), imagePathAdapter(image_path_adapter) {}

    void pop(bool canPop);

    void render() override;
};



#endif //IMAGEVIEWERCREATOR_H
