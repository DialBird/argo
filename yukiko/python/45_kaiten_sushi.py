N = int(input())
sushi = [int(i) for i in input().split()]
dp = [0]*N
dp[N-1] = sushi[N-1]
dp[N-2] = max(sushi[N-2:])

for i in reversed(range(N-2)):
    dp[i] = max(sushi[i] + dp[i+2], dp[i+1])

print(dp[0])
