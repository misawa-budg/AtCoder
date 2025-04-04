#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s", S);

    int count = 0;
    int countinue = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'O') {
            countinue++;
            if (countinue >= K) {
                countinue = 0;
                count++;
            }
        } else {
            countinue = 0;
        }
    }



    printf("%d\n", count);

    return 0;
}
