#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    int cards[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &cards[i]);
    }
    int fullhouse = 0;
    int count1 = 0, count2 = 0;
    int card1 = cards[0], card2 = -1;

    for (int i = 0; i < 4; i++) {
        if (cards[i] != card1) {
            card2 = cards[i];
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (card1 == cards[i]) {
            count1++;
        } else if (card2 == cards[i]) {
            count2++;
        }
    }

    if (count1 == 2 && count2 == 2) {
        fullhouse = 1;
    } else if (count1 == 3 && count2 == 1) {
        fullhouse = 1;
    } else if (count1 == 1 && count2 == 3) {
        fullhouse = 1;
    }

    if (fullhouse) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }



    return 0;
}
