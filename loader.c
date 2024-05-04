/*
 * loader.c : Defines loader functions for opening and loading object files
 */

#include "loader.h"

// memory array location
unsigned short memoryAddress;

/*
 * Read an object file and modify the machine state as described in the writeup
 */
int ReadObjectFile(char* filename, MachineState* CPU)
{
  FILE* file;
  file = fopen(filename, "rb");

  unsigned short int *data = (unsigned short int *)malloc(sizeof(unsigned short int));
  if (data == NULL) {
    fclose(file);
    return -1;
  }

  int ret = -1;
  while (1) {
    ret = fread(data, 2, 1, file);
    if (ret != 1) {
      if (feof(file)) {
        // Reached end of file
        break;
      } 
      else {
        free(data);
        fclose(file);
        return -1;
      }
    }
    // data read 
    unsigned short int header, address, n;
    header = *data;
    header = (header << 8) | (header >> 8);

    switch(header)
    {
      case 0xDADA: // Data: 3-word header (0xDADA, <address>, <n>), n-word body comprising the initial data values
        fread(data, 2, 1, file);
        address = *data;
        address = (address << 8) | (address >> 8);
        fread(data, 2, 1, file);
        n = *data;
        n = (n << 8) | (n >> 8);

        for( int i = 0; i < n; ++i )
        {
          fread(data, 2, 1, file);
          CPU->memory[address+i] = *data;
        }
        break;

      case 0xCADE: // Code: 3-word header (0xCADE, <address>, <n>), n-word body comprising the instructions
        fread(data, 2, 1, file);
        address = *data;
        address = (address << 8) | (address >> 8);
        fread(data, 2, 1, file);
        n = *data;
        n = (n << 8) | (n >> 8);

        for( int i = 0; i < n; ++i )
        {
          fread(data, 2, 1, file);
          CPU->memory[address+i] = *data;
        }
        break;

      case 0xC3B7: // Symbol: 3-word header (0xC3B7, <address>, <n>), n-character body of the symbol string
        fread(data, 2, 1, file);
        address = *data;
        address = (address << 8) | (address >> 8);
        fread(data, 2, 1, file);
        n = *data;
        n = (n << 8) | (n >> 8);

        for( int i = 0; i < n; ++i )
        {
          fread(data, 1, 1, file);
          // don't need to populate memory with this data 
        }
        break;

      case 0xF17E: // File name: 2-word header (0xF17E, <n>), n-character body comprising the file name string
        fread(data, 2, 1, file);
        n = *data;
        n = (n << 8) | (n >> 8);

        for( int i = 0; i < n; ++i )
        {
          fread(data, 1, 1, file);
          // don't need to populate memory with this data 
        }
        break;

      case 0x715E: // Line number: 4-word header (0x715E, <address>, <line>, <file-index>), no body
        fread(data, 2, 1, file);
        fread(data, 2, 1, file);
        fread(data, 2, 1, file);
        break;

      default:
        fclose(file);
        free(data);
        return -1;
        break;
    }
  }

  free(data);
  fclose(file);
  return 0;
}
