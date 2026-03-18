#include <stdio.h>
#include <string.h>
#include "options.h"


void write(char *file_path){
  FILE *file = fopen(file_path, "ab");//Open in append mode
  printf("Type what you want to add: ");
  char input[64];
  input[0] = '\0';
  fgets(input, sizeof input, stdin);
  fprintf(file, "- %s\n", input);
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
