#include <stdio.h>

int main(void){

  FILE *ftodo = fopen("todo.bin", "wb");
  FILE *fgoal = fopen("goal.bin", "wb");
  
  printf("Hello, World\n");
  
  
  return 0;
}
