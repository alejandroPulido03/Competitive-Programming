for _ in range(int(input())):
    a, b = map(int, input().split(":"))
    print(f"{0 if (a % 12) < 10 and a != 0 and a != 12 else ''}{a % 12 if a != 0 and a != 12 else 12}:{0 if b < 10 else ''}{b} {('PM' if a > 11 else 'AM')}")