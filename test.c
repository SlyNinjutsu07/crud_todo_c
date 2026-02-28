#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

int main(void) {

  int curr_sel_index = 1, past_sel_index = 0;

  char *options[] = {"TO-DO", "GOALS", "SETTINGS", "EXIT"};

  while (1) {

    printf("Type an index: ");
    int input = fgetc(stdin) - '0'; // To match inputs rather than ascii code
    fgetc(stdin); // Consume "\n"

    if (1 <= input && input <= 4) {
      past_sel_index = curr_sel_index;
      curr_sel_index = input;
    } else if(input == 0) exit(0);

    char buffer[36];
    for (int i = 1; i <= 4; i++) {
      if (curr_sel_index == i) {
        strcpy(buffer, "(>) ");
        strcat(buffer, options[i - 1]);
        printf("%s\n", buffer);
      } else
        printf("%s\n", options[i - 1]);
    }
    memset(buffer, 0, sizeof(buffer));
  }

  return 0;
}
