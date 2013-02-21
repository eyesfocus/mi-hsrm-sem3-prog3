g = 20
print sorted([(x**3+y**3, a**3+b**3, x,y,a,b)for x in range(1, g) for y in range(1, g) for a in range(1,g) for b in range(1,g) if x < y if a < b if x < a if x**3 + y**3 == a**3 + b**3])
