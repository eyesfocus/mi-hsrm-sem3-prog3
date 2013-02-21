#!usr/local/bin/python
# -*- coding: utf-8 -*-
#!/usr/bin/python
# -*- coding: utf-8 -*-
        

def python_filter(b):
    breite = b[0];
    maxx = 0
    bild = b[3:]
    
    out = [b[0], b[1], maxx]
    
    aktpx = 0
    while aktpx < len(bild):
        summe1, summe2 = 0, 0

        if ((aktpx % breite) != 0) & ((aktpx - breite) >= 0): #es gibt links oben
            summe1 += bild[aktpx - breite - 1]
            summe2 += bild[aktpx - breite - 1]
            
        if (((aktpx+1) % breite) != 0) & ((aktpx - breite) >= 0): #es gibt rechts oben
            summe1 += (-bild[aktpx - breite + 1])
            summe2 += bild[aktpx - breite + 1]
            
        if (aktpx - breite) >= 0: #oben mitte
            summe2 += (2 * bild[aktpx - breite])
            
        if ((aktpx % breite) != 0) & (aktpx < (len(bild) - breite)): # links unten				// dann existiert links unten
            summe1 += bild[aktpx + breite - 1]
            summe2 += (-bild[aktpx + breite - 1])
            
        if (((aktpx+1) % breite) != 0) & (aktpx < (len(bild) - breite)): # rechts unten
            summe1 += (-bild[aktpx + breite + 1])
            summe2 += (-bild[aktpx + breite + 1])
            
        if (aktpx + breite) < len(bild): #unten mitte
            summe2 += ((-2) * bild[aktpx + breite])
            
        if ((aktpx) % breite) != 0: # links
            summe1 += (2 * bild[aktpx - 1])
            
        if ((aktpx + 1) % breite) != 0: # rechts
            summe1 += ((-2) * bild[aktpx + 1])

        value = abs(summe1) + abs(summe2)
        if value > maxx:
            maxx = value
            
        out.append(value)
        
        aktpx += 1

    out[2] = maxx

    return out



    



        
