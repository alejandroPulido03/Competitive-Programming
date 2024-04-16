t = int(input())

def get_diff(a_n):
    for i in range(len(a_n) - 1):
        if a_n[i] == 0 and a_n[i + 1] == 1:
            return i, i + 1
    return -1, -1

for _ in range(t):
    n = int(input())
    a_n = list(map(int, input().split()))
    if a_n[n - 1] == 0:
        print(*[i for i in range(1, n + 2)])
    elif a_n[0] == 1:
        print(*([n + 1] + [i for i in range(1, n + 1)]))
    else:
        f, j = get_diff(a_n)
        if f == -1:
            print(-1)
        else:
            print(*([i for i in range(1, f + 2)] + [n + 1] + [i for i in range(j + 1, n + 1)]))
