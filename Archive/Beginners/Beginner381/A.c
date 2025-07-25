#include <stdio.h>
#include <string.h>
#include <ctype.h>

int judge(char S[], int len) {
    if (len % 2 == 0) return 0;
    int mid = (len+1)/2;
    for (int i = 0; i < mid-1; i++) {
        if (S[i] != '1') return 0;
    }
    if (S[mid-1] != '/') return 0;
    for (int i = mid; i < len; i++) {
        if (S[i] != '2') return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    char S[N+1];
    scanf("%s", S);

    if (judge(S, N)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
