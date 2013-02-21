#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int toInt(char k[]){
  unsigned int convert = 0; /*konvertierte binaerzahl*/
  unsigned int bitwert = 1; /*aktueller bitwert*/
  int size = 0;
  int i;

  size = strlen(k);
  
  /*durchlaeuft die eingabe von hinten und berechnet bei gesetzter 1 den aktuellen Bitwert zum Gesamtwert hinzu */
  for(i = size-1; i >= 0; i--){
    if(k[i] == '1'){
      convert += bitwert;
    }
    bitwert = bitwert*2; /*naechstes Bit*/
  }
  return convert;
}

int toBinar(unsigned int out){
  unsigned int m = (sizeof(unsigned int)*8); /*Anzahl Bitstellen*/
  unsigned int n = 1 << (m-1); /*zunaechst groesst moegliches Bit*/
  unsigned int gesetzt = 0; /*"Fleck"*/

  /*durchlaeuft die Zahl "out" und ueberprueft ob Bits gesetzt sind*/
  while(n > 0){
    if (out & n){ 
      putchar('1');
      gesetzt = 1; 
    } else if((gesetzt == 1) |(n == 1)) { /*sobald erstes Bit gesetzt, oder letztes Bit erreicht...*/
      putchar('0'); /*duerfen ggf. Nullen ausgegeben werden*/	
    }
    n = n >> 1; /*naechst niedrigeres Bit*/
  }
  printf("\n");

  return 0;
}

int main(int argc, char *argv[]){

unsigned int x;
unsigned int y;
unsigned int out=0;

  if (argc > 1) {
	
    x = toInt(argv[1]);
    y = toInt(argv[3]);

    if(strcmp(argv[2], "and") == 0){
      out = (x & y);
    } else if(strcmp(argv[2], "or") == 0){
      out = (x | y);
    } else if(strcmp(argv[2], "xor") == 0){
      out = (x ^ y);
    } else if(strcmp(argv[2], "rshift") == 0){
      out = (x >> y);
    } else if(strcmp(argv[2], "lshift") == 0){
      out = (x << y);
    }
  } 

  toBinar(out);

  return out;
}
