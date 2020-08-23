from guizero import App, Text, Combo, PushButton
from random import randint

def play_game_def():
	player_msg.value = "Player Chose: " + player_choice.value

	chosen = randint(1,3)
	if chosen==1:
		computer = 'Rock'
	elif chosen ==2:
		computer = 'Paper'
	else:
		computer = 'Scissors'
	computer_msg.value = "Computer Chose: " + computer

	if player_choice.value==computer:
		final_msg.value = 'DRAW'
	elif player_choice.value =='Rock' and computer =='Scissors':
		final_msg.value = 'Player WINS!'
	elif player_choice.value =='Rock' and computer =='Paper':
		final_msg.value = 'Player LOSS'
	elif player_choice.value =='Paper' and computer =='Rock':
		final_msg.value = 'Player WINS!'
	elif player_choice.value =='Paper' and computer =='Scissors':
		final_msg.value = 'Player LOSS'
	elif player_choice.value =='Scissors' and computer =='Paper':
		final_msg.value = 'Player WINS!'
	elif player_choice.value =='Scissors' and computer =='Rock':
		final_msg.value = 'Player LOSS'

app = App(title="Python Rock Paper Scissors",width=600, height=400, layout="grid")

welcome_msg = Text(app, text="Welcome to Rock Paper Scissors", grid=[0,0], align="left")
welcome_msg1 = Text(app, text="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", grid=[0,1], align="left")
player_choice = Combo(app, options=["Rock","Paper", "Scissors"], grid=[1,3], align="left")
player_choice_text = Text(app, text="Player Choice: ", grid=[0,3], align="left", color='blue')
player_msg = Text(app, text="", grid=[0,6], align="left", color='blue')
computer_msg = Text(app, text="", grid=[0,7], align="left", color='red')
final_msg = Text(app, text="", grid=[0,8], align="left", color='green')
play_game = PushButton(app, command=play_game_def, text="PLAY GAME", grid=[1,5],align="left")

app.display()