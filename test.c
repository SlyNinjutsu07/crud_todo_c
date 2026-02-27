#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int main(void) {

  int curr_sel_index = 0, past_sel_index;

  char *options[] = {"TO-DO", "GOALS", "SETTINGS", "EXIT"};

  while (1) {
    
    printf("Type an index: ");
    int input = fgetc(stdin);
    fgetc(stdin);//Consume "\n"
    printf("%d\n", input);    
    if(input>=49 && input <= 52){
      past_sel_index = curr_sel_index;
      curr_sel_index = input;
    }
    
    char buffer[36]; 
    for (int i = 1; i <= 4; i++){

      if(curr_sel_index == i){
        strcpy(buffer,"(>) ");
        strcat(buffer, options[i]);
        printf("%s\n", buffer);        
      } else printf("%s\n", options[i - 1]);
    } 
  }

  return 0;
}
