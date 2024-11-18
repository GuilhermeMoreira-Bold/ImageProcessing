//
// Created by guilherme on 18/11/24.
//

#ifndef EDITOR_H
#define EDITOR_H

#include <SDL_video.h>
#include "../widgets/Widget.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl2.h"


class Editor : public Widget {
public:
    template<typename... Args>
    Editor(SDL_Window* window, SDL_GLContext gl_context,Args...  args) : Widget(args...) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
        ImGui_ImplOpenGL3_Init("#version 330");

    };

    void render();
    void shutdown();
};



#endif //EDITOR_H
