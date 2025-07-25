#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int N, C;
	int count = 0;
	scanf("%d %d", &N, &C);

	int prevT;
	scanf("%d", &prevT);
	count++;
	for(int i = 1; i < N; i++) {
		int T;
		scanf("%d", &T);
		if(T-prevT < C) {
			continue;
		} else {
			count++;
			prevT = T;
		}
	}

	printf("%d\n", count);

	return 0;
}
