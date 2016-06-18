#include <stdio.h>
#include <wctype.h>

int readFromStdInput();
int readFromFile(char *);
int formatOutPut(int, int, int, char *);

int main (int argc, char *argv[]) {
  if (argc == 0) {
    readFromStdInput();
  } else {
    char *filename = argv[1];
    readFromFile(filename);
  }
  return 0;
}

int readFromStdInput () {
  printf("FUCK\n");
  return 0;
}

int readFromFile (char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("%s file doesn't no exist.\n", filename);
  }
  char c; /* read char from file */
  int wordcount = 0; /* words count */
  int linecount = 0;
  int charcount = 0;
  int in_word = 0; /* if has started check for word */
  while (fscanf(fp, "%c", &c) != EOF) {
    if (iswspace(c)) {
      if (in_word) {
        wordcount++;
      }
      if (c == '\n') {
        linecount++;
      }
      in_word = 0;
    } else {
      in_word = 1;
    }
    charcount++;
  }
  return 0;
}

int formatOutPut(int linecount, int wordcount, int charcount, char *filename) {
  printf("%d\t%d\t%d\t%s\n", linecount, wordcount, charcount, filename);
  return 0;
}
