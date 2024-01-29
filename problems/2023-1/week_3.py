numOfCards, queries = list(map(int, input().split(' ')))
cards = list(map(int, input().split(' ')))
queries = list(map(int, input().split(' ')))

first_left = {}

for i in range(len(cards)):
    if not cards[i] in first_left:
        first_left[cards[i]] = i + 1

for i in queries:
    print(first_left[i])
    first_left[i] = 1


""" numOfVertex = int(input())

tree = [[]]
for i in range(numOfVertex - 1):
    v = int(input())
    tree[v - 1].append(len(tree) + 1)
    tree.append([])


vertex = 1

isSpruce = True
def spruce(v):
    leafs = 0
    for i in tree[v]:
        if not tree[i - 1]:
            leafs += 1
        else:
            spruce(i - 1)
    if leafs < 3:
        global isSpruce 
        isSpruce = False

spruce(0)
print('Yes' if isSpruce else 'No') """

""" def solve(trs, r):
    tr = {}
    for i in range(r):
        a,b,c = list(map(int, input().split(' ')))
        if not a in tr:
            tr[a] = []
        if not c in tr:
            tr[a] = c
            



for _ in int(input()):
    trSize, rest = list(map(int, input().split(' ')))
    solve(trSize, rest) """