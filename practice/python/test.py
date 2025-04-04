N, K = map(int, input().split())

A = list()
cumulative_sum = list()
cumulative_sum.append(int(input()))
for i in range(N-1):
    cumulative_sum.append(cumulative_sum[i] + int(input()))

for i in range(K):
    index = int(input())
    print(cumulative_sum[index-1])
