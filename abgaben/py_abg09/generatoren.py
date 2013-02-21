def im_kreis(g):
    g_liste = list(g)
    i = 0
    
    while True:
        if i == len(g_liste):
            i = 0
            
        yield g_liste[i]
        i += 1
        
def von_vorne(g):
    g_liste = list(g)
    i, j = 0, 0
    
    while j < len(g_liste):
        while i <= j:
            yield g_liste[i]
            i += 1
        i = 0
        j += 1
    
def pendel(g):
    g_liste = list(g)
    back = False
    i = 0
    
    while True:
        yield g_liste[i]

        if i+1 == len(g_liste):
            back = True
        if i-1 < 0:
            back = False
            
        if not back:
            i += 1
        else:
            i-= 1
            
        
        
