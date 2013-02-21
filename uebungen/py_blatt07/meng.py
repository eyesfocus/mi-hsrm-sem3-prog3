# -*- coding: utf-8 -*-

class Set(object):

    def __init__(self, seq = []):
        self.liste = []

        if len(seq) > 1:
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
        
    def remove(self, e):
        if e in self.liste:
            self.liste.remove(e)

    def difference_update(self, seq):
        for e in seq:
            if e in self.liste:
                self.liste.remove(e)
                
    def difference(self, seq):
        d = Set()
        d.union_update(self.liste)
        d.difference_update(seq)
        return d
    
    def clear(self):
        self.liste = []

    def size(self):
        return len(self.liste)
    
    def __eq__(self, lis): ##todo
        for e in self.liste:
            if e not in lis:
                return False
        for e in lis:
            if e not in self.liste:
                return False
        return True

    def __ne__(self, lis): ##todo
        for e in self.liste:
            if e in lis:
                return False
        for e in lis:
            if e in self.liste:
                return False
        return True
    
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

    def __iter__(self):
        return iter(self.liste)

    def __len__(self):
        return len(self.liste)

    __add__ = union
    __radd__ = __add__
    __sub__ = difference
