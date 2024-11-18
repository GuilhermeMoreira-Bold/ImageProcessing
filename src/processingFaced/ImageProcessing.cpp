//
// Created by guilherme on 18/11/24.
//

#include "ImageProcessing.h"

#include <SDL.h>
#include "../service/ImageLoader.h"
#include "../widgets/ImageViwer.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl2.h"

ImageProcessing::ImageProcessing(char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        SDL_Log("Erro ao inicializar SDL: %s", SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        printf("Erro ao criar a janela: %s\n", SDL_GetError());
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1);

    if (glewInit() != 0) {
        fprintf(stderr, "Falha ao inicializar OpenGL loader!\n");
    }


    ImageLoader loader;


    editor = new Editor(window, gl_context,new HelloWidget(), new TestWidget(), new ImageViwer(1200.0f,843.0f,loader.loadImage("/home/guilherme/CLionProjects/IMAGE_PROCESSING/res/img.jpg")));

    myRenderer = new Renderer(window, renderer, editor);
}

ImageProcessing::~ImageProcessing() {
}


void ImageProcessing::run() {
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            ImGui_ImplSDL2_ProcessEvent(&event);
        }


        myRenderer->render();
    }
}
