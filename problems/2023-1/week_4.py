from sys import stdin, stdout

N, W = list(map(int, stdin.readline().split(' ')))
wnList = [list(map(int, stdin.readline().split(' '))) for _ in range(N)]

dp = [[-1 for _ in range(W + 1)] for _ in range(N + 1)]

def solve(W, val, i):
    if W == 0 or i < 0:
        return 0
    else:
        w, n = wnList[i]
        if dp[i][W] != -1:
            return dp[i][W]
        else:
            if w <= W:
                dp[i][W] = max(n + solve(W - w, val, i - 1), solve(W, val, i - 1)) 
                return dp[i][W]
            else:
                dp[i][W] = solve(W, val, i - 1)
                return dp[i][W]

stdout.write(str(solve(W, 0, len(wnList) - 1)))
