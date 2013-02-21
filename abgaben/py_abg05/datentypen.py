#!usr/bin/python
# -*- coding: utf-8 -*-


lis = range(100)
import string

s = string.lowercase + string.uppercase

lis_a = lis[1:-1]
lis_b = lis[::2]
lis_c = lis[1::2]
lis_d = zip(lis_b, lis_c)

s_a = s[::2]
s_b = s[::-1]
