def knapsack(N, W, w, v):
    dp = [[0 for _ in range(W + 1)] for _ in range(N + 1)]
    
    for ni in range(N + 1):
        for wi in range(W + 1):
            if wi - w[ni] >= 0:
                dp[ni][wi] = max(dp[ni - 1][wi], v[ni] + dp[ni - 1][wi - w[ni]])
            else:
                dp[ni][wi] = dp[ni - 1][wi]

    return dp[N][W]
    

N, W = map(int, input().split(' '))

w, v = [], []
for _ in range(N):
    wi, vi = map(int, input().split(' '))
    w.append(wi)
    v.append(vi)


print(knapsack(N - 1, W, w, v))
