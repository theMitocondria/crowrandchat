# Project Name

## Overview
This project is a C++ application that consists of multiple components including `Client`, `Manager`, and `Room`. The project is structured with separate directories for source files, header files, and build artifacts.

## Directory Structure

- [`build/`](): Contains the compiled object files.
- [`include/`](): Contains the header files.
- [`src/`](): Contains the source files.
- [`Makefile`](): Contains the build instructions.
- [`backend.out`](): The compiled executable.
- [`Readme.md`](): This file.

## Build Instructions

To build the project, you need to have `g++`,`crow` and `asio` installed in the environment. 

Then, You can build the project by running the following command in the root directory:

```sh
make
```

This will compile the source files in the src/ directory and place the object files in the build/ directory. The final executable will be named backend.out.

## Running the Application
After building the project, you can run the application using:
```sh
make run
```

This will execute the backend.out file.

## Cleaning the Build
To clean the build directory and remove all object files and the executable, run:
```sh
make clean
```
## Makefile Details
 - Compiler: g++
 - Source Directory: src
 - Include Directory: include
 - Build Directory: build
 - Executable Name: backend.out
 - Compiler Flags: -I$(INC_DIR) -std=c++11 -pthread
### Phony Targets
 - all: Default target to build the executable.
 - clean: Removes all object files and the executable.
 - run: Runs the executable.
### Dependencies
 - g++ (GNU Compiler Collection)
