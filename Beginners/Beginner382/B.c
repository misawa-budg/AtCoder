#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    char S[N+1];
    scanf("%s", S);

    int eatAmount = D;
    for (int i = N-1; i > -1; i--) {
        if (S[i] == '@') {
            S[i] = '.';
            eatAmount--;
            if(eatAmount == 0) {
                break;
            }
        }
    }

    printf("%s\n", S);

    return 0;
}
