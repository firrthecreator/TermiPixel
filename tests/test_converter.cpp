#include <gtest/gtest.h>
#include "TermiPixel/ascii_converter.hpp"
#include <stdexcept>

// A test fixture can be used to share setup/teardown code between tests.
class AsciiConverterTest : public ::testing::Test {};

// Tests that a basic grayscale matrix is converted correctly.
TEST_F(AsciiConverterTest, HandlesBasicConversion) {
    // Arrange: Create a predictable 2x2 grayscale matrix and a simple ramp.
    GrayscaleMatrix matrix = {
        {0, 85},      // Darkest, one-third brightness
        {170, 255}    // Two-thirds brightness, brightest
    };
    AsciiConverter converter("0123");

    // Act: Convert the matrix to an ASCII string.
    std::string result = converter.convert(matrix);
    
    // Assert: The result should match the expected ASCII string.
    ASSERT_EQ(result, "01\n23\n");
}

// Tests that an empty matrix is handled gracefully.
TEST_F(AsciiConverterTest, HandlesEmptyMatrix) {
    // Arrange: Create an empty matrix.
    GrayscaleMatrix emptyMatrix;
    AsciiConverter converter("abcd");

    // Act: Convert the empty matrix.
    std::string result = converter.convert(emptyMatrix);

    // Assert: The result should be an empty string.
    ASSERT_TRUE(result.empty());
}

// Tests that the constructor throws an exception if the character ramp is empty.
TEST_F(AsciiConverterTest, ThrowsOnEmptyRamp) {
    // Assert: Check that constructing with an empty ramp throws std::invalid_argument.
    // This is the expected behavior to prevent runtime errors later.
    ASSERT_THROW(AsciiConverter(""), std::invalid_argument);
}

// Tests that the mapping logic works correctly with a more detailed ramp.
TEST_F(AsciiConverterTest, HandlesDetailedRamp) {
    // Arrange: Create a simple matrix and a 10-character ramp.
    GrayscaleMatrix matrix = {{0, 128, 255}}; // Dark, middle gray, bright
    const std::string detailedRamp = " .:-=+*#%@";

    AsciiConverter converter(detailedRamp);

    // Act: Convert the matrix.
    std::string result = converter.convert(matrix);

    // Assert: The pixels should map to the start, middle, and end of the ramp.
    // 0   -> index 0 -> ' '
    // 128 -> index 5 -> '='
    // 255 -> index 9 -> '@'
    ASSERT_EQ(result, " =@\n");
}
