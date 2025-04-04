N = int(input())
result = [['.' for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j in range(N):
        layer = min(i, j, N-1-i, N-1-j)
        if layer % 2 == 0:
            result[i][j] = '#'
        else:
            result[i][j] = '.'

for i in range(N):
    for j in range(N):
        print(result[i][j], end='')
    print()
