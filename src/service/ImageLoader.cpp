//
// Created by guilherme on 18/11/24.
//

#include "ImageLoader.h"

#include <iostream>
#include <ostream>
#include <SDL_surface.h>
#include <GL/glew.h>
#include <SDL_image.h>

GuigoImage* ImageLoader::loadImage(char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        printf("Falha ao carregar a imagem: %s\n", IMG_GetError());
    }

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        surface->w,
        surface->h,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        surface->pixels
    );

    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(surface);
    return new GuigoImage(texture);
}
