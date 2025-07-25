#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, M;
    int count = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int hands;
        scanf("%d", &hands);
        M -= hands;
        if (M < 0) break;
        count++;
    }

    printf("%d\n", count);

    return 0;
}
