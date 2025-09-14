# TermiPixel Usage Guide

This document provides a detailed overview of the command-line options available for TermiPixel.

## Command-Line Options

| Short Flag | Long Flag   | Description                                                                 | Default Value |
|------------|-------------|-----------------------------------------------------------------------------|---------------|
| `-f`       | `--file`    | **(Required)** Path to the input image file.                                | N/A           |
| `-w`       | `--width`   | Desired width of the ASCII art in characters.                               | `100`         |
| `-o`       | `--output`  | Path to the output text file. If omitted, output is printed to the terminal.| N/A           |
| `-i`       | `--invert`  | Invert the brightness-to-character mapping.                                 | `false`       |
| `-s`       | `--set`     | Character set to use: `simple` or `detailed`.                               | `detailed`    |
| `-h`       | `--help`    | Display help message and exit.                                              | N/A           |

## Character Sets

### simple
A basic 10-character set. Good for minimalistic or retro ASCII styles:
```
 .:-=+*#%@
```

### detailed
A 70+ character set offering more detail and smoother gradients:
```
$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. 
```

## Examples

### 1. Basic Conversion  
Convert `input.png` to ASCII and print it directly to the terminal:

```bash
termipixel -f input.png -w 150
```

### 2. Save to File  
Convert `avatar.jpg` and save the result to `avatar.txt`:

```bash
termipixel -f avatar.jpg -w 80 -o avatar.txt
```

### 3. Inverted and Simple Set  
Convert `landscape.png` using the `simple` character set, invert brightness, and save it:

```bash
termipixel -f landscape.png -w 200 -i --set simple -o landscape_simple.txt
```

## Notes

- The `--file` flag is mandatory.
- Output defaults to the terminal if no `--output` is specified.
- Higher widths improve detail but may require terminal resizing or horizontal scrolling.
- You can run `termipixel --help` to view available options at any time.
