def is_prim(x):
    for e in range(2,x):
        if x % e == 0:
            return False
    return True

def prim():
    yield 2
    i = 3
    while True:
        if is_prim(i):
            yield i
        i += 1

def pprim():
    p1, p2 = prim(), prim()
    p2.next()
    while True:
        x,y = p1.next(), p2.next()
        if x + 2 == y:
            yield x,y
