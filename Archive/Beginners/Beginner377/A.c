#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[4];
    int match[3] = {0};
    scanf("%s", S);

    for (int j = 'A'; j <= 'C'; j++) {
        for (int i = 0; i < 3; i++) {
            if (match[i] == 0 && S[i] == j) {
                match[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (match[i] == 0) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}
