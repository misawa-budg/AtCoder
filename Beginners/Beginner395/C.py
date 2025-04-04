N = int(input())
A = list(map(int, input().split()))
previous_index = [-1] * (10 ** 6 + 1)
ans = float('inf')

for i in range(N):
    if previous_index[A[i]] != -1:
        ans = min(ans, i - previous_index[A[i]] + 1)
    previous_index[A[i]] = i

if ans == float('inf'):
    print(-1)
else:
    print(ans)
