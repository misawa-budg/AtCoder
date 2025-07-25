#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char AB, AC, BC;
    scanf("%c %c %c", &AB, &AC, &BC);
    int order[3] = {0, 0, 0};

    (AB == '<') ? order[1]++:order[0]++;
    (AC == '<') ? order[2]++:order[0]++;
    (BC == '<') ? order[2]++:order[1]++;

    for(int i = 0; i < 3; i++) {
        if(order[i] == 1) {
            (i == 0) ? printf("A\n") : (i == 1)? printf("B\n") : printf("C\n");
            break;
        }
    }
}
