#include <stdio.h>
#include <string.h>
#include "options.h"


void write(){

}

// Outputs the values from that specific file
void read(char *file_path) {
  //Open the file
  FILE *file = fopen(file_path, "rb");
  char buffer[256];
  buffer[0] = '\0';
  fread(buffer,256,sizeof(char),file);

  char* p = buffer;
  char* task = p;
  while(p = strstr(p, '-')){
    strcat(task,buffer - p);
    printf("%s\n", task);
  }
  
}
