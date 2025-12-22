#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <iterator>
#include <algorithm>

uint8_t rotateRight(const uint8_t &value, unsigned int shift)
{
    shift = shift % 8;
    if (shift == 0) {
        return value;
    }
    return (value >> shift) | (value << (8 - shift));
}

void removeFromIndex(std::vector<uint8_t> &list, uint8_t value, size_t startIndex)
{
    if (startIndex >= list.size()) {
        return;
    }
    auto it = std::find(list.begin() + startIndex, list.end(), value);
    if (it != list.end()) {
        list.erase(it);
    }
}

uint8_t complementValue(const uint8_t &value)
{
    return ~value;
}

int main()
{
    std::vector<uint8_t> all;

    for (int i = 255; i >= 0; --i) {
        all.push_back(static_cast<uint8_t>(i));
    }

    for (size_t i = 0; i < all.size(); ) {
        for (size_t j = 1; j < 8; ++j) {
            uint8_t rotated = rotateRight(all[i], j);
            removeFromIndex(all, rotated, i + 1);
        }
        ++i;
    }

    std::cout << "Generative Numbers : " << all.size() << std::endl;

    for (auto value : all) {
        std::cout << (int)value << std::endl;
    }


    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "Generative Complement Numbers : " << all.size() << std::endl;

    for (auto value : all) {
        std::cout << (int)complementValue(value) << std::endl;
    }

    return 0;
}
