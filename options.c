#include <stdio.h>
#include <string.h>
#include "options.h"


void write(char *file_path, char *usr_input){
  FILE *file = fopen(file_path, "ab");//Open in append mode
  char mod_input[40]; // 6 7 🤪
  snprintf(mod_input, sizeof mod_input, "- %s\n", usr_input);//Null-term on its own
  fwrite(mod_input, sizeof(char), sizeof mod_input, file);
  read(file_path);
  fclose(file);
}

// Outputs the values from that specific file
void read(char *file_path) {
  //Open the file
  FILE *file = fopen(file_path, "rb");
  char buffer[256];
  size_t n = fread(buffer,sizeof buffer,sizeof(char),file);
  buffer[strcspn(buffer, "\0")] = ' ';
  buffer[n] = '\0';

  char *pa = buffer, *pb = pa;
  char task[32];

  while ((pa = strstr(pa, "\n")) != NULL) {
    strncpy(task, pb, (pa - pb) + 1);
    printf("%s", task);
    pb = pa;
    pa++;
  }

  fclose(file);
}

void settings(){
  //Either clear goals or to-dos
}