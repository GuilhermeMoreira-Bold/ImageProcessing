cmake_minimum_required(VERSION 3.20)
project(IMAGE_PROCESSING LANGUAGES CXX CUDA)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}  ${GLEW_INCLUDE_DIRS})

add_subdirectory(vendor/imgui)

set(CMAKE_CUDA_STANDARD 20)

add_executable(IMAGE_PROCESSING main.cu
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
        src/processingFaced/ImageProcessing.cpp
        src/processingFaced/ImageProcessing.h
        src/editor/Editor.cpp
        src/editor/Editor.h
        src/widgets/Widget.cpp
        src/widgets/Widget.h
        src/widgets/HelloWidget.cpp
        src/widgets/HelloWidget.h
        src/widgets/TestWidget.cpp
        src/widgets/TestWidget.h
        src/widgets/ImageViwer.cpp
        src/widgets/ImageViwer.h
        src/components/GuigoImage.cpp
        src/components/GuigoImage.h
        src/service/ImageLoader.cpp
        src/service/ImageLoader.h
        src/widgets/ImageModifier.cpp
        src/widgets/ImageModifier.h
        src/widgets/LogWidget.cpp
        src/widgets/LogWidget.h
        src/log/Log.cpp
        src/log/Log.h
        src/widgets/Console.cpp
        src/widgets/Console.h
        src/observers/LogObserver.h
)

target_link_libraries(IMAGE_PROCESSING PRIVATE
        ${SDL2_LIBRARIES}
        SDL2_image
        imgui
        OpenGL
        GLEW::GLEW
)

set_target_properties(IMAGE_PROCESSING PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
