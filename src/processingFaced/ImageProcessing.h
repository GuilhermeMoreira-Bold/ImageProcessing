//
// Created by guilherme on 18/11/24.
//

#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H
#include "../renderer/Renderer.h"
#include <GL/glew.h>
#include "../widgets/HelloWidget.h"
#include "../widgets/TestWidget.h"

class ImageProcessing {
    Renderer* myRenderer;
    Editor* editor;
public:
    ImageProcessing(char* title, int width, int height);
    ~ImageProcessing();
   void run();
};



#endif //IMAGEPROCESSING_H
