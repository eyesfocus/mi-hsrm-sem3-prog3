#include <stdio.h> 
#include <stdlib.h>

int betrag(int x){
  if (x < 0){
    return -x;
  }
  return x;
}


void c_filter(int* bild, int groesse) {

  int breite = bild[0];
  int hoehe = bild[1];
  int maxx = 0;
  int summe1 = 0;
  int summe2 = 0;
  int aktpx;
  int neuerwert = 0;

  
  int *vergleich = malloc(sizeof(int)*groesse);

  vergleich[0] = bild[0];
  vergleich[1] = bild[1];
  vergleich[2] = bild[2];

  
  for(aktpx = 3; aktpx < hoehe*breite; aktpx++){
    summe1 = 0;
    summe2 = 0;
    
    /*links oben*/
    if ((aktpx-3) % breite != 0 && (aktpx - breite) > 2){
      summe1 += bild[aktpx - breite - 1];
      summe2 += bild[aktpx - breite - 1];
    }

    /*rechts oben*/
    if ((aktpx-2) % breite != 0 && (aktpx - breite) > 2){
      summe1 += (-bild[aktpx - breite + 1]);
      summe2 += bild[aktpx - breite + 1];
    }
    
    /*mitte oben*/
    if (aktpx - breite > 2){
      summe2 += 2* bild[aktpx - breite];
    }

    /*links unten*/
    if ((aktpx-3) % breite != 0 && aktpx < (groesse - breite)) {
	summe1 += bild[aktpx + breite - 1];
	summe2 += (-bild[aktpx + breite -1]);
    }

    /*rechts unten*/
    if (((aktpx - 2) % breite) != 0 && aktpx < (groesse - breite)){
      summe1 += (-bild[aktpx + breite + 1]);
      summe2 += (-bild[aktpx + breite + 1]);
    }

    /*unten mitte*/
    if ((aktpx + breite) < groesse){
      summe2 += ((-2) * bild[aktpx + breite]);
    }
    
    /*links*/
    if (((aktpx - 3) % breite) != 0){
      summe1 += (2 * bild[aktpx - 1]);
    }

    /*rechts*/
    if (((aktpx - 2) % breite) != 0){
      summe1 += ((-2) * bild[aktpx + 1]);
    }


    neuerwert = (betrag(summe1) + betrag(summe2));

    if (neuerwert > maxx){
      maxx = neuerwert;
    }

    vergleich[aktpx] = neuerwert;
  }

  for (aktpx = 0; aktpx < groesse; aktpx++){
    bild[aktpx] = vergleich[aktpx];
  }
  bild[2] = maxx;
  free(vergleich);
  /*return vergleich;*/
}
