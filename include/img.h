#include <iostream>
#include <fstream>
#include <vector>

void savePPM(const std::string &filename, const std::vector<std::vector<int>> &array) {
    std::ofstream ofs(filename, std::ios::out | std::ios::binary);
    if (!ofs) {
        std::cerr << "Could not open the file for writing!" << std::endl;
        return;
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

    ofs.close();
}