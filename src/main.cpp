#include <iostream>
#include <fstream>
#include <string>
#include "cxxopts.hpp"
#include "TermiPixel/image_processor.hpp"
#include "TermiPixel/ascii_converter.hpp"

void saveToFile(const std::string& content, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "ASCII art saved to " << filename << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
    }
}

int main(int argc, char* argv[]) {
    // CLI Options Setup
    cxxopts::Options options("TermiPixel", "A powerful CLI tool to convert images to ASCII art.");
    options.add_options()
        ("f,file", "Input image file path", cxxopts::value<std::string>())
        ("w,width", "Width of the output ASCII art in characters", cxxopts::value<unsigned int>()->default_value("100"))
        ("o,output", "Output file path (prints to console if not specified)", cxxopts::value<std::string>())
        ("i,invert", "Invert brightness (light becomes dark)", cxxopts::value<bool>()->default_value("false"))
        ("s,set", "Character set for ASCII mapping (e.g., 'simple', 'detailed')", cxxopts::value<std::string>()->default_value("detailed"))
        ("h,help", "Print usage information");

    try {
        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            return 0;
        }

        if (!result.count("file")) {
            std::cerr << "Error: Input file must be specified with -f or --file." << std::endl;
            std::cerr << options.help() << std::endl;
            return 1;
        }

        std::string filePath = result["file"].as<std::string>();
        unsigned int width = result["width"].as<unsigned int>();
        bool invert = result["invert"].as<bool>();
        std::string charSet = result["set"].as<std::string>();

        // Character Set Selection
        std::string ramp;
        if (charSet == "simple") {
            ramp = " .:-=+*#%@";
        } else { // "detailed" is default
            ramp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
        }

        // Processing Logic
        ImageProcessor processor;
        if (!processor.loadImage(filePath)) {
            return 1;
        }

        GrayscaleMatrix grayMatrix = processor.toGrayscale(width, invert);

        AsciiConverter converter(ramp);
        std::string asciiResult = converter.convert(grayMatrix);

        // Output
        if (result.count("output")) {
            saveToFile(asciiResult, result["output"].as<std::string>());
        } else {
            std::cout << asciiResult;
        }

    } catch (const cxxopts::exceptions::exception& e) {
        std::cerr << "Error parsing options: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
