z = 123456

print [k for k in [t**3 for t in range(1,10)] if k%2==0]

print [t for t in range(2,z-1) if z%t == 0]

print [p for p in range(1,20) if [t for t in range(2, p-1) if z%t == 0] == []]
