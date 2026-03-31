#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"

#define SIZE 256

//Writes the following: "- {string}\n\0"
void write(char *file_path, char *usr_input){
  FILE *file = fopen(file_path, "ab");//Open in append mode
  char mod_input[40]; 
  snprintf(mod_input, sizeof mod_input, "- %s\n", usr_input);//Null-term on its own
  fwrite(mod_input, sizeof(char), strlen(mod_input) + 1, file);//strlen + 1 includes '\0'
  // read(file_path);
  fclose(file);
}

// Outputs the values from that specific file
char *read(char *file_path, char *buffer) {
  //Open the file
  FILE *file = fopen(file_path, "rb");
  buffer = (char *)malloc(sizeof(char) * SIZE);

  //Read notes and null-terminate
  int pos = 0;
  char byte;

  while(fread(&byte, sizeof(char), 1, file) > 0){
    if(byte != '\0') buffer[pos++] = byte;
    if(pos >= SIZE) break;
  }
  buffer[pos] = '\0';

  system("clear");
  printf("%s", buffer);
  fgetc(stdin);

  fclose(file);
  
  return buffer;
}


void settings(void){
  //Either clear goals or to-dos
}
