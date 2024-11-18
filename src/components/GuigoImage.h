//
// Created by guilherme on 18/11/24.
//

#ifndef GUIGOIMAGE_H
#define GUIGOIMAGE_H



class GuigoImage {
    unsigned int Textute;
public:
    GuigoImage(unsigned int Texture) {
        this-> Textute = Texture;
    }
    unsigned int getTextute() {
        return this->Textute;
    }
};
#endif //GUIGOIMAGE_H
