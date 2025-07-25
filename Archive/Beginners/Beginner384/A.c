#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    char c1, c2;
    scanf("%d %c %c", &N, &c1, &c2);

    char S[N+1];
    scanf("%s", S);

    for (int i = 0; i < N; i++) {
        if (S[i] != c1) {
            S[i] = c2;
        }
    }

    printf("%s\n", S);

    return 0;
}
