#Aufgabe 2a

def ggTr(x, y):
    "rekursiv: gibt groessten gemeinsamen Teiler von x und y zurueck"

    if x == y:
        return x
    if x > y:
        return ggTr(x-y, y)
    else: #x<y
        return ggTr(x, y-x)

print ggTr(10,30)
print ggTr(20,30)
print ggTr(2,5)
print ggTr(8,6)
print ggTr(7,3)






#Aufgabe 2b
def ggTi(x, y):
    "iterativ: gibt groessten gemeinsamen Teiler von x und y zurueck"

    if x <= 0 & y <= 0:
        return 0
    while x % y:
        x = x % y
        if x < y:
            x,y = y,x
    return y

#alternativ
def ggTi_2(x, y):
    while y!=0:
        x,y = y, x%y
    return x


print ggT(10,30)
print ggT(20,30)
print ggT(2,5)
print ggT(8,6)
print ggT(7,3)



#Aufgabe 2c

#mit tupel:
def mittelwert():
    list = []
    for line in file("ggts.dat"):
        list.append(int(line.strip()))

    tup = zip(list[::2], list[1::2])
    t=0
    for x,y in tup:
        z = ggT(x,y)
        t = t+z
    print t/(len(tup))

#alternativ:
def mittelwert2():
    list = []
    for line in file("ggts.dat"):
        list.append(int(line.strip()))

    ggtges = 0
    i = 0
    while i < len(list)/2: 
        ggt = ggT(list[i*2], list[i*2+1])
        ggtges = ggtges + ggt
        i = i+1

    print ggtges/(len(list)/2)





#Aufgabe 2d

#rek
def ggTl(l):
    if len(l) == 1:
        return l[0]
    else:
        l[:2] = [ggT(l[0], l[1])]
        return ggTl(l)

def ggTl2(l):
    
    
