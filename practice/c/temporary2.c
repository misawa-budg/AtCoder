#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1001
#define INF 1000000

int main() {
    char S[MAX_LENGTH];
    scanf("%s", S);
    int N = strlen(S);
    
    int dp[MAX_LENGTH];
    for(int i = 0; i <= N; i++) {
        dp[i] = INF;
    }
    dp[0] = 0; 
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        
        if(i >= 2 && S[i-2] == '0' && S[i-1] == '0') {
            if(dp[i-2] + 1 < dp[i]) {
                dp[i] = dp[i-2] + 1;
            }
        }
    }
    
    printf("%d\n", dp[N]);
    
    return 0;
}