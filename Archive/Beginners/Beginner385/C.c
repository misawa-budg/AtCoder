#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3000
#define MAXH 3000

int main(void) {
    int N;
    scanf("%d", &N);

    static int H[MAXN];
    for(int i = 0; i < N; i++){
        scanf("%d", &H[i]);
    }

    static int pos[MAXH + 1][MAXN];
    static int count[MAXH + 1] = {0};

    for(int i = 0; i < N; i++){
        int h = H[i];
        pos[h][count[h]] = i;
        count[h]++;
    }

    int ans = 1;
    for(int h = 1; h <= MAXH; h++){
        int M = count[h];
        if(M == 0) continue;
        if(M == 1) {
            if(ans < 1) ans = 1;
            continue;
        }

        static int dp[MAXN][MAXN];
        for(int j = 0; j < M; j++){
            for(int d = 0; d < N; d++){
                dp[j][d] = 0;
            }
        }


        for(int j = 0; j < M; j++){
            for(int i = 0; i < j; i++){
                int d = pos[h][j] - pos[h][i];
                if(dp[i][d] == 0) {
                    dp[j][d] = 2;
                } else {
                    dp[j][d] = dp[i][d] + 1;
                }
                if(dp[j][d] > ans) {
                    ans = dp[j][d];
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
