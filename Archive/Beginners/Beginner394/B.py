N = int(input())
strings = []

for i in range(N):
    strings.append(input())

strings.sort(key=len)

for string in strings:
    print(string, end="")
print()
