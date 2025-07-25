#include <stdio.h>
#include <stdlib.h>

#define MAX_K 200000

// グローバル配列として宣言
int A_arr[200005];
int B_arr[200005];
int min_i_arr[200005];
int eaten_arr[200005];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A_arr[i]);
    }
    for (int j = 1; j <= M; j++) {
        scanf("%d", &B_arr[j]);
    }

    for (int k = 0; k <= MAX_K; k++) {
        min_i_arr[k] = N + 1;
    }


    for (int i = 1; i <= N; i++) {
        if (A_arr[i] <= MAX_K) {
            if (i < min_i_arr[A_arr[i]]) {
                min_i_arr[A_arr[i]] = i;
            }
        }
    }


    for (int k = 1; k <= MAX_K; k++) {
        if (min_i_arr[k] > min_i_arr[k - 1]) {
            min_i_arr[k] = min_i_arr[k - 1];
        }
    }

    for (int j = 1; j <= M; j++) {
        int B = B_arr[j];
        if (B > MAX_K) B = MAX_K;
        if (min_i_arr[B] <= N) {
            eaten_arr[j] = min_i_arr[B];
        } else {
            eaten_arr[j] = -1;
        }
    }

    for (int j = 1; j <= M; j++) {
        printf("%d\n", eaten_arr[j]);
    }

    return 0;
}
