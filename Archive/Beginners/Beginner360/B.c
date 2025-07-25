#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[101], T[101];
    scanf("%s %s", S, T);

    int Slen = strlen(S);
    int Tlen = strlen(T);
    int isExist = 0;

    for(int i = 1; i < Slen; i++) {
        for(int j = 0; j < i; j++) {
            char temp[101];
            int l = 0;
            for(int k = j; k < Slen; k += i, l++) {
                temp[l] = S[k];
            }
            temp[l] = '\0';
            if(strcmp(temp, T) == 0) {
                isExist = 1;
                break;
            }
        }
        if(isExist) break;
    }

    isExist == 1 ? printf("Yes\n") : printf("No\n");

    return 0;

}
