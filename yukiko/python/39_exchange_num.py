N = list(map(int, input()))
n_size = len(N)

for i in range(n_size - 1):
    back_max = max(N[i+1:])
    if N[i] < back_max:
        for j in reversed(range(n_size)):
            if N[j] == back_max:
                N[i], N[j] = N[j], N[i]
                break
        break

print("".join(map(str, N)))
