#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 200005
#define MAXQ 200005

char S[MAXLEN];
long long K[MAXQ];
char result[MAXQ];
int Q;
int lenS;

char swapcase(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a' + 'A';
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}

char get_char(long long K, long long len_current) {
    if (len_current == lenS) {
        return S[K - 1];
    }
    long long len_half = len_current / 2;
    if (K <= len_half) {
        return get_char(K, len_half);
    } else {
        char c = get_char(K - len_half, len_half);
        return swapcase(c);
    }
}

int main() {
    scanf("%s", S);
    lenS = strlen(S);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &K[i]);
    }

    for (int i = 0; i < Q; i++) {
        long long Ki = K[i];
        long long len_current = lenS;
        while (len_current < Ki) {
            len_current *= 2;
        }
        char c = get_char(Ki, len_current);
        result[i] = c;
    }

    for (int i = 0; i < Q; i++) {
        printf("%c", result[i]);
        if (i != Q - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
