from random import randint

def roll():
    n = randint(1,6)
    total = n
    while n == 6:
        n = randint(1,6)
        total += n
    return total

def position_index(index):
    if index < 10:
        return 2*(index + 2)
    return 3*(index - 1) - 2

def print_on_position(size, posA, posB):
    planA = 1
    planB = 3
    if posA != 0:
        planA = position_index (posA)
    if posB != 0:
        planB = position_index (posB)
    i = 1

    if size < 10:
        i = 2

    if posA == size:
        planA += i
    elif posB == size:
        planB += i

    index_range = position_index(size)
    for i in range (0, index_range + 5):
        if i == planA:
            print("A", end ="")
        elif i == planB:
            print("B", end ="")
        else:
            print(" ", end ="")
    print()

def print_status(size, posA, posB):
    print()
    print_on_position(size, posA, posB)
    print("start ", end="")
    for i in range(1, size):
        print(i, "", end="")
    print("finish")

def print_move(who, moves, position):
    print(who, "rolls ", end ="")
    for i in range(0, moves//6):
        print(6, end=" ")
    print(moves%6, "and", end =" ")
    if moves == 0:
        print("does not move (rolled too much).")
    else:
        print("advances",moves ,"spaces to position" , position, end = "")
        print ('.')
        
def kick(name, output):
    if output:
        if name == "A":
            print("Player B kicks out player A!")
        else:
            print("Player A kicks out player B!")
    return 0;

def play_race(size, output):
    posA = 0
    posB = 0
    turns = 0
    move = 0
    if output:
        print_status(size, posA, posB)
    while posB != size:
        move = roll();
        if move + posA > size:
            move = 0;
        posA += move
        if posA == posB:
            posB = kick ("B", output)
        if output:
            print_move("A", move, posA)                
            print_status(size, posA, posB)
        turns += 1
        
        if posA == size:
            break
        
        move = roll();
        if move + posB > size:
            move = 0;
        posB += move
        if posA == posB:
            posA = kick ("A", output)
        if output:
            print_move("B", move, posB)                  
            print_status(size, posA, posB)          
        turns += 1
        
    winner = "A"
    if posB == size:
        winner = "B"
    if output:
        print ("Player", winner, "wins!")
        print ("The game lasted for", turns, "turns.", end="")
    else:
        return turns
        
def race_analysis(size, count):
    length_sum = 0
    wins_A = 0
    wins_B = 0
    
    for i in range(0, count):
        length = play_race (size, False)
        length_sum += length
        if length % 2 == 1:
            wins_A += 1
        else:
            wins_B += 1
    print ("Average race length:", length_sum / count)
    print ("A's success rate:", 100 * wins_A / count, "%")
    print ("B's success rate:", 100 * wins_B / count, "%")
