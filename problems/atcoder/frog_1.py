n, k = map(int, input().split())
vals = list(map(int, input().split()))

dp = [float("inf") for _ in range(n)]

dp[0] = 0
dp[1] = abs(vals[0] - vals[1])
for i in range(2, len(dp)):
    for j in range(1, min(i, k) + 1):
        dp[i] = min(dp[i - j] + abs(vals[i] - vals[i - j]), dp[i])


print(dp[-1])
