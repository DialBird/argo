K = int(input())

E = [0]*(20+5)
E[K-1] = 1

for i in reversed(range(0,K-1)):
    for j in range(6):
        E[i] += E[i + j + 1] / 6
    E[i] += 1

print(E[0])
