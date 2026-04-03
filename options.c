#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"

#define SIZE 256

// Writes the following to file @ `file_path`: "- {`usr_input`}\n\0"
void write(note *n, char *usr_input){
  FILE *file = fopen(n->note_path, "ab");//Open in append mode
  char mod_input[40]; 
  snprintf(mod_input, sizeof mod_input, "- %s\n", usr_input);//Null-term on its own
  fwrite(mod_input, sizeof(char), strlen(mod_input) + 1, file);//strlen + 1 includes '\0'
  // read(file_path);
  fclose(file);
}

// Allocates `256 bytes` to `buffer`
// Reads data from file @ `file_path` into `buffer`
// Auto terminates: `'\0'`
char *read(note *n) {
  //Open the file
  FILE *file = fopen(n->note_path, "rb");
  char *buffer = (char *)malloc(sizeof(char) * SIZE);

  if(!file) return NULL;
  if(!buffer) {fclose(file); return NULL;}

  //Read notes and null-terminate
  int pos = 0;
  char byte;

  //Reads until the last character IN THE FILE (not in garbage memory)
  while(fread(&byte, sizeof(char), 1, file) > 0){
    if(byte != '\0') buffer[pos++] = byte; //Reads without null terminations
    if(byte == '-') n->note_count++;
    if(pos >= SIZE) break;
  }
  buffer[pos] = '\0';

  system("clear");
  printf("%s\n", buffer);
  fgetc(stdin);

  fclose(file);
  
  return buffer;
}

void delete_item(note *n){
  char *del_buf = read(n);
  int i = 1;
  char *p1 = del_buf, *p2 = p1;

  //Put a number in front of every option
  while((p1 = strstr(p2, "\n")) != NULL){
    printf("{%d} %.*s\n", i, (int)(p1-p2), p2);
    i++;
    p1+=2;//skip the second '\n'
    p2 = p1;
  }
    
  printf("Which note would you like to delete?");

  fgetc(stdin);
}

void settings(void){
  //Either clear goals or to-dos
}
