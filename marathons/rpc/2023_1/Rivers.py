import math

a = input()

l = a.split("1")
sum = 0
for i in l:
    sum = max(math.ceil(len(i) / 2), sum)

print(sum)
