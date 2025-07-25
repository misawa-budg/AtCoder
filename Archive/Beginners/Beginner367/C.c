#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K;
int r[8];
int seq[8];

void solve(int lv) {
    if(lv == N){
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += seq[i];
        }
        if(sum % K == 0) {
            for(int i = 0; i < N; i++) {
                if(i) {
                    printf(" ");
                }
                printf("%d", seq[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= r[lv]; i++) {
        seq[lv] = i;
        solve(lv + 1);
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &r[i]);
    }
    solve(0);
    return 0;
}
