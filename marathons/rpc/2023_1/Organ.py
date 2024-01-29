import math

y = int(input())
n = y
factorials = [math.factorial(i) for i in range(10)]
x = 0
res = ""
for i in range(len(factorials) -1, -1, -1):
    while(y - factorials[i] >= 0 and y > 0):
        y -= factorials[i]
        res += str(i)
res = res[::-1]
if res == "1":
    res = "0"

print(res[0] + res[1:].replace("1", "0"))



