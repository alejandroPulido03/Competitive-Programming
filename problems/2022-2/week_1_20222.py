# CodeForces - 466A 
""" n, m, a, b = map(int, input().split(' '))
print(min(n * a, n // m * b + min(n % m * b, (n - n // m * m) * a), int(n/m + 1) * b)) """

# CodeForces - 459A
""" x1, y1, x2, y2 = map(int, input().split(' '))
x3, x4, y3, y4 = 0,0,0,0
isPosible = True
if x1 == x2:
    x3 = x4 = abs(y1 - y2) + x1
    y3 = y1
    y4 = y2
elif y1 == y2:
    y3 = y4 = abs(x1 - x2) + y1
    x3 = x1
    x4 = x2
else:
    if abs(x1 - x2) != abs(y1 - y2):
        isPosible = False
    else:
        x3 = x1
        y3 = y2
        x4 = x2
        y4 = y1

print(f'{x3} {y3} {x4} {y4}' if isPosible else -1) """

# CodeForces - 1214C
""" n = int(input())
numOfOpen = 0
brks = list(input())
for brk in brks:
    numOfOpen += 1 if brk == '(' else -1
    if numOfOpen < -1:
        break

print('Yes' if 0 <= numOfOpen <= 1 and not(len(brks) % 2) else 'No') """

# CodeForces - 1428B 

def solve():
    n = int(input())
    grp = [[] for _ in range(n)]
    returned = 0

    cncts = list(input())
    for i in range(len(cncts)):
        if cncts[i] == "-":
            grp[i].append((i + 1) % n)
            grp[(i + 1) % n].append(i)
        elif cncts[i] == ">":
            grp[i].append((i + 1) % n)
        else:
            grp[(i + 1) % n].append(i)
    
    
    
    if(n == 2 and ((cncts[0] == ">" and cncts[1] == "<") or (cncts[1] == ">" and cncts[0] == "<"))):
        print(0)
    else:
        cnt_cmps = kosaraju(grp)

        for cpm in cnt_cmps:
            if len(cpm) > 1:
                returned += len(cpm)

        print(returned)

def kosaraju(grp):
    cnt_comps = []

    #Reverse graph (E+V)
    newGrp = [[] for i in range(len(grp))]
    for i in range(len(grp)):
        for j in range(len(grp[i])):
            newGrp[grp[i][j]].append(i)

    #DFS Reversed graph
    postorder = []
    visited = [0 for _ in range(len(newGrp))]

    for i in range(len(visited)):
         if visited[i] == 0:
             stack = [i]
             while(stack):
                 start = stack.pop()
                 if visited[start] == 0:
                     for son in newGrp[start]:
                         stack.append(son)

                     visited[start] = 1
                     postorder.append(start)

#    def dfsGr(start):
#        if visited[start] == 0:
#            visited[start] = 1
#            for son in newGrp[start]:
#                dfsGr(son)
#            postorder.append(start)
#
#    for i in range(len(visited)):
#        if visited[i] == 0:
#            dfsGr(i)  

    #DFS with postorder
    visited = [0 for _ in range(len(grp))]

    for i in postorder[::-1]:
        cnt_comps.append([])
        stack = [i]
        while(stack):
            start = stack.pop()
            if visited[start] == 0:
                visited[start] = 1
                for son in grp[start]:
                    stack.append(son)
                cnt_comps[-1].append(start)


    return cnt_comps
    


for _ in range(int(input())): 
    solve()

