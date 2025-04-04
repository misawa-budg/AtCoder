#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    int N;
    scanf("%d", &N);
    int A[3];
    A[0] = N/100;
    A[1] = (N-A[0]*100)/10;
    A[2] = (N-A[0]*100-A[1]*10);

    printf("%d%d%d %d%d%d\n", A[1], A[2], A[0], A[2], A[0], A[1]);

    return 0;

}
