def diff(a, b):
    count = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            count += 1
        if count > 1:
            return count
    return count

def solve():
    num = int(input())
    st = input()
    pattern = -1
    for i in range(1, num + 1):
        not_word = False
        failed = False
        for j in range(1, num, i):
            if st[0: i] != st[j: j + i]:
                if (failed or diff(st[0: i], st[j: j + i]) > 1):
                    not_word = True
                    break
                else:
                    failed = True
        if not not_word:
            pattern = i
            break
    print(pattern)
        

for _ in range(int(input())):
    solve()

