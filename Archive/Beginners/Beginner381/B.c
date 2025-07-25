#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int judge(char S[], int len) {
    if (len % 2 == 1) return 0;
    int mid = len/2;
    for (int i = 0; i < mid; i++) {
        if (S[2*i] != S[2*i+1]) return 0;
    }
    char frequency[27];
    for (int i = 0; i < len; i++) {
        frequency[S[i] - 'a']++;
    }
    for (int i = 0; i < 27; i++) {
        if (frequency[i] != 0 && frequency[i] != 2) return 0;
    }
    return 1;
}

int main() {
    char S[101];
    scanf("%s", S);

    if (judge(S, strlen(S))) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
