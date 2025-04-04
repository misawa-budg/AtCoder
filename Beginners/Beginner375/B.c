#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    int xpos = 0, ypos = 0;
    double cost = 0;
    for(int i = 0; i < N; i++) {
        int X, Y;
        scanf("%d %d",  &X, &Y);
        cost += sqrt(pow(xpos-X, 2) + pow(ypos-Y, 2));
        xpos = X; ypos = Y;
    }
    cost += sqrt(pow(xpos, 2) + pow(ypos, 2));

    printf("%.10f\n", cost);

    return 0;

}
