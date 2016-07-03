#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 0xefffffff;
  printf("%d\n", i);
  char *b = (char *)&i;
  printf("%d, %d\n", *b == 0x34, *(b + 1) == 0x12);
}

