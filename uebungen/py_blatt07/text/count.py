def count_words(s):
    dic = {}
    w = file(s).read().split()
    for e in [(v, w.count(v)) for v in set(w)]:
        dic[e[0]] = e[1]
    return dic

def count_chars(s):
    dic = {}
    w = file(s).read().strip()
    w = w.replace(" ", "")
    for e in [(v, w.count(v)) for v in set(w)]:
        dic[e[0]] = e[1]
    return dic
