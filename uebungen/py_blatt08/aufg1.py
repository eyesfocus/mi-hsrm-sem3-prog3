# -*- coding: utf-8 -*-

import sys

def zaehle(woerter):
    dic = {}
    lis = []
    for w in woerter[1:]:
        if w in dic:
            dic[w] += 1
        else:
            dic[w] = 1
    m = max(dic.values())
    for k in dic:
        if dic[k] == m:
            lis.append((k, dic[k]))
    sorted(lis)
    for x,y in lis:
        print y, ':', x


if __name__ == '__main__':
    if len(sys.argv) > 1:
        zaehle(sys.argv)
