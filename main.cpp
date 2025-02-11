#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "include/PPM.h"
#include <fmt/core.h>

void savePPM(const std::string &filename, const std::vector<std::vector<int>> &array) {
    std::ofstream ofs(filename, std::ios::out);
    if (!ofs) {
        throw std::runtime_error("Could not open the file for writing!");
    }

    int height = array.size();
    int width = array[0].size();

    ofs << "P3\n" << width << " " << height << "\n255\n";

    for (const auto &row : array) {
        for (const auto &pixel : row) {
            int r = (pixel >> 16) & 0xFF;
            int g = (pixel >> 8) & 0xFF;
            int b = pixel & 0xFF;
            ofs << r << " " << g << " " << b << " ";
        }
        ofs << "\n";
    }
}

int main() {
    fmt::print("Hello World!\n");
    try {
        PPM ppmInstance;
        savePPM("output.ppm", ppmInstance.imageData);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}