import os
import sys

def objread(datei):

    x = []
    for line in datei:
        if len(line.split()) > 1 and line.split()[0] == 'v':
            x.append(map(float,line.split()[1:]))

    pl = [(a[0], a[1], a[2]) for a in x]
    return pl
    
    
if __name__ == '__main__':
    if len(sys.argv) > 1:
        datei = file(sys.argv[1])
        print objread(datei)
