#!usr/local/bin/python
# -*- coding: utf-8 -*-

import string, sys

def intlis():
    "erstellt neue Liste mit Integerwerten aus bestehender Liste"
    lis = []
    for pix in pgm:
        lis.append(int(pix))
    return lis

def machDatei(lis):
    "erstellt aus Liste neue pgm Datei"
    if len(sys.argv) > 3:
        out = sys.argv[4]
    if len(sys.argv) <=3:
        out = "out.pgm"
    fobj = open(out, "w")
    fobj.write(datei.split("\n")[0] + "\n")
    fobj.write(datei.split("\n")[1] + "\n")
    fobj.write(str(maxx) + "\n")
    i = 1
    for e in lis: 
        fobj.write(str(e))
        fobj.write(" ")
        if i%20==0:
            fobj.write("\n")
        i+=1

    fobj.close()

    
    

def heller(p):
    if -100 <= p and p <= 100:
        neu = []
        for i in intlis():
            i += int((p / 100.0) * maxx)
            if i > maxx:
                i = maxx
            if i < 0:
                i = 0
            neu.append(i)
        machDatei(neu)                   

def gamma(g):
    if 0 <= g and g <= 10.0:
        neu = []
        for i in intlis():
            i = (int)(float(maxx)*(float(i)/maxx)**g)
            if i > maxx:
                i = maxx
            if i < 0:
                i = 0
            neu.append(i)    
        machDatei(neu)
        
def binarisieren(s):
    if 0 <= s and s <= maxx:
        neu = []
        for i in intlis():
            if i >= s:
                i = maxx
            if i < s:
                i = 0
            neu.append(i)
        machDatei(neu)

#main
if len(sys.argv) > 1:
    datei = file(sys.argv[3]).read()
    maxx = int(datei.split("\n")[2])
    h = int(datei.split("\n")[1].split(" ")[0])
    b = int(datei.split("\n")[1].split(" ")[1])
    pgm = datei.split()[4:]

    meth = sys.argv[1]
    param = sys.argv[2]
    if meth in ["gamma", "heller", "binarisieren"]:
        if meth == "gamma":
            gamma(float(param))
        if meth == "heller":
            heller(int(param))
        if meth == "binarisieren":
            binarisieren(int(param))
    else:
        print "Fehlerhafte Parametereingabe (Methode)"
else:
    print "Bitte Parameter angeben"
        
