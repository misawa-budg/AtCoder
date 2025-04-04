#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int canConvertWithOneEdit(char *S, char *T);

int main() {
    int K;
    char *S = (char *)malloc((500002) * sizeof(char));
    char *T = (char *)malloc((500002) * sizeof(char));
    if (S == NULL || T == NULL) {
        return 1;
    }

    scanf("%d %s %s", &K, S, T);


    if (canConvertWithOneEdit(S, T)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(S);
    free(T);

    return 0;
}

int canConvertWithOneEdit(char *S, char *T) {
    int lenS = strlen(S);
    int lenT = strlen(T);

    if (abs(lenS - lenT) > 1) {
        return 0;
    }

    if (lenS == lenT) {
        int diff = 0;
        for (int i = 0; i < lenS; i++) {
            if (S[i] != T[i]) {
                diff++;
                if (diff > 1) {
                    return 0;
                }
            }
        }
        return 1;
    }

    if (lenS + 1 == lenT) {
        int i = 0, j = 0;
        int mismatch = 0;
        while (i < lenS && j < lenT) {
            if (S[i] == T[j]) {
                i++;
                j++;
            } else {
                if (mismatch) {
                    return 0; 
                }
                mismatch = 1;
                j++;
            }
        }
        return 1;
    }

    if (lenS - 1 == lenT) {
        int i = 0, j = 0;
        int mismatch = 0;
        while (i < lenS && j < lenT) {
            if (S[i] == T[j]) {
                i++;
                j++;
            } else {
                if (mismatch) {
                    return 0;
                }
                mismatch = 1;
                i++; 
            }
        }
        return 1;
    }
    return 0;
}