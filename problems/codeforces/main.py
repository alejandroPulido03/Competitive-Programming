l = int(input())
cut_prices = [0] * (l + 1)
dp = [float("-inf")] * (l + 1)

cut_prices[1:] = map(int, input().split())

dp[1] = cut_prices[1]
for i in range(2, l + 1):
    for j in range(1, i):
        dp[i] = max(dp[i], dp[j] + dp[i - j], cut_prices[i])

print(dp[l])