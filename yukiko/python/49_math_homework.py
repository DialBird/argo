S = list(input())

scaned = []
next_int = []

for c in S:
    if c == '*':
        scaned.append(int("".join(next_int)))
        next_int = []
        scaned.append(c)
    elif c == '+':
        scaned.append(int("".join(next_int)))
        next_int = []
        scaned.append(c)
    else:
        next_int.append(c)

scaned.append(int("".join(next_int)))

ans = scaned[0]
for i in range(1, len(scaned), 2):
    if scaned[i] == '*':
        ans += scaned[i+1]
    elif scaned[i] == '+':
        ans *= scaned[i+1]
    
print(ans)
