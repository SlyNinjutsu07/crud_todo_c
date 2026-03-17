#include <stdio.h>
#include "options.h"

void write(){

}

// Outputs the values from that specific file
void list(FILE *file) {
  char buffer[256];
  fread(buffer,256,sizeof(char),file);
}
