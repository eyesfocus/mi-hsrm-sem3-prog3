import string

def konsonanten(s):
    "Zaehlt alle Konsonanten im String s und gibt die Anzahl zurueck"

    voks = ["a","e","i","o","u","A","E","I","O","U"]
    anz = 0
    for e in s:
        if e in string.ascii_letters:
            if e not in voks:
                anz = anz + 1
    return anz
                
        
def vokale(s):
    "Zaehlt alle Vokale im String s und gibt ein Dictionary mit den Vokalen als Schluessel und deren Vorkommen als Werte zurueck"

    voks = ["a","e","i","o","u","A","E","I","O","U"]
    vokdict = {"a":0, "e":0, "i":0, "o":0, "u":0, "A":0, "E":0, "I":0 ,"O":0,"U":0}
    
    for e in s:
        if e in voks:
            vokdict[e] += 1

    return vokdict
            


def haeufigste_kleine_vokale(s):
    "Zaehlt alle kleinen Vokale im String s und gibt eine Liste von Tupeln zurueck, fuer die gilt tupel = (anzahl, vokal)"

    voks_klein = ["a", "e", "i", "o", "u"]
    vokdict = {"a":0, "e":0, "i":0, "o":0, "u":0}
    lis = []

    for e in s:
        if e in voks_klein:
            vokdict[e] += 1

    
    for e in vokdict:
        lis.append((vokdict[e], e))

    lis.sort()
    lis.reverse()
    
    return lis

            
if __name__ == '__main__':
    fname = '/usr/share/dict/words'
    s = file(fname).read()
    print "Anzahl Konsonanten", konsonanten(s)
    print "Vokale", vokale(s)
    print "haeufigste kleine Vokale", haeufigste_kleine_vokale(s)
