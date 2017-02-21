K = int(input())
dp = [0 for i in range(25)]
dp[K - 1] = 1

for i in reversed(range(K-1)):
    for j in range(1, 7):
        dp[i] += dp[i + j] / 6.0

    dp[i] += 1

print(dp[0])
