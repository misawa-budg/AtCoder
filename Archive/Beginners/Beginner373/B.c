#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[27];
    int sum = 0;
    scanf("%s", input);

    int pres, prev;
    for(int i = 0; i < 27; i++) {
        if(input[i] == 'A') {
            prev = i;
        }
    }

    for(int letter = 'B'; letter <= 'Z'; letter++) {
        int index = 0;
        while(index < 26) {
            if(input[index] == letter) {
                sum += abs(prev - index);
                prev = index;
                break;
            }
            index++;
        }
    }

    printf("%d\n", sum);

    return 0;
}
