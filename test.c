#include <stdio.h>

int main(void){
    
    char buffer[64] = {0};
    fgets(buffer, sizeof buffer, stdin);

    printf("Your input:\n");
    fwrite(buffer, sizeof(char), sizeof buffer, stdout);

    return 0;
}