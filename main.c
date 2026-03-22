#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Opening files
  char *path_todos = "files/todo.bin";
  char *path_goals = "files/goals.bin";

  int curr_sel_index = 1;

  char *options[] = {"TO-DO", "GOALS", "SETTINGS", "EXIT"};

  // Getting Input
  while (1) {

    char ops_buffer[36];
    for (int i = 1; i <= 4; i++) {
      // Prints out option
      if (curr_sel_index == i) {
        strcpy(ops_buffer, "(>) ");
        strcat(ops_buffer, options[i - 1]);
        printf("%s\n", ops_buffer);
      } else
        printf("%s\n", options[i - 1]);
    }
    memset(ops_buffer, 0, sizeof ops_buffer);

    char input[10];

    printf("Type an index (hit 'q' to exit): ");
    fgets(input, sizeof input, stdin);

    // 1-4 for options
    if (1 <= input[0] - '0' && input[0] - '0' <= 4) {
      curr_sel_index = input[0] - '0';
    } 
    // 'q' to quit
    else if (input[0] == 'q') {
      exit(0);
    } 
    // enter to see that list
    else if (input[0] == '\n') {
      char *list_buffer = NULL;
      char i[64];
      // TO-DOS
      if (curr_sel_index == 1) {
        printf(
            "Hit enter to view list | Type if you want to add something new: ");
        fgets(i, sizeof i, stdin);
        if (i[0] == '\n')
          printf("%s", read(path_todos, list_buffer));
        else
          write(path_todos, i);
      }
      // GOALS
      else if (curr_sel_index == 2) {
        printf("Hit enter or type a new goal: ");
        fgets(i, sizeof i, stdin);
        if (i[0] == '\n')
          printf("%s", read(path_goals, list_buffer));
        else
          write(path_goals, i);
      }
    }
    system("clear");
  }

  return 0;
}
