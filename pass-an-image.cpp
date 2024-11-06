#include <iostream>
#include "brightener.h"

int main() {
    Image image(512, 512); // Assuming the constructor takes width, height, and max color value
	std::cout << "Brightening a 512 x 512 image\n";
    ImageBrightener brightener(image);
    int attenuatedCount = brightener.BrightenWholeImage();
    std::cout << "Attenuated " << attenuatedCount << " pixels\n";
}
