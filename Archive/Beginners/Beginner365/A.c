#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int Y;
    scanf("%d", &Y);

    if(Y%4 != 0 || (Y%100==0 && Y%400!=0)) {
        printf("365\n");
    } else {
        printf("366\n");
    }


    return 0;
}
