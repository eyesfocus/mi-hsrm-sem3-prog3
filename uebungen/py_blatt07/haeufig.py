import text

dic = text.count.count_words("shakes.txt")

lis = []
for e in dic:
    lis.append((dic[e], e))

lis.sort(reverse = True)

print lis[:26]
print lis[25][1]
