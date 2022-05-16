import random
ans_list = [4,5,4,7]
check_list = {}
# for i in range(4):
#     r = random.randrange(0, 9)
#     ans_list.append(r)

print(f"answer is={ans_list}")

endgame = False
while not endgame:
    AB = {'A': 0, 'B': 0}
    input_list = []
    inp = input(f"guss a number")
    for a in inp:
        input_list.append(int(a))
    for i in range(len(input_list)):
        print(f"{input_list[i]}", end=' ')
    print("")
    save = 10
    for i in range(4):
        if input_list[i] == ans_list[i]:
            AB['A'] += 1
            input_list[i] = save
            save += 1
            ans_list[i] = save
            save += 1
    for j in range(4):
        for k in range(4):
            if input_list[j] == ans_list[k]:
                AB['B'] += 1
                input_list[j] = save
                save += 1
                ans_list[k] = save
                save += 1
    for x, y in AB.items():
        print(f"{y} {x}", end=' ')
    print("")
    if AB['A'] == 4:
        endgame = True
        print(f"You guess it right!")
    else:
        print(f"Try again!")
