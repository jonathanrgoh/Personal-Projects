from  guizero import App, Text, PushButton, Picture
import time
import os
import random
import sys

def calc_hand(hand):
    non_aces = [c for c in hand if c != 'A']
    aces = [c for c in hand if c == 'A']

    sum = 0

    for card in non_aces:
        if card in 'JQK':
            sum += 10
        else:
            sum += int(card)

    for card in aces:
        if sum <= 10:
            sum += 11
        else:
            sum += 1

    return sum

def deal():
	p1=player[0]
	player_card1.text=str(player[0])
    


app = App(title="Python Black Jack", width=600, height=600, layout="grid")

dealing_msg = Text(app, text="BLACKJACK", grid=[0,0], align="left")
dealing_msg2 = Text(app, text="~~~~~~~~~", grid=[0,1], align="left")

#my_cat = Picture(app, image="title3.gif", grid=[3,2], align="left")

dealer_hand = Text(app, text="Dealer's Hand: ", grid=[0,3], align="left")
dealer_card1 = PushButton(app, text='', grid=[1,3],align="left")
dealer_card2 = PushButton(app, text='', grid=[2,3],align="left")

dealing_msg3 = Text(app, text="", grid=[0,4], align="left")

player_hand = Text(app, text="Player's Hand: ", grid=[0,5], align="left", color='blue')
player_card1 = PushButton(app, text='', grid=[1,5],align="left")
player_card2 = PushButton(app, text='', grid=[2,5],align="left")

deal_cards = PushButton(app, command='deal', text="DEAL", grid=[0,6],align="left")



cards = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A','2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A','2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A','2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A',]
random.shuffle(cards)

dealer = []
player = []

player.append(cards.pop())
dealer.append(cards.pop())
player.append(cards.pop())
dealer.append(cards.pop())

app.display()