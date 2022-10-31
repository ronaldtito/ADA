from operator import sub
import subprocess
import os
import numpy as np
import matplotlib.pyplot as plt

data, temp = os.pipe()
os.write(temp,bytes('1\n','utf-8'))
#----Horse----
run_horse = subprocess.Popen(['horse.exe'],stdout=subprocess.PIPE)
horse = run_horse.communicate()[0]
horse = horse.split()
run_horse.kill()
horse_f = []
g = 1
for i in horse:
    horse_f.append((g,float(i.decode())))
    g+=1
horseA = sorted(horse_f,key= lambda x:x[1])

print(horseA)


#----QQuenn----
run_queen = subprocess.Popen(['nqueens.exe'],stdout=subprocess.PIPE)
queen = run_queen.communicate()[0]
queen = queen.split()
run_queen.kill()
queen_f = []
g = 1
for i in queen:
    queen_f.append((g,float(i.decode())))
    g+=1
queenA = sorted(queen_f,key= lambda x:x[1])

print(queenA)
#-----Puzzle------
run_puzzle = subprocess.Popen(['puzzle.exe'],stdout=subprocess.PIPE)
puzzle = run_puzzle.communicate()[0]
puzzle = puzzle.split()
run_puzzle.kill()
puzzle_f = []
g = 1
for i in puzzle:
    puzzle_f.append((g,float(i.decode())))
    g+=1
puzzleA = sorted(puzzle_f,key= lambda x:x[1])

print(puzzleA)

grupos = 3
y = np.arange(1,grupos+1)

horsetime =[]
for i in horse_f:
    horsetime.append(i[1])

queentime =[]
for i in queen_f:
    queentime.append(i[1])

puzzletime=[]
for i in puzzle_f:
    puzzletime.append(i[1])

horsetime1 = np.array(horsetime)
queentime1 = np.array(queentime)
puzzletime1 = np.array(puzzletime)

fig, ax = plt.subplots()
ax.barh(y, horsetime1, label= 'Horse')
ax.barh(y, queentime1, left = horsetime1, label= 'Nqueens')
ax.barh(y, puzzletime1, left= queentime1 + horsetime1, label= 'Puzzle')

ax.legend()

plt.show()
