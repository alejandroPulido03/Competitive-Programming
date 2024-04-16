import math

while(True):
    try:
        n = int(input())
    except EOFError:
        break
    
    for i in range(1, n + 1):
        a = n + i**2
        print(i, " ", a)
        
            
