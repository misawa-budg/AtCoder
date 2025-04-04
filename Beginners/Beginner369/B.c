#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, pos[2] = {-1, -1};
    int sum = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char temp[2];
        int num;
        scanf("%d %s", &num, temp);
        if(strcmp(temp, "L") == 0) {
            if(pos[0] != -1) {
                sum += abs(pos[0] - num);
            }
            pos[0] = num;
        } else {
            if(pos[1] != -1) {
                sum += abs(pos[1] - num);
            }
            pos[1] = num;
        }
    }

    printf("%d\n", sum);
}
