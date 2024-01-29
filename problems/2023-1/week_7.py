import sys

sys.setrecursionlimit(10**5)

n, w = map(int, input().split(' '))
n_list = [list(map(int, input().split(' '))) for _ in range(n)]

dp = [[-1 for _ in range(100)] for _ in range(10**5)]
def solve(w, i=0):
    if i == len(n_list) or w - n_list[i][0] < 0:
        dp[i][w] = 0
        return 0
    else:
        if dp[i][w] == -1:
            dp[i][w] = max(n_list[i][1] + solve(w-n_list[i][0],
                    i+1), solve(w, i+1))
    return dp[i][w]

print(solve(w))
