# TermiPixel

TermiPixel is a powerful and efficient command-line tool for converting images into ASCII art directly in your terminal.  
Written in modern C++, it is designed to be fast, customizable, and easy to maintain.

## Features

- **Multiple Image Format Support**  
  Supports PNG, JPG, BMP, and more using the `stb_image` library.

- **Customizable Width**  
  Allows you to set the width of the ASCII output to fit your terminal or artistic preference.

- **Brightness Inversion**  
  Option to invert the brightness-to-character mapping for negative-style effects.

- **Character Set Selection**  
  Choose between a simple 10-character set or a detailed 70-character set.

- **File Output Option**  
  Save the result to a `.txt` file or print directly to the terminal.

- **Cross-Platform Compatibility**  
  Buildable on Linux, macOS, and Windows using CMake and a C++17-compliant compiler.

- **Modular Codebase**  
  Structured for readability and ease of extension or maintenance.

## Prerequisites

To build TermiPixel, you need:

- A C++17-compatible compiler (e.g., GCC, Clang)
- CMake 3.10 or higher
- Git (for cloning the repository)

## Building the Project

1. **Clone the repository**
   ```bash
   git clone https://github.com/firrthecreator/TermiPixel.git
   cd TermiPixel
   ```

2. **Configure and build with CMake**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Install (optional)**
   ```bash
   sudo make install
   ```

## Usage

Refer to [`docs/USAGE.md`](docs/USAGE.md) for the complete list of available options and usage details.

### Quick Examples

Convert an image (`photo.jpg`) and output it to the terminal:
```bash
./build/termipixel -f /path/to/photo.jpg -w 120
```

Convert an image (`logo.png`), invert the brightness, and save the output to a text file:
```bash
./build/termipixel -f logo.png -w 80 --invert -o ascii_logo.txt
```

## Contributing

Contributions are welcome!  
Feel free to fork this repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.  
See the `LICENSE` file for full details.
