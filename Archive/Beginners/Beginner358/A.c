#include <stdio.h>
#include <string.h>

int main() {
  char input1[11];
  char input2[11];

  scanf("%s %s", input1, input2);

  (strcmp(input1, "AtCoder") == 0 && strcmp(input2, "Land") == 0) ? printf("Yes\n") : printf("No\n");

  return 0;
}
