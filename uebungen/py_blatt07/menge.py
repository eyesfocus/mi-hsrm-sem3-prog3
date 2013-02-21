# -*- coding: utf-8 -*-
import os
import sys

class Set(object):

    def __init__(self, seq = None):
        self.liste = [] 
        if seq == None:
            seq = []
        else:
            for e in seq:
                if e not in self.liste:
                    self.liste.append(e)
                    
    def add(self, elem):
        if elem not in self.liste:
            self.liste.append(elem)

    def union_update(self, seq):
        for e in seq:
            self.add(e)

    def union(self, seq):
        u = Set()
        u.union_update(self.liste)
        u.union_update(seq)
        return u

    def remove(self, elem):
        if elem in self.liste:
            self.liste.remove(elem)

    def difference_update(self, seq):
        for e in seq:
            self.remove(e)

    def difference(self, seq):
        d = Set()
        d.union_update(self.liste)
        d.difference_update(seq)
        return d

    def clear(self):
        self.liste = []

    def size(self):
        return len(self.liste)

    def __eq__(self, lis):
        for e in self.liste:
            if e not in lis:
                return False
        for e in lis:
            if e not in self.liste:
                return False
        return True

    def __ne__(self, lis):
        for e in self.liste:
            if e in lis:
                return False
        for e in lis:
            if e in self.liste:
                return False
        return True

    def __iter__(self):
        return iter(self.liste)

    def __len__(self):
        return len(self.liste)

    def __repr__(self):
        s = "set{"
        i = 0
        while i < len(self.liste):
            s += str(self.liste[i])
            i += 1
            if i < len(self.liste):
                s+= ", "
        s += "}"
        return s
    
    __add__ = union
    __radd__ = __add__
    __sub__ = difference
    

class OrderedSet(Set):
    def __init__(self, seq =[]):
        Set.__init__(self, seq)

    def __cmp__(self, seq):
        if self.liste == seq.liste:
            return 0
        elif self.liste < seq.liste:
            return -1
        return 1

    def add(self, elem):
        "Hinzufügen eines Elements an passender Stelle, wenn es noch nicht vorhanden ist"
        if elem not in self.liste:
            self.liste.append(elem)
            self.liste.sort()
