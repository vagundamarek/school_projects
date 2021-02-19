from random import randint

def new_game(rows, cols):
    out = []
    for row in range (0, rows):
        x = []
        for col in range (0, cols):
            x.append(' ')
        out.append(x)
    return out

def put(game, stone, row, col):
    cols = len (game[0])
    rows = len (game)

    for x in range (row - 1, row +2):
        if (x >= 0 and x < rows):
            for y in range (col-1, col +2):
                if (y >= 0 and y < cols):
                    game[x][y] = '*'
    game[row][col] = stone


def index_row(size):
    #row with numbers
    print ("    ", end='')
    for i in range (0, size):
        print ('', i, '', end='')
        if (i < 10):
            print (' ', end='')
    print ('')
        
def line(size):
    #upper border of plan    
    print ("   +", end='')
    for i in range (0, size):
        print("---+", end='')
    print ('')

def init_row(number):
    if number < 10:
        print (' ', end='')
    print (number, "|", end='')
    
def draw_game(game):
    cols = len (game[0])
    rows = len (game)

    index_row(cols)
    line(cols)
    
    for x in range (0, rows):
        init_row(x)
        for y in range (0, cols):
            print ('', game[x][y], '|', end='')
        print('')
        line(cols)
    print('')

def is_over(game):
    cols = len (game[0])
    rows = len (game)
    for x in range (0, rows):
        for y in range (0, cols):
            if game[x][y] == ' ':
                return False
    return True

def distance(x,y):
    if (abs(x[0]-y[0])>abs(x[1]-y[1])):
        return abs(x[0]-y[0])
    else:
        return abs(x[1]-y[1])

def spaces_create(game):
    cols = len (game[0])
    rows = len (game)
    
    spaces=[]
    for x in range (0, rows):
        for y in range (0, cols):
            if (game[x][y]) == ' ':
                spaces.append((x,y))
    return spaces

def distance_big (spaces):
    for i in range (0, len(spaces)):
        for j in range (i+1, len(spaces)):
            if distance(spaces[i], spaces[j])>3:
                return True
    return False

def sector (spaces, p):
    for x in spaces:
        flag = True
        for y in spaces:
            if distance(x,y)>1:
                flag = False
        if flag:
            p[0] = x[0]
            p[1] = x[1]
            return True
    return False
    
def win(game, p):
    cols = len (game[0])
    rows = len (game)
    
    spaces = spaces_create(game)

    if distance_big(spaces):
        return False
    return sector(spaces, p)
    
def random (game, p):
    cols = len (game[0])
    rows = len (game)
    
    p[0] = randint(0, rows -1)
    p[1] = randint(0, cols -1)

    while game[p[0]][p[1]] != ' ':
        p[0] = randint(0, rows -1)
        p[1] = randint(0, cols -1)
        
def strategy(game):
    p = [0,0]
    if win(game, p) == False:
        random (game, p)
    return (p[0], p[1])

def turn_PC(g):
    point = strategy(g)
    draw_game(g)
    put(g, 'X', point[0], point[1])
    print ("Na tahu je počítač.")
    print ("Počítač hraje na pozici (řádek", point[0], ',sloupec', point[1], ')')

def load_str(parameter):
     x = input()
     while x.isdigit()== False:
        print ("Nevalidní znak.")
        print ("Zadej " + parameter + ': ', end='')
        x = input()
     return x
    
def out_of_range (x, limit):
    if (x >=0 and x < limit):
        return False;
    return True

def load_val(parameter, limit):
    x = int(load_str(parameter))
    
    while out_of_range(x, limit):
        print ("Nevalidní index.")
        print ("Zadej " + parameter + ': ', end='')
        x = int(load_str(parameter))
    return x

def turn_human(g):
    draw_game(g)
    print ("Na tahu je člověk.")
    
    print ("Zadej řádek: ", end='')
    x = load_val("řádek", len(g))
    print ("Zadej sloupec: ", end='')
    y = load_val("sloupec", len(g[0]))
    while g[x][y] != ' ':
        print ("Neplatná pozice.")
        
        print ("Zadej řádek: ", end='')
        x = load_val("řádek", len(g))
        print ("Zadej sloupec: ", end='')
        y = load_val("sloupec", len(g[0]))
    
    put(g, 'O', x, y)    

def play_obstruction(rows, cols, human_starts=True):
    g = new_game(rows, cols)
    human = human_starts

    while is_over(g)==False:
        if human:
            turn_human(g)
            human = False
        else:
            turn_PC(g)
            human = True
        print('')
            
    draw_game(g)        
    if (human):
        print ("Prohrál jsi.")
    else:
        print ("Vyhrál jsi.")
    
        
    
