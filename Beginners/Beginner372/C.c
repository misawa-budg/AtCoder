#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, Q, ABCs = 0;
    scanf("%d %d", &N, &Q);
    char S[N+1];
    scanf("%s", S);

    for(int i = 0; i <= N - 3; i++) {
        if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') ABCs++;
    }

    for(int i = 0; i < Q; i++) {
        int index, count = ABCs;
        char C;
        scanf("%d %c", &index, &C);
        index--;

        int pre[3] = {0}, post[3] = {0};

        for(int j = index - 2, k = 0; j <= index; j++, k++) {
            if(0 <= j && j <= N - 3) {
                if(S[j] == 'A' && S[j+1] == 'B' && S[j+2] == 'C') {
                    pre[k] = 1;
                }
            }
        }

        S[index] = C;

        for(int j = index - 2, k = 0; j <= index; j++, k++) {
            if(0 <= j && j <= N - 3) {
                if(S[j] == 'A' && S[j+1] == 'B' && S[j+2] == 'C') {
                    post[k] = 1;
                }
            }
        }

        for(int j = 0; j < 3; j++) {
            if(pre[j] != post[j]) {
                if(pre[j]) count--;
                if(post[j]) count++;
            }
        }

        printf("%d\n", count);
        ABCs = count;
    }

    return 0;
}
