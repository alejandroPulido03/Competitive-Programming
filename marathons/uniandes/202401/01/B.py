n = int(input())

pn = list(map(lambda x: int(x) - 1, input().split()))

def hole_badges(a, pn):
    pa = a
    holed = set()
    while(pa not in holed):
        holed.add(pa)
        pa = pn[pa]
    return str(pa + 1)


a = []
for i in range(n):
    a.append(hole_badges(i, pn))
print(" ".join(a))

print("")