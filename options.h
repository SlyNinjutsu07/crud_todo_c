#include <stdio.h>

typedef struct {
  int note_count;
  char *note_path;
} note;

void write(note *n, char *usr_input);
char *read(note *n, char *buffer);
void settings();
