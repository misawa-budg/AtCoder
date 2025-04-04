#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s",S);

    int lastStart, lastEnd;
    int start, end;
    int inWord = 0;
    int group = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (!inWord)
            {
                start = i;
                group++;
            }
            inWord = 1;
        } else {
            if (inWord) {
                end = i-1;
                inWord = 0;
            }
            if (group == K)
                break;
            if (group > 1) {
                lastStart = start;
                lastEnd = end;
            }
        }
        if (group == 1) {
            if (!inWord) {
                lastStart = start;
                lastEnd = end;
            }
        }
        if (i == N-1) {
            end = i;
        }
    }

    int segmentSize = end - start + 1;

    for (int i = 0; i < segmentSize; i++) {
        S[lastEnd+1+i] = '1';
        S[start+i] = '0';
    }

    printf("%s\n", S);


    return 0;
}
