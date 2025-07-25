#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count = 0;
    for(int i = 1; i <= 12; i++) {
        char input[101];
        scanf("%s", input);
        int len = strlen(input);
        if(len == i) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
