#include "TermiPixel/ascii_converter.hpp"
#include <stdexcept>

AsciiConverter::AsciiConverter(std::string charRamp) : characterRamp(std::move(charRamp)) {
    if (characterRamp.empty()) {
        throw std::invalid_argument("Character ramp cannot be empty.");
    }
}

std::string AsciiConverter::convert(const GrayscaleMatrix& matrix) {
    std::string asciiArt;
    if (matrix.empty()) {
        return asciiArt;
    }

    // Pre-calculate ramp size to avoid calling .length() in the loop
    size_t rampSize = characterRamp.length();

    for (const auto& row : matrix) {
        for (const auto& pixelValue : row) {
            // Map the 0-255 grayscale value to an index in the character ramp
            int rampIndex = (pixelValue * (rampSize - 1)) / 255;
            asciiArt += characterRamp[rampIndex];
        }
        asciiArt += '\n';
    }
    return asciiArt;
}
