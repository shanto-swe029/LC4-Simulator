/*
 * trace.c: location of main() to start the simulator
 */

#include "loader.h"

// Global variable defining the current state of the machine
MachineState* CPU;

int main(int argc, char** argv)
{
  if( argc < 3 ) {
    printf("error1: usage: ./trace <output_filename.txt> <first.obj> ...\n");
    return -1;
  }
  else {
    for( int i = 2; i < argc; i++ )
    {
      FILE* file = fopen(argv[i], "r");
      if(file == NULL) {
        printf("error: invalid file name %s\n", argv[i]);
        return -1;
      }
      fclose(file);
    }
  }

  CPU = malloc(sizeof(MachineState)); // Allocate memory for CPU
  if (CPU == NULL) {
      printf("Failed to allocate memory for CPU\n");
      return -1; // Return an error code if memory allocation fails
  }

  for( int i = 0; i < 65536; ++i )
  {
    CPU->memory[i] = 0;
  }

  // Read each .obj file and load into memory 

  for( int i = 2; i < argc; ++i )
  {
    int ret = ReadObjectFile(argv[i], CPU);

    if( ret == -1 ) {
      printf("error: Cannot read .obj files\n");
      return -1;
    }
  }

  FILE* out_file = fopen(argv[1], "w");

  if( out_file == NULL ) {
    printf("error: output file writing error\n");
    return -1;
  }

  // Save this memory into the output file 
  for( int i = 0; i < 65536; i++ )
  {
    fprintf(out_file, "address: %05d contents: 0x%04x\n", i, CPU->memory[i]);
  }

  fclose(out_file);
  free(CPU);
  return 0;
}