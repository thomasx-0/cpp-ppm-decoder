#include <iostream>
#include "./include/img.h"

int main() {
    std::cout << "Hello CMake" << std::endl;
    std::vector<std::vector<int>> imageData = {
        {0xFF0000, 0x00FF00, 0x0000FF},
        {0xFFFF00, 0xFF00FF, 0x00FFFF},
        {0xFFFFFF, 0x000000, 0x888888}
    };
    // FIXME: reformat the function parameters
    savePPM("output.ppm", imageData);
    return 0;
}
