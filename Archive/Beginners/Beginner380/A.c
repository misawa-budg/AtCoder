#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int N;
    scanf("%d", &N);

    int is = 0;
    int one=0, two=0, three=0;

    for (; N > 0;) {
        int temp = N % 10;
        if (temp == 1) one++;
        if (temp == 2) two++;
        if (temp == 3) three++;
        N /= 10;
    }

    if (one == 1 && two == 2 && three == 3) is = 1;

    printf("%s", (is == 1)?"Yes\n":"No\n");

    return 0;
}
