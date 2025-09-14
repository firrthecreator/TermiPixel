#ifndef TERMIPixel_ASCII_CONVERTER_HPP
#define TERMIPixel_ASCII_CONVERTER_HPP

#include "image_processor.hpp"
#include <string>

class AsciiConverter {
public:
    /**
     * @brief Constructs an AsciiConverter with a specific character set.
     * @param charRamp The string of characters used to represent brightness levels.
     */
    explicit AsciiConverter(std::string charRamp);

    /**
     * @brief Converts a grayscale matrix into an ASCII art string.
     * @param matrix The grayscale matrix from ImageProcessor.
     * @return A string containing the final ASCII art.
     */
    std::string convert(const GrayscaleMatrix& matrix);

private:
    std::string characterRamp;
};

#endif //TERMIPixel_ASCII_CONVERTER_HPP
