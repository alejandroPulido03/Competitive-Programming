n = int(input())

p = list(map(int, input().split()))

def dp(mi, mj, i):
    if i == n:
        return abs(mi - mj)
    return(min(dp(mi - p[i], mj + p[i], i + 1), dp(mi, mj, i + 1)))

print(dp(sum(p), 0, 0))

