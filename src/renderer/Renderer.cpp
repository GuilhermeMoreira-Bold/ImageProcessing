//
// Created by guilherme on 18/11/24.
//

#include "Renderer.h"

#include <SDL.h>
#include <backends/imgui_impl_opengl3_loader.h>
#include "backends/imgui_impl_opengl3.h"

Renderer::Renderer(SDL_Window *window, SDL_Renderer *renderer,Editor *editor) {
    this->window = window;
    this->editor = editor;
    this->renderer = renderer;
}

Renderer::~Renderer() {
}

void Renderer::render() {
    editor->render();
    glViewport(0, 0, 1280, 720);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    if(ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        ImGui::UpdatePlatformWindows();
    }
    SDL_GL_SwapWindow(window);

}

void Renderer::addImage(SDL_Texture *texture) {
    textures.push_back(texture);
}

void Renderer::shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    editor->shutdown();
}
