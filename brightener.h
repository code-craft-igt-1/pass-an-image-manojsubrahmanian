#pragma once
#include <cstdint>
#include <memory>
#include <algorithm>
#include <random>

struct Image {
    int rows;
    int columns;
    std::unique_ptr<uint8_t[]> pixels;

    // Constructor to initialize rows, columns, and set all pixel values to random values between 0 and 255
    Image(int r, int c) : rows(r), columns(c), pixels(std::make_unique<uint8_t[]>(r * c)) {
        std::random_device rd;  // Seed for the random number engine
        std::mt19937 gen(rd()); // Mersenne Twister random number engine
        std::uniform_int_distribution<> dis(0, 255); // Uniform distribution between 0 and 255

        for (int i = 0; i < r * c; ++i) {
            pixels[i] = dis(gen); // Assign random value to each pixel
        }
    }
};

class ImageBrightener {
private:
    Image& m_inputImage;
public:
    ImageBrightener(Image& inputImage);
    int BrightenWholeImage();
    Image& GetImage();
};
