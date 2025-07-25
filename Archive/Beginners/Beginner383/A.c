#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {

    int N;
    scanf("%d", &N);

    int amount = 0;
    int prevTime = 0;
    for (int i = 0; i < N; i++) {
        int time, num;
        scanf("%d %d", &time, &num);

        amount -= time - prevTime;
        if (amount < 0) {
            amount = 0;
        }
        amount += num;
        prevTime = time;
    }

    printf("%d\n", amount);
    return 0;
}
