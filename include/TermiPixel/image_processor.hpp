#ifndef TERMIPixel_IMAGE_PROCESSOR_HPP
#define TERMIPixel_IMAGE_PROCESSOR_HPP

#include <string>
#include <vector>
#include <cstdint>

// Represents a grayscale pixel value
using GrayscaleMatrix = std::vector<std::vector<uint8_t>>;

class ImageProcessor {
public:
    /**
     * @brief Loads an image from the specified file path.
     * @param filePath The path to the image file.
     * @return True if the image was loaded successfully, false otherwise.
     */
    bool loadImage(const std::string& filePath);

    /**
     * @brief Converts the loaded image to grayscale and resizes it.
     * @param width The target width in characters for the ASCII art.
     * @param invert Inverts the brightness of the pixels if true.
     * @return A 2D vector representing the grayscale matrix of the image.
     */
    GrayscaleMatrix toGrayscale(unsigned int width, bool invert);

private:
    int imgWidth = 0;
    int imgHeight = 0;
    int channels = 0;
    unsigned char* imageData = nullptr;
};

#endif //TERMIPixel_IMAGE_PROCESSOR_HPP
