#include <stdio.h>
#include <string.h>

#define MAXN 200005

char S[MAXN];
int count[26];
long long positions[26][MAXN];
long long prefix_sum[MAXN];

int main() {
    scanf("%s", S);
    int N = strlen(S);

    // 各文字の出現位置を記録（1-based indexing）
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'A';
        positions[c][count[c]++] = i + 1; // 1-based indexingに変更
    }

    long long total_triplets = 0;


    for (int c = 0; c < 26; c++) {
        int m = count[c];
        if (m < 2) continue;


        prefix_sum[0] = positions[c][0];
        for (int i = 1; i < m; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + positions[c][i];
        }

        long long total_sum = prefix_sum[m - 1];

        for (int i = 0; i < m - 1; i++) {
            long long num_positions = m - i - 1;
            long long suffix_sum = total_sum - prefix_sum[i];

            long long sum_k_minus_i = suffix_sum - positions[c][i] * num_positions;
            long long num_triplets = sum_k_minus_i - num_positions;

            if (num_triplets > 0) {
                total_triplets += num_triplets;
            }
        }
    }

    printf("%lld\n", total_triplets);

    return 0;
}
