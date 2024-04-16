n = int(input())

dp = [[0 for _ in range(3)] for _ in range(n)]

dp[0] = list(map(int, input().split()))

for i in range(1, n):
    a = list(map(int, input().split()))
    for j in range(3):
        dp[i][j] = max(dp[i - 1][(j - 1) % 3], dp[i - 1][(j + 1) % 3]) + a[j]

print(max(dp[-1]))