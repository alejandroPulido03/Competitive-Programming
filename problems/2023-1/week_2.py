""" def do(value):
    denominations = [100, 50, 10, 5, 2, 1]
    num_of_bills = 0
    while(value > 0):
        for i in denominations:
            while(value - i >= 0):
                value -= i
                num_of_bills += 1
                
    print(num_of_bills)

for i in range(int(input(''))):
    do(int(input(''))) """

""" s, n = [int(i) for i in input('').split(' ')]
isPossible = True
matches = []

for i in range(n):
    x, y = [int(i) for i in input('').split(' ')]
    matches.append([x,y])

matches.sort(key=lambda n: n[0])
for i in matches:
    if s > i[0]:
        s += i[1]
    else:
        isPossible = False

print('YES' if isPossible else 'NO') """

for i in range(int(input(''))):
    cards, joker_cards, players = [int(i) for i in input('').split(' ')]

    cards_per_player = cards // players
    plain_cards = cards - joker_cards
    best_player = min(cards, joker_cards)
    rest_of_jokers = joker_cards - best_player

    n = rest_of_jokers // players if rest_of_jokers % players == 0 else rest_of_jokers //players + 1

    