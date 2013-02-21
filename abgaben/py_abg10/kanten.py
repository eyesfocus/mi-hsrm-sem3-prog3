#!/usr/bin/python
# -*- coding: utf-8 -*-

from pyfilter import python_filter
import sys, os
import ctypes

def lese(path):
    datei = file(path).read()
    pgm = [int(i) for i in datei.split()[1:]]
    return pgm

def machDatei(lis, name):
    "erstellt aus Liste neue pgm Datei"

    if len(sys.argv) > 2:
        out = sys.argv[3]
    if len(sys.argv) <=3:
        out = "out2.pgm"
    fobj = open(out, "w")
    fobj.write("P2\n")
    fobj.write(str(lis[0]) + " " + str(lis[1]) + "\n")
    fobj.write(str(lis[2]) + "\n")

    i = 1
    for e in lis[3:]: 
        fobj.write(str(e))
        fobj.write(" ")
        if i%20==0:
            fobj.write("\n")
        i+=1

    fobj.close()    


if __name__ == '__main__':
    pgm = lese(sys.argv[2])
    
    if sys.argv[1] == 'python':
        n_pgm = python_filter(pgm)
        machDatei(n_pgm, sys.argv[3])

    if sys.argv[1] == 'c':
        pgmArray = ctypes.c_int * (len(pgm))
        pgm_in_c = pgmArray(*(pgm))
        laenge_in_c = ctypes.c_int(len(pgm))
        cfilter = ctypes.cdll.LoadLibrary(os.path.join(os.getcwd(),'cfilter.so'))
        cfilter.c_filter(pgm_in_c,laenge_in_c)
        machDatei(pgm_in_c, sys.argv[3])

