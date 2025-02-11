#ifndef PPM_H
#define PPM_H

#include <vector>

class PPM {
public:
    std::vector<std::vector<int>> imageData;

    PPM() : imageData({
        {0xFF0000, 0x00FF00, 0x0000FF},
        {0xFFFFFF, 0x000000, 0x888888},
        {0x000000, 0xFFFFFF, 0x000000}
    }) {}
};

#endif // PPM_H
