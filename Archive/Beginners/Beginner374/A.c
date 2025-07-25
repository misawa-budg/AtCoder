#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int len;
    char input[31];
    scanf("%s", input);

    len = strlen(input);

    int haveSan = 0;

    if(input[len - 3] == 's') {
        if(input[len - 2] == 'a') {
            if(input[len - 1] == 'n') {
                haveSan = 1;
            }
        }
    }

    if(haveSan) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
