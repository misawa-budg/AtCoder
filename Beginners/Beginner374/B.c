#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[101], T[101];
    scanf("%s%s", S, T);

    int Slen = strlen(S), Tlen = strlen(T);
    int maxlen = (Slen >= Tlen) ? Slen : Tlen;

    int isSame = 1, index;

    for(int i = 0; i < maxlen; i++) {
        if(S[i] == '\0' || T[i] == '\0') {
            isSame = 0;
            index = i + 1;
        } else if (S[i] != T[i]) {
            isSame = 0;
            index = i + 1;
        }
        if(!isSame) break;
    }

    if(isSame) {
        printf("0\n");
    } else {
        printf("%d\n", index);
    }

    return 0;

}
