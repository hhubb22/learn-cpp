# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ learning project with a simple "Hello World" program. The project uses CMake for build management and follows modern C++17 standards.

## Build Commands

### Full Build Process
```bash
rm -rf build && mkdir build && cd build && cmake .. && make
```

### Quick Build (if build directory exists)
```bash
cd build && make
```

### Clean Build
```bash
rm -rf build
```

## Project Structure

- `src/hello.cc` - Main source file containing the Hello World program
- `CMakeLists.txt` - Root CMake configuration with project settings
- `src/CMakeLists.txt` - Source-specific CMake configuration
- `build/bin/hello` - Compiled executable location (after build)
- `main` - Legacy executable (can be ignored)

## CMake Configuration

The project is configured with:
- C++17 standard requirement
- Executable output directed to `build/bin/` directory
- Modern CMake practices with target-specific properties

## Running the Program

After building:
```bash
./build/bin/hello
```

Output: `Hello, Zed!`

## Architecture Notes

This is a single-file C++ program with minimal complexity. The CMake structure is designed to demonstrate best practices for C++ project organization, even for simple programs.