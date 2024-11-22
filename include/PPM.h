#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

void savePPM(const std::string &filename, const std::vector<std::vector<int>> &array) {
    std::ofstream ofs(filename, std::ios::out);
    if (!ofs) {
        std::cerr << "Could not open the file for writing!";
        return;
    }

    int height = array.size();
    int width = array[0].size();

    std::ostringstream oss;
    oss << "P3\n" << width << " " << height << "\n255\n";

    for (const auto &row : array) {
        for (const auto &pixel : row) {
            int r = (pixel >> 16) & 0xFF;
            int g = (pixel >> 8) & 0xFF;
            int b = pixel & 0xFF;
            oss << r << " " << g << " " << b << " ";
        }
        oss << "\n";
    }

    ofs << oss.str();
    ofs.close();
}