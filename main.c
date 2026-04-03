#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Opening files
  note todos = {.note_path = "files/todo.bin", .note_count = 0};
  note goals = {.note_path = "files/goals.bin", .note_count = 0};
  int curr_sel_index = 1;

  char *options[] = {"TO-DO", "GOALS", "SETTINGS", "EXIT"};

  // Getting Input
  while (1) {

    char ops_buffer[36];
    for (int i = 1; i <= 4; i++) {
      // Prints out options
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

    // MENU
    // 1-4 for options
    if (1 <= input[0] - '0' && input[0] - '0' <= 4) {
      curr_sel_index = input[0] - '0';
    }
    // 'q' to quit
    else if (input[0] == 'q') {
      exit(0);
    } 
    // 'd' to delete
    else if (input[0] == 'd') {
    }
    // enter to see that list
    else if (input[0] == '\n') {
      char i[64];               // input

      switch (curr_sel_index) {
      case 1: // TODOS
        printf(
            "Hit enter to view list | Type if you want to add something new: ");
        fgets(i, sizeof i, stdin);
        if (i[0] == '\n') {
          read(&todos);
        } else
          write(&todos, i);
        break;
      case 2: // GOALS
        printf("Hit enter or type a new goal: ");
        fgets(i, sizeof i, stdin);
        if (i[0] == '\n')
          read(&goals);
        else
          write(&goals, i);
        break;
      }
    }

    todos.note_count = 0;
    goals.note_count = 0;

    system("clear");
  }

  return 0;
}
