import sys


def getCompStr(s):
    compstr = ''
    akt = 0
    counter = 1
    for c in s:
        if len(compstr) == 0:
            akt = c
            compstr += str(c)
        else:
            if c == akt:
                counter += 1
            else:
                if counter > 1:
                    compstr += str(counter)
                akt = c
                compstr += str(akt)
                counter = 1
    if counter > 1:
        compstr += str(counter)
       
    return compstr
        
            
    


if __name__ == "__main__":
    if len(sys.argv) > 1:
        for arg in sys.argv[1:]:
            print getCompStr(arg)
