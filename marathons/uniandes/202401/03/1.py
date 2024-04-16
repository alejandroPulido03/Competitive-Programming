while (True):
    try:
        x = input()
    except EOFError:
        break
    step, mod = map(int, x.split())

    s = 0
    num = 1
    for i in range(1, mod):
        a = (s + step) % mod
        if a == 0:
            break
        s = a
        num += 1
    
    st = str(step).rjust(10) + str(mod).rjust(10) + " "* 4
    st += "Good Choice" if num == mod else "Bad Choice"
    print(st + "\n")
