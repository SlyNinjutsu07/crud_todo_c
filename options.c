#include <stdio.h>
#include <string.h>
#include "options.h"


void write(char *file_path){
  FILE *file = fopen(file_path, "ab");//Open in append mode
  printf("Type what you want to add: ");
  char input[64];
  fgets(input, sizeof(input) - 2, stdin);
  char mod_input[67]; // 6 7 🤪
  snprintf(mod_input, sizeof mod_input, "- %s\n", input);
  fwrite(mod_input, sizeof(char), sizeof mod_input, file);
  fclose(file);
}

// Outputs the values from that specific file
void read(char *file_path) {
  //Open the file
  FILE *file = fopen(file_path, "rb");
  char buffer[256];
  buffer[0] = '\0';
  fread(buffer,256,sizeof(char),file);

  char *pa = buffer, *pb = pa;
  char task[64];

  while ((pa = strstr(pa, "-")) != NULL) {
    strncpy(task, pb, pa - pb);
    task[strcspn(task, "\n")] = '\0';
    printf("%s\n", task);
    pb = pa;
  }

  fclose(file);
}

void settings(){
  //Either clear goals or to-dos
}