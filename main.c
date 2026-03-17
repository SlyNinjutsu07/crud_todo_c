#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"

int main(void) {

  //Opening files
  char *path_todos = "files/todo.bin";
  char *path_goals = "files/goals.bin"; 

  int curr_sel_index = 1, past_sel_index = 0;

  char *options[] = {"TO-DO", "GOALS", "SETTINGS", "EXIT"};

  //Getting Input
  while (1) {

    char buffer[36];
    for (int i = 1; i <= 4; i++) {
      // Prints out option
      if (curr_sel_index == i) {
        strcpy(buffer, "(>) ");
        strcat(buffer, options[i - 1]);
        printf("%s\n", buffer);
      } else
        printf("%s\n", options[i - 1]);
    }
    memset(buffer, 0, sizeof(buffer));

    char input[10];

    printf("Type an index (hit 'q' to exit): ");
    fgets(input, sizeof input, stdin);

    if (1 <= input[0] - '0' && input[0] - '0' <= 4) {
      past_sel_index = curr_sel_index;
      curr_sel_index = input[0] - '0';
    } 
    else if (input[0] == 'q'){
      exit(0);
    }
    else if (input[0] == '\n'){
      if(curr_sel_index == 1){
        write(path_todos);
      } 
      else if (curr_sel_index == 0) write(path_goals);
      // if(curr_sel_index == 1) read(path_todos);
      // else if (curr_sel_index == 0) read(path_goals);
    }
    // system("clear");
  }


  return 0;
}
