from math import sqrt

N = int(input())

sqrt_n = int(sqrt(N))
cnt = 0

# 2で割れるだけ先に割る
while N % 2 == 0:
    N //= 2
    cnt += 1
    if cnt >= 3: break

# 3以上の奇数で確認する
if cnt < 3 and N != 1:
    for i in range(3, sqrt_n + 1, 2):
        if N == 1: break

        while N % i == 0:
            N //= i
            cnt += 1
            if cnt >= 3: break

if N != 1:
    cnt += 1

if cnt >= 3:
    print("YES")
else:
    print("NO")
