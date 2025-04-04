#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101], output[101];
    scanf("%s", input);

    int len = strlen(input);

    for(int i = 0, j = 0; i < len; i++, j++) {
        while(input[i] == '.') {
            i++;
        }
        output[j] = input[i];
    }

    printf("%s\n", output);

}
