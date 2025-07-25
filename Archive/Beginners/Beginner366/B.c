#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, M = 0;
    scanf("%d", &N);

    char S[101][101];
    char T[101][101];

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 100; j++) {
            T[i][j] = '*';
        }
    }


    for(int i = 0; i < N; i++) {
        scanf("%s", S[i]);
        if(strlen(S[i]) > M) M = strlen(S[i]);
    }

    for(int i = 0; i < N; i++) {
        int tempLen = strlen(S[i]);
        for(int j = 0; j < tempLen; j++) {
            T[j][N - i - 1] = S[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        int tempLen = N;
        while(tempLen > 0 && T[i][tempLen - 1] == '*') {
            tempLen--;
        }
        T[i][tempLen] = '\0';
        printf("%s\n", T[i]);
    }


    return 0;
}
