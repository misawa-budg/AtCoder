S = input()
stack = []
pairs = {')': '(', ']': '[', '>': '<'}

for ch in S:
    if ch in "([<":
        stack.append(ch)
    else:
        if stack and stack[-1] == pairs[ch]:
            stack.pop()
        else:
            print('No')
            break
else:
    print('Yes' if not stack else 'No')
