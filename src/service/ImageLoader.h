//
// Created by guilherme on 18/11/24.
//

#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include <string>
#include "../components/GuigoImage.h"
#include "../log/Log.h"

class ImageLoader {
    public:
    ImageLoader() = default;
    ~ImageLoader() = default;
    GuigoImage* loadImage(char* path);
};



#endif //IMAGELOADER_H
