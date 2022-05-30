# -*- coding: utf-8 -*-
import random


class Boss:
    def __init__(self):
        self.name = "Boss"
        self.HP = 500
        self.skill = {1: ("招式一", 150), 2: ("招式二", 100), 3: ("招式三", 200), 4: ("招式四", 50)}

    def attack(self, player):
        boss_damage = self.skill[random.randrange(1, 5, 1)]
        player_damaged = player[random.randrange(0, 2, 1)]
        player_damaged.HP -= boss_damage[1]
        if player_damaged.HP < 0:
            player_damaged.HP = 0
        print(f"{self.name}對{player_damaged.name}使出了{boss_damage[0]}造成了{boss_damage[1]}傷害")


class P1:
    def __init__(self, name):
        self.name = name
        self.HP = 300
        self.attack = 100
        self.step = 0

    def update(self):
        if self.step == 1:
            self.Attack()
        else:
            self.heal()

    def Attack(self):
        global boss
        boss.HP -= self.attack
        if boss.HP < 0:
            boss.HP = 0
        print(f"{self.name:<10}對{boss.name}造成{self.attack}傷害")

    def heal(self):
        self.HP += 100
        print(f"{self.name:<10}回復了些許生命")
        if self.HP > 300:
            self.HP = 300


class P2:

    def __init__(self, name):
        self.name = name
        self.HP = 250
        self.attack = 150
        self.step = 0

    def update(self):
        if self.step == 1:
            self.Attack()
        else:
            self.heal()

    def Attack(self):
        global boss
        boss.HP -= self.attack
        if boss.HP < 0:
            boss.HP = 0
        print(f"{self.name:<10}對{boss.name}造成{self.attack}傷害")

    def heal(self):
        self.HP += 100
        print(f"{self.name:<10}回復了些許生命")
        if self.HP > 250:
            self.HP = 250


boss = Boss()

name1 = input("p1's name:")
name2 = input("p2's name:")
player1 = P1(name1)
player2 = P2(name2)
print(f"Game start !\n{player1.name} and {player2.name} fight with Boss")


def print_data():
    print(f"{boss.name:<10}\t:HP:{boss.HP:<3} \tSkill:", end='')
    for skill, attack in boss.skill.values():
        print(f"{skill}({attack})", end='')
    print()
    print(f"{player1.name:<10} \t:HP:{player1.HP:<3} \tATK:{player1.attack:<3}")
    print(f"{player2.name:<10} \t:HP:{player2.HP:<3} \tATK:{player2.attack:<3}")
    print()


def boss_round():
    print("----------Boss的回合----------")
    print_data()
    boss.attack((player1, player2))


def player_round():
    print("\n----------你的回合----------")
    print_data()
    player1.step = int(input(f"{player1.name:<10}(1.attack 2.heal)"))
    player2.step = int(input(f"{player2.name:<10}(1.attack 2.heal)"))
    player1.update()
    player2.update()
    print()


while True:
    boss_round()
    if player1.HP == 0 or player2.HP == 0:
        break
    player_round()
    if boss.HP == 0:
        break

if boss.HP:
    print_data()
    print("You Lose")
else:
    print_data()
    print("You Win")
