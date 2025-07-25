timesTable = [[i * j for i in range(1, 10)] for j in range(1, 10)]

X = int(input())

total = 0
for i in range(1, 10):
    for j in range(1, 10):
        if timesTable[i - 1][j - 1] != X:
            total += timesTable[i - 1][j - 1]

print(total)
