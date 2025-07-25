x = int(input())

factorial = 1
for i in range(1, x + 1):
    factorial *= i
    if factorial == x:
        print(i)
        break
else:
    print(-1)
