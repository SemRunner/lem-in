#!python3
import sys
import os
import random as rnd

directions0 = ((-1, 0), (0, 1), (1, 0), (0, -1))
directions1 = ((-1, -1), (-1, 1), (1, -1), (1, 1))
directions2 = ((-2, -1), (-2, 1), (-1, 2), (1, 2), (2, -1), (2, 1), (-1, -2), (1, -2))
directions3 = ((-3, -2), (-3, 2), (-2, 3), (2, 3), (3, -2), (3, 2), (-2, -3), (2, -3))
directions4 = ((-4, -3), (-4, -2), (-4, -1), (-4, 1), (-4, 2), (-4, 3),
               (4, -3), (4, -2), (4, -1), (4, 1), (4, 2), (4, 3),
               (-3, 4), (-2, 4), (-1, 4), (1, 4), (2, 4), (3, 4),
               (-3, -4), (-2, -4), (-1, -4), (1, -4), (2, -4), (3, -4),
               (-4, -4), (-4, 4), (4, 4), (4, -4))

def print_usage():
    print(
    '''usage: python3 convert_fdf_to_lemin.py arg1 arg2 arg3 ... arg7 [arg8 arg9]
    this script convert map fdf to lemin anthill. it create file in folder of fdf file.
    
    arg1: map_name

    then enter parameters of anthill or put parameters in command line.
    parameters:
        arg2 - number of ants
        arg3, arg4 - (x, y) of start room
        arg5, arg6 - (x, y) of end room
        arg7 - type of connections:
            0 - only ortogonal
            1 - all ortogonal, start/end: diagonal
            2 - all ortogon, start/end: diagonal and radius 2
            3 - all ortogon, start/end: dagonal, radius 2, 3, 4
            4 - all ortogon, start/end: diag + radius 2 + radius (param 8)
            5 - all ortogon and diagonal (with random), start/end diag + radius 2 + radius (param 8)
            6 - all links in radius (param 8), random, start/end in radius
            7 - all links in radius (param 8), with random
        arg8 (optionally) - radius of connections
        arg9 (optionally) - random (probability of links: 1..100% (0% == 100%))''')


def addlink(links, rooms, i, j, y, x, random=0):
    def check_frontiers():
        if 0 <= y < len(rooms) and 0 <= x < len(rooms[i]) and \
            0 <= i < len(rooms) and 0 <= j < len(rooms[i]):
            return True
        else:
            return False
        
    def link_append():
        try:
            room1 = min(rooms[i][j], rooms[y][x])
            room2 = max(rooms[i][j], rooms[y][x])
            links.append((room1, room2))
        except:
            pass
    
    if (check_frontiers()):
        if random == 0:
            link_append()
        elif rnd.randint(0, 100) < random:
            link_append()        

def addlinks(links, rooms, i, j, directions, random=0):
    for r, c in directions:
        y = i + r
        x = j + c
        addlink(links, rooms, i, j, y, x, random)

def addlinks_all_ortogonal(links, rooms, random=0):
    for i in range(len(rooms)):
        for j in range(len(rooms[i])):
            addlinks(links, rooms, i, j, directions0, random)

def addlinks_all_diagonal(links, rooms, random=0):
    for i in range(len(rooms)):
        for j in range(len(rooms[i])):
            addlinks(links, rooms, i, j, directions1, random)            

def addlinks_all_inradius(links, rooms, random=0):
    for i in range(len(rooms)):
        for j in range(len(rooms[i])):
            for shift_i in range(1-radius, radius):
                for shift_j in range(1-radius, radius):
                    if shift_i != 0 and shift_j != 0:
                        addlink(links, rooms, i, j, i + shift_i, j + shift_j, random)

def addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j):
    addlinks(links, rooms, start_room_i, start_room_j, directions1, random=0)
    addlinks(links, rooms, end_room_i, end_room_j, directions1, random=0)

def addlinks_dirs2(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j):
    addlinks(links, rooms, start_room_i, start_room_j, directions2, random=0)
    addlinks(links, rooms, end_room_i, end_room_j, directions2, random=0)

def addlinks_dirs3(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j):
    addlinks(links, rooms, start_room_i, start_room_j, directions3, random=0)
    addlinks(links, rooms, end_room_i, end_room_j, directions3, random=0)

def addlinks_dirs4(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j):
    addlinks(links, rooms, start_room_i, start_room_j, directions4, 0)
    addlinks(links, rooms, end_room_i, end_room_j, directions4, 0)

def add_links_dirs234_radius(links, rooms, start_i, start_j, end_i, end_j, radius):
    for i in range(1 - radius, radius):
        for j in range (1 - radius, radius):
            s_i, s_j = start_i + i, start_j + j
            e_i, e_j = end_i + i, end_j + j
            addlinks_dirs2(links, rooms, s_i, s_j, e_i, e_j)
            addlinks_dirs3(links, rooms, s_i, s_j, e_i, e_j)
            addlinks_dirs4(links, rooms, s_i, s_j, e_i, e_j)

def addlinks_in_radius(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j, radius):
    y_values = (radius, -radius)
    x_values = (radius, -radius)
    for y in y_values:
        for x in range(1-radius, radius):
            addlink(links, rooms, start_room_i, start_room_j, start_room_i + y, start_room_j + x, random=0)
            addlink(links, rooms, end_room_i, end_room_j, end_room_i + y, end_room_j + x, random=0)
    for x in x_values:
        for y in range(1-radius, radius):
            addlink(links, rooms, start_room_i, start_room_j, start_room_i + y, start_room_j + x, random=0)
            addlink(links, rooms, end_room_i, end_room_j, end_room_i + y, end_room_j + x, random=0)

if len(sys.argv) < 2:
    print_usage()
    exit()

filename = sys.argv[1]

# create matrix of vertex (matrix[][]) from file
if len(sys.argv) > 0:
    with open(filename, 'r') as fd:
        matrix = []
        i = 0
        for line in fd:
            matrix.append([])
            for num in line.rstrip().split(" "):
                try:
                    matrix[i].append(int(num))
                except:
                    if ',' in num:
                        n, color = num.split(',')
                        try:
                            matrix[i].append((int(n), color))
                        except:
                            pass
                    pass
            i += 1

print("#size map: height {} x width {}".format(len(matrix), len(matrix[0])))

if len(sys.argv) >= 8:
    number_of_ants = int(sys.argv[2])
    start_room_i = int(sys.argv[3])
    start_room_j = int(sys.argv[4])
    end_room_i = int(sys.argv[5])
    end_room_j = int(sys.argv[6])
    type_connections = int(sys.argv[7])
    radius = int(sys.argv[8]) if len(sys.argv) >= 9 else 0
    random = int(sys.argv[9]) if len(sys.argv) >= 10 else 0
else:    
    number_of_ants = int(input("Enter number of ants: "))
    start_room_i = int(input("Enter row of start room: "))
    start_room_j = int(input("Enter col of start room: "))
    end_room_i = int(input("Enter row of end room: "))
    end_room_j = int(input("Enter col of end room: "))
    print(
        '''type of connections:
            0 - only ortogonal
            1 - all ortogonal, start/end: diagonal
            2 - all ortogon, start/end: diagonal and radius 2
            3 - all ortogon, start/end: dagonal, radius 2, 3, 4
            4 - all ortogon, start/end: diag + radius 2 + radius (param 8)
            5 - all ortogon and diagonal (with random), start/end diag + radius 2 + radius (param 8)
            6 - all links in radius (param 8), random, start/end in radius
            7 - all links in radius (param 8), with random
        '''
    )
    type_connections = int(input("Enter type of connections rooms (1..5): "))
    radius = int(input("Enter radius of connections: "))
    random = int(input("Enter random (1-100% (0% = 100%)): "))

print("map parameters: ants {}, start({},{}), end({},{}), type connections: {}".format(number_of_ants, start_room_i, start_room_j, end_room_i, end_room_j, type_connections))
print("radius: {}, random: {}".format(radius, random))
# print_rooms - make list with info for printing anthill
print_rooms = []
print_rooms.append(str(number_of_ants))
print_rooms.append("#rooms:")
room = 0 # counter of rooms
# rooms[][] - matrix of rooms, where rooms[i[j] == number of room.
rooms = []
for i in range(len(matrix)):
    rooms.append([])
    for j in range(len(matrix[i])):
        if i == start_room_i and j == start_room_j:
            print_rooms.append("##start")
        if i == end_room_i and j == end_room_j:
            print_rooms.append("##end")
        if  type(matrix[i][j]) == int:
            print_rooms.append(str(room) + " " + str(j) + " " + str(i) + " " + str(matrix[i][j]))
        elif len(matrix[i][j]) == 2:
            print_rooms.append(str(room) + " " + str(j) + " " + str(i) + " " + str(matrix[i][j][0]) + " " + str(matrix[i][j][1]))         
        rooms[i].append(room)
        room += 1

#base directions (ortogonal)
links = []

if int(type_connections) == 0:
    addlinks_all_ortogonal(links, rooms)

# additional links (1) (diagonal near start/end)
if int(type_connections) == 1:
    addlinks_all_ortogonal(links, rooms)
    addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)

# additional links (2) (edges on distanse 2)
if int(type_connections) == 2:
    addlinks_all_ortogonal(links, rooms)
    addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_dirs2(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)

# additional links (3) (feel +-2 boxes with diagonal edges)
if int(type_connections) == 3:
    addlinks_all_ortogonal(links, rooms)
    addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_dirs2(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    add_links_dirs234_radius(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j, radius)

# add links (4) (24 edges on distanse 4)
if int(type_connections) == 4:
    addlinks_all_ortogonal(links, rooms)
    addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_dirs2(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_in_radius(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j, radius)

if int(type_connections) == 5:
    addlinks_all_ortogonal(links, rooms, random)
    addlinks_all_diagonal(links, rooms, random)
    addlinks_startend_diagonal(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_dirs2(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j)
    addlinks_in_radius(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j, radius)

if int(type_connections) == 6:
    addlinks_in_radius(links, rooms, start_room_i, start_room_j, end_room_i, end_room_j, radius)    
    addlinks_all_inradius(links, rooms, random)

if int(type_connections) == 7:
    addlinks_all_inradius(links, rooms, random)
    
# remove duplicates of links
links = set(links)

filename1 = []
filename1.append(os.path.splitext(filename)[0])
filename1.append(str(number_of_ants))
filename1.append(str(start_room_i))
filename1.append(str(start_room_j))
filename1.append(str(end_room_i))
filename1.append(str(end_room_j))
filename1.append(str(type_connections))
filename1 = "_".join(filename1)
filename_z = filename1 + "_z"

print("map name: {}".format(filename_z))

with open(filename_z, "w") as fd:
    for line in print_rooms:
        fd.write(line + "\n")
    for link in links:
        fd.write("{}-{}".format(link[0], link[1]) + "\n")
    fd.write("#size map: height {} x width {}".format(len(matrix), len(matrix[0])) + "\n")
    fd.write("#map parameters: number of ants: {}, start: ({}, {}), end: ({}, {})\n".format(number_of_ants, start_room_i, start_room_j, end_room_i, end_room_j))
    fd.write("#type connections: {}, radius: {}, random: {}\n".format(type_connections, radius, random))
    