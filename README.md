# LC4 Simulator

## Overview

The LC4 Simulator is a command-line tool designed to simulate the execution of LC4 machine code. It loads binary object files created by the LC4 assembler, executes the instructions, and maintains the state of the LC4 processor. The simulator generates trace files that document the execution cycle-by-cycle.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Description

The LC4 Simulator reads LC4 .OBJ files, parses them, and loads the instructions and data into memory. It then simulates the execution of these instructions, updating the processor's state and producing a detailed trace of each cycle's activities. The simulator handles various LC4 machine code sections, including code, data, symbols, file names, and line numbers.

## Features

- Reads and parses PennSim-generated .OBJ files.
- Loads instructions and data into the LC4 memory.
- Simulates the execution of LC4 machine code.
- Produces trace files with detailed cycle information.
- Handles endianness conversion for different architectures.

## Technologies Used

- C programming language
- Clang compiler

## Installation

1. **Compile the project:**
    ```sh
    make all
    ```

This command will generate an executable named `trace`.

## Usage

1. **Run the simulator:**
    ```sh
    ./trace output_filename.txt first.obj second.obj third.obj ...
    ```

   - `output_filename.txt`: The name of the file where the trace output will be written.
   - `first.obj`, `second.obj`, `third.obj`, ...: One or more LC4 object files to be loaded into the simulator.

2. **Example:**
    ```sh
    ./trace output.txt example1.obj example2.obj
    ```

## Contributing

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/fooBar`).
3. Commit your changes (`git commit -m 'Add some fooBar'`).
4. Push to the branch (`git push origin feature/fooBar`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License.

## Contact

For any questions or support, please contact [dev.shanto.bd@gmail.com](mailto:dev.shanto.bd@gmail.com).
