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

  char* pa = buffer, pb = pa;
  char* task = '\0';
  while(pa = strstr(pa, '-')){
    strcpy(task,pa - pb);
    printf("%s\n", task);
    pb = pa;
  } 
  
}
