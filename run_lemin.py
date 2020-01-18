#!python3
import sys
import os
import subprocess as spr

def print_usage():
    print(
    '''usage: run_lemin arg1 arg2 [arg3]
    arg1 = name of lem-in file
    arg2 = file with anthill
    arg3 (optionally): 1 - if you want to remain file with result

    this program do:
        1. convert all rooms in map (arg2) to rooms with two coordinates (x, y)
        1. run lem-in: [arg1] < [converted map]
        2. remake res of lem-in to primary map
        3. run ./visu with primary map and results
    ''')

def convert_res_noz_to_z(anthill_z, res_no_z, res_z):
    if (len(sys.argv) != 3):
        for i in sys.argv:
            print(i)
        #print(len(sys.argv))
        print_usage()
        exit()

    anthill_print = []

    with open(anthill_z, 'r') as fd:
        for line in fd:
            anthill_print.append(line)

    with open(res_no_z, 'r') as fd:
        for line in fd:
            if line[0] == "L":
                anthill_print.append(line)

    with open(res_z, 'w') as fd:
        for line in anthill_print:
            print(line)
            fd.write(line)

if len(sys.argv) < 3:
    print_usage()
    exit()

prog_name = sys.argv[1]
prog_name_base = os.path.basename(sys.argv[1])
map_name = sys.argv[2]
visu_name = "./visu"

# check files
if os.path.isfile(prog_name) == False:
    print("error name program")
    exit()
if os.path.isfile(map_name) == False:
    print("error map file")
    exit()
if os.path.isfile(visu_name) == False:
    print("./visu not exist (may be need compile?)")
    exit()

print("convert map...", end="")
map_z = []
map_no_z = []
with open(map_name, "r") as fd:
    for line in fd:
        line = line.rstrip('\n')
        if len(line) != 0 and line[0] != '#' and ' ' in line:
            room = line.split(' ')
            map_no_z.append(room[0] + ' ' + room[1] + ' ' + room[2])
        else:
            map_no_z.append(line)
        map_z.append(line)
# map_no_z.append("\n")
# map_z.append("\n")
with open('run_lemin_map_without_z', "w") as fd:
    for line in map_no_z:
        line = line + "\n"
        fd.write(line)
if prog_name_base == prog_name and prog_name[0:2] != "./":
    prog_name = "./" + prog_name
    
print(" converted", end="\n")
start_str = prog_name + " < " + "run_lemin_map_without_z" + " > " + "run_lemin_res_without_z"
print(start_str)
print("start lem-in...")
p = spr.Popen(start_str, shell=True)
p.wait()
print("lem-in finished")

print("convert back ... ", end="")
ant_steps = []
with open('run_lemin_res_without_z', 'r') as fd:
    for line in fd:
        line = line.rstrip('\n')
        if len(line) != 0 and line[0] == 'L':
            ant_steps.append(line)
            

with open('run_lemin_res_with_z', 'w') as fd:
    fd.write("\n".join(map_z))
    fd.write("\n");
    fd.write("\n");
    fd.write("\n".join(ant_steps))
    
print("converted", end="\n")

p = spr.Popen("rm " + 'run_lemin_map_without_z', shell=True)
p.wait()
p = spr.Popen("rm "+ "run_lemin_res_without_z", shell=True)
p.wait()

print("start visualization ...")
p = spr.Popen("./visu " + 'run_lemin_res_with_z', shell=True)
p.wait()

if len(sys.argv) >= 4 and sys.argv[3] == '1':
    pass
else:
    p = spr.Popen("rm "+ "run_lemin_res_with_z", shell=True)
    p.wait()
    pass
print("finish")