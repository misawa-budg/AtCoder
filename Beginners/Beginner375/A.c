#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    scanf("%d" , &N);
    char S[N+1];
    scanf("%s", S);
    int count = 0;
    for(int i = 0; i < N - 2; i++) {
        if(S[i] == '#' && S[i+1] == '.' && S[i+2] == '#') count++;
    }

    printf("%d\n", count);


    return 0;
}
