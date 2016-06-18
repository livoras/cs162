#include <stdio.h>
#include <wctype.h>

#define INIT_COUNTER(X) \
  Counter X; \
  X.linecount = 0; \
  X.charcount = 0; \
  X.wordcount = 0;

typedef struct {
  int linecount;
  int wordcount;
  int charcount;
  int status; // 0, 1
} Counter;

int readFromStdInput();
int readFromFile(char *);
int formatOutPut(Counter *, char *);
int counting(Counter *, char);

int main (int argc, char *argv[]) {
  if (argc == 1) {
    readFromStdInput();
  } else {
    char *filename = argv[1];
    readFromFile(filename);
  }
  return 0;
}

int readFromStdInput () {
  char c;
  INIT_COUNTER(counter)
  while (scanf("%c", &c) != EOF) {
    counting(&counter, c);
  }
  formatOutPut(&counter, "");
  return 0;
}

int readFromFile (char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("%s file doesn't no exist.\n", filename);
  }
  char c;
  INIT_COUNTER(counter);
  while (fscanf(fp, "%c", &c) != EOF) {
    counting(&counter, c);
  }
  formatOutPut(&counter, filename);
  return 0;
}

int counting (Counter *counter, char c) {
    if (iswspace(c)) {
      if (counter->status) {
        counter->wordcount++;
      }
      if (c == '\n') {
        counter->linecount++;
      }
      counter->status = 0;
    } else {
      counter->status = 1;
    }
    counter->charcount++;
    return 0;
}

int formatOutPut(Counter *counter, char *filename) {
  printf("%d\t%d\t%d\t%s\n", counter->linecount, counter->wordcount, counter->charcount, filename);
  return 0;
}
