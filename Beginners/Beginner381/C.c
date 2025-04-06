#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int judge(char S[], int l, int r) {
    if (S[l] != '1') return 0;
    if (S[r] != '2') return 0;
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    char S[N+1];
    scanf("%s", S);

    int temp;
    int maxLen = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '/') {
            for (int j = 0; j < N; j++) {
                if (i-j < 0 || i+j >= N) break;
                if (judge(S, i-j, i+j)) {
                    temp = 1 + 2 * j;
                } else if (j == 0) {
                    temp = 1;
                } else {
                    break;
                }
                if (temp > maxLen) maxLen = temp;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
