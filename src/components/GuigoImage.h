//
// Created by guilherme on 18/11/24.
//

#ifndef GUIGOIMAGE_H
#define GUIGOIMAGE_H



class GuigoImage {
    unsigned int Textute;
    int width, height;

public:
    int get_width() {
        return width;
    }

    int get_height() {
        return height;
    }

    GuigoImage(unsigned int textute, int width, int height)
        : Textute(textute),
          width(width),
          height(height) {
    }

    unsigned int getTextute() {
        return this->Textute;
    }
};
#endif //GUIGOIMAGE_H
