#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char ** parse_args(char *line){
  char **store = malloc(256);
  int i = 0;
  while (line){
    store[i] = strsep(&line, " ");
    i++;
  }
  return store;
}

int main(int argc, char *argv[]){
  printf("Testing parse_args for 'ls -a -l'\n");
  char *line = malloc(256);
  strcat(line, "ls -a -l");
  char ** args = parse_args(line);
  printf("Printing arguments\n");
  int i = 0;
  while (args[i] != NULL){
    printf("%s\n", args[i]);
    i++;
  }
  printf("\nTesting execvp\n");
  execvp(args[0], args);
  return 0;
}
