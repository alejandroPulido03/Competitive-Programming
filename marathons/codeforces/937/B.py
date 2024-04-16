for _ in range(int(input())):
    n = int(input())
    turn = True
    line = False
    for i in range(1, 2*n + 1, 2):
        block = ""
        line = not line
        turn = not line
        for j in range(1, 2*n + 1, 2):
            if not turn:
                block += "##"
            else:
                block += ".."
            turn = not turn
        print(block)
        print(block)
