N = int(input())
A = list(map(int, input().split()))

ans = True
for i in range(N-1):
    if A[i] >= A[i+1]:
        ans = False
        break

if ans: print('Yes')
else: print('No')
