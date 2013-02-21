#Aufgabe 1 a

l = [1,2,3]
for e in l:
    print e

i=0
while i<len(l):
    print [i]
    i+=1


#Aufgabe 1 b

d = {1:"eins", 2:"zwei", 3:"drei"}
l = d.keys()
i = 0
while i < len(l):
    s = l[i]
    print s, d[s]
    i = i+1

for e in d:
    print e, d[e]
