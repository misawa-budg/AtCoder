#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;

    scanf("%d", &N);

    int before = 0;
    for(int i = 0; i < N; i++) {
        char input[6];
        scanf("%s", input);

        if(i != N - 1 && before == 1 && strcmp(input, "sweet")==0) {
            printf("No\n");
            return 0;
        } else if (strcmp(input, "sweet")==0) {
            before = 1;
        } else {
            before = 0;
        }

    }
    printf("Yes\n");

    return 0;
}
