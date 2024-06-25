# LC4 Disassembler

This project involves creating an LC4 Disassembler in C. The program reads a .OBJ file created by PennSim, parses it, and loads the data into a hash table of linked lists representing the segments of LC4’s memory. The goal is to reverse assemble the contents back into the original assembly code.

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
The LC4 Disassembler reads an LC4 .OBJ file, parses it, and loads the data into a hash table of linked lists. It then reverse assembles the binary data back into assembly code. This project demonstrates the use of dynamic memory in C, including linked lists and hash tables.

## Features
- Reads and parses LC4 .OBJ files
- Loads data into a hash table of linked lists
- Reverse assembles binary data into assembly code
- Handles dynamic memory allocation and management

## Technologies Used
- C programming language
- clang compiler

## Installation
1. **Compile the program:**
    ```sh
    clang lc4_memory.c lc4_memory_test.c -o lc4_memory_test
    ```

## Usage
1. **Run the disassembler:**
    ```sh
    ./lc4 <output_filename.txt> <object_file1.obj> <object_file2.obj> ...
    ```
   Replace `<output_filename.txt>` with the desired output file name and `<object_file1.obj>`, `<object_file2.obj>`, etc., with the names of your LC4 object files.

2. **Example:**
    ```sh
    ./lc4 output.txt first.obj second.obj
    ```

## Contributing
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -m 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Open a Pull Request

## License
This project is licensed under the MIT License.

## Contact
For any questions or support, please contact [dev.shanto.bd@gmail.com](mailto:dev.shanto.bd@gmail.com).

