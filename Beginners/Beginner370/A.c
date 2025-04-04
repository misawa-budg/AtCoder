#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int L, R;

    scanf("%d %d", &L, &R);

    if(!L&&!R || L&&R) {
        printf("Invalid\n");
    } else if(L) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;

}
