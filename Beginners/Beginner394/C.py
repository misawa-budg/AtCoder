S = input()
S_list = list(S)
i = 0
while i < len(S_list) - 1:
    if S_list[i] == 'W' and S_list[i+1] == 'A':
        S_list[i] = 'A'
        S_list[i+1] = 'C'
        i = max(i - 1, 0)
    else:
        i += 1

result = "".join(S_list)
print(result)
