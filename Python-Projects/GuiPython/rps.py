from random import randint



while True:

	player = input('rock (r), paper (p), or scissors (s)? ')

	print (player, 'vs', end=' ')

	chosen = randint(1,3)
	#print (chosen)

	if chosen==1:
		computer= 'r'
	elif chosen ==2:
		computer = 'p'
	else:
		computer = 's'

	print (computer)

	if player==computer:
		print('DRAW')
	elif player =='r' and computer =='s':
		print('Player WINS!')
	elif player =='r' and computer =='p':
		print('Computer WINS!')
	elif player =='p' and computer =='r':
		print('Player WINS!')
	elif player =='p' and computer =='s':
		print('Computer WINS!')
	elif player =='s' and computer =='p':
		print('Player WINS!')
	elif player =='s' and computer =='r':
		print('Computer WINS!')

	replay = input('PLAY AGAIN? (y/n)')

	if replay=='n':
		break

	print("~~~~\n\n")
