#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int hand[N];
    for(int i = 0; i < N; i++) {
        hand[i] = -1;
    }

    int Lpos = 0, Rpos = 1;
    hand[Lpos] = 0; hand[Rpos] = 1;

    int cost = 0;

    for(int i = 0; i < Q; i++) {
        char H;
        int T;
        int reverse = 0;
        scanf(" %c %d", &H, &T);
        T--;
        if(H == 'R') {
            int steps = (T >= Rpos) ? T - Rpos : N - Rpos + T;
            for(int k = 0; k < steps; k++) {
                int j = (Rpos + k) % N;
                if(hand[j] == 0) {
                    reverse = 1;
                    break;
                }
            }

            if(reverse) {
                cost += (Rpos - T < 0) ? Rpos - T + N : Rpos - T;
            } else {
                cost += (T - Rpos < 0) ? T - Rpos + N : T - Rpos;
            }

            hand[Rpos] = -1; hand[T] = 1;
            Rpos = T;

        } else {
            int steps = (T >= Lpos) ? T - Lpos : N - Lpos + T;
            for(int k = 0; k < steps; k++) {
                int j = (Lpos + k) % N;
                if(hand[j] == 1) {
                    reverse = 1;
                    break;
                }
            }


            if(reverse) {
                cost += (Lpos - T < 0) ? Lpos - T + N : Lpos - T;
            } else {
                cost += (T - Lpos < 0) ? T - Lpos + N : T - Lpos;
            }

            hand[Lpos] = -1; hand[T] = 0;
            Lpos = T;
        }

    }

    printf("%d\n", cost);

    return 0;

}
