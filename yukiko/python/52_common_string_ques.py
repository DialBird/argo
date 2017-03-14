S = list(input())

pattern = []
results = set([])

def add(rest):
    if len(rest) == 1:
        pattern.append(rest[0])
        results.add("".join(pattern))
        pattern.pop(-1)
        return

    pattern.append(rest[0])
    add(rest[1:])
    pattern.pop(-1)
    pattern.append(rest[-1])
    add(rest[:-1])
    pattern.pop(-1)

add(S)

print(len(results))
