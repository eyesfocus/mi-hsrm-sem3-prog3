class Ring:
    def __init__(self, seq): 
        self.liste = []
        self.index = 0
        for s in seq:
            self.liste.append(s)

    def __iter__(self):
        it = Ring(self.liste)
        it.index = self.index
        return it

    def __repr__(self):
        s = "r["
        i = 0
        while i < len(self.liste):
            if i == self.index:
                s += "; "
            else:
                if i > 0:
                    s += ", "
            s += str(self.liste[i])
            i+=1
        s += "]"
        return s

    def __contains__(self, item):
        return item in self.liste

    def __len__(self):
        return len(self.liste)
        

    def __getitem__(self, key):
        if key == 0:
            return self.liste[self.index]
        i = self.index
        while key != 0:
            if i == len(self.liste) - 1:
                i = 0
            else:
                i += 1
            key -= 1
        return self.liste[i]
            
    
    def add(self, ele): 
        if self.index == 0:
            self.liste.append(ele)
        else:
            self.liste[self.index:self.index] = [ele]
            self.index +=1
            
    def add_sequence(self, seq):
        for e in seq:
            self.add(e)

    def get_elements(self):
        elems = self.liste[self.index:]
        elems.extend(self.liste[:self.index])
        return elems  

    def get_current(self): 
        return self.liste[self.index]

    def remove_current(self): 
        del self.liste[self.index]
        if self.index >= len(self.liste):
            self.index = 0
    
    def next(self): 
        if self.index < len(self.liste)-1:
            self.index += 1
            return self.liste[self.index-1]
        else:
            self.index = 0
            return self.liste[len(self.liste)-1]

    def is_empty(self):
        if len(self.liste) == 0:
            return True
        else:
            return False

    def clear(self):
        self.liste = []
        self.index = 0
