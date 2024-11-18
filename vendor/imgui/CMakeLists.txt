cmake_minimum_required(VERSION 3.15)
project(imgui)

set(IMGUI_SOURCES
        imgui.cpp
        imgui_draw.cpp
        imgui_widgets.cpp
        imgui_tables.cpp
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp
        backends/imgui_impl_opengl3.h
        backends/imgui_impl_sdl2.h
        backends/imgui_impl_sdlrenderer2.h
        backends/imgui_impl_sdl2.cpp
        backends/imgui_impl_sdlrenderer2.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
