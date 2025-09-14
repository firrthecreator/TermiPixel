#include "TermiPixel/image_processor.hpp"
// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

bool ImageProcessor::loadImage(const std::string& filePath) {
    if (imageData) {
        stbi_image_free(imageData);
    }
    imageData = stbi_load(filePath.c_str(), &imgWidth, &imgHeight, &channels, 0);
    if (!imageData) {
        std::cerr << "Error: Could not load image from " << filePath << std::endl;
        return false;
    }
    return true;
}

GrayscaleMatrix ImageProcessor::toGrayscale(unsigned int width, bool invert) {
    if (!imageData) {
        throw std::runtime_error("Image not loaded. Call loadImage() first.");
    }

    // Calculate new height to maintain aspect ratio, accounting for character aspect ratio (approx 2:1)
    double aspectRatio = static_cast<double>(imgHeight) / static_cast<double>(imgWidth);
    unsigned int height = static_cast<unsigned int>(std::round(static_cast<double>(width) * aspectRatio * 0.55));

    GrayscaleMatrix matrix(height, std::vector<uint8_t>(width));

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            // Map the output coordinates back to the original image coordinates
            int originalX = static_cast<int>((static_cast<double>(x) / width) * imgWidth);
            int originalY = static_cast<int>((static_cast<double>(y) / height) * imgHeight);

            // Get the pixel data from the original image
            unsigned char* pixelOffset = imageData + (originalY * imgWidth + originalX) * channels;
            
            // Convert to grayscale using the luminosity method
            uint8_t r = (channels >= 1) ? pixelOffset[0] : 0;
            uint8_t g = (channels >= 2) ? pixelOffset[1] : 0;
            uint8_t b = (channels >= 3) ? pixelOffset[2] : 0;

            // Grayscale formula: 0.21 R + 0.72 G + 0.07 B
            double grayValue = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            
            uint8_t finalGray = static_cast<uint8_t>(grayValue);

            if (invert) {
                matrix[y][x] = 255 - finalGray;
            } else {
                matrix[y][x] = finalGray;
            }
        }
    }
    stbi_image_free(imageData);
    imageData = nullptr;
    return matrix;
}
