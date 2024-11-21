//
// Created by guilherme on 20/11/24.
//

#ifndef IMAGEVIEWERCREATOR_H
#define IMAGEVIEWERCREATOR_H
#include "../Widget.h"


class ImageViewerCreator : public Widget {
   bool canPop = false;
    public:
    ImageViewerCreator() = default;

    void pop(bool canPop);

    void render() override;
};



#endif //IMAGEVIEWERCREATOR_H
