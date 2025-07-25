#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[4];
    scanf("%s", S);

    int isLeft = 0;

    for(int i = 0; i < 3; i++) {
        if(S[i] == 'R') {
            isLeft = 1;
        }
        if(S[i] == 'M') {
            break;
        }
    }

    (isLeft == 1) ? printf("Yes\n") : printf("No\n");

    return 0;
}
