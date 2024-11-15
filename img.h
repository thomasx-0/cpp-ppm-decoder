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

int main() {
    std::vector<std::vector<int>> array = {
        {0xFF0000, 0x00FF00, 0x0000FF},
        {0xFFFF00, 0xFF00FF, 0x00FFFF},
        {0xFFFFFF, 0x000000, 0x888888}
    };

    savePPM("output.ppm", array);

    std::cout << "Image saved as output.ppm" << std::endl;

    return 0;
}