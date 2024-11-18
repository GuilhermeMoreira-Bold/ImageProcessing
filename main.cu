#include <iostream>
#include <SDL2/SDL.h>
#include "imgui.h"
#include "src/processingFaced/ImageProcessing.h"

int main() {
    ImageProcessing process("Guigo", 1600, 900);
    process.run();
    return 0;
}
