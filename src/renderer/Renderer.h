//
// Created by guilherme on 18/11/24.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <SDL_render.h>
#include <vector>
#include "../editor/Editor.h"


class Renderer {
    SDL_Window* window;
    SDL_Renderer* renderer;
    Editor* editor;
    std::vector<SDL_Texture*> textures;
    public:
    Renderer(SDL_Window* window, SDL_Renderer* renderer,Editor* editor);
    ~Renderer();
    void render();
    void addImage(SDL_Texture* texture);
    void shutdown();
};



#endif //RENDERER_H
