#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int a1, int b1, int a2, int b2) {
    return !(b1 <= a2 || b2 <= a1);
}

int main() {
    int points[12];

    for(int i = 0; i < 12; i++) {
        scanf("%d", &points[i]);
    }

    if(f(points[0], points[3], points[6], points[9]) &&
       f(points[1], points[4], points[7], points[10]) &&
       f(points[2], points[5], points[8], points[11])) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
