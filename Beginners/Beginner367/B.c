#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    scanf("%s", input);

    int len = strlen(input);

    int need = len;
    int period = 1;
    for(int i = len - 1; i >= 0; i--) {
        if(input[i] == '0' && period == 1) {
            need = i;
        } else if(input[i] == '.'){
            need = i;
            period = 0;
        } else {
            break;
        }
    }

    for(int i = 0; i < need; i++) {
        printf("%c", input[i]);
    }
    printf("\n");


    return 0;
}
