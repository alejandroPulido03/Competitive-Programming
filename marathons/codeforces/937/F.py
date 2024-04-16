
def solve(head):
    if head == 2:
        if a > 0:
            a -=1
            solve(2)
        if a > 0:
            a -=1
            solve(2)
    if head == 1:
        pass

for _ in range(int(input())):
    a,b,c = map(int, input().split())
    
