#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define MAXP 2000000

static int sieve[MAXP+1];
static int primes[MAXP];
static int prime_count = 0;

int main() {
    long long N;
    scanf("%" SCNd64, &N);
    {
        memset(sieve, 0, sizeof(sieve));
        sieve[0] = 1; sieve[1] = 1;
        for (int i = 2; i*i <= MAXP; i++) {
            if (!sieve[i]) {
                for (int j = i*i; j <= MAXP; j += i) {
                    sieve[j] = 1;
                }
            }
        }
        for (int i = 2; i <= MAXP; i++) {
            if (!sieve[i]) primes[prime_count++] = i;
        }
    }

    long long count_pattern1 = 0;
    {
        long double N8 = powl((long double)N, 1.0L/8.0L);
        for (int i = 0; i < prime_count; i++) {
            long long p = primes[i];
            if (p > (long long)floor(N8)) break;
            __int128 p8 = 1;
            for (int k = 0; k < 8; k++) p8 = p8 * p;
            if (p8 <= (__int128)N) {
                count_pattern1++;
            } else {
                break;
            }
        }
    }

    long long count_pattern2 = 0;
    {
        for (int i = 0; i < prime_count; i++) {
            long long p = primes[i];
            __int128 p2 = (__int128)p * p;
            if (p2 > N) break;

            long long limit = (long long)(floor((long double)(N / (long double)p2)));
            long double q_limit = floor(sqrtl((long double)limit));
            if (q_limit < p+1) continue;

            int left = i+1, right = prime_count-1;
            int pos = i;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (primes[mid] <= (long long)q_limit) {
                    pos = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (pos > i) {
                count_pattern2 += (pos - (i+1) + 1);
            }
        }
    }

    printf("%" PRId64 "\n", count_pattern1 + count_pattern2);

    return 0;
}
