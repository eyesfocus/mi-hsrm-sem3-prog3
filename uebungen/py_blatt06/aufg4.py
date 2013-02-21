#!usr/bin/python
# -*- coding: utf-8 -*-

import random
import string
import sys
import os

fordir = "/usr/share/games/fortunes"

def rand(l):
    rand = random.randint(0, len(l))
    print l[rand]

def filt(s):
    return ".dat" not in s and ".u8" not in s
    

datlis = os.listdir(fordir)
datlis = filter(filt, datlis)



lis = []
for e in datlis:
    dat = file("/usr/share/games/fortunes/" + e).read()
    lis.append(dat.split("\n%\n"))

    
if len(sys.argv) == 1:
    rand(lis)

if len(sys.argv) == 3 and sys.argv[1] == "-m":
    pat = sys.argv[2]
    pat_lis = []

    for e in lis:
        if pat in e:
            pat_lis.append(e)

    if len(pat_lis) != 0:
        rand(pat_lis)

