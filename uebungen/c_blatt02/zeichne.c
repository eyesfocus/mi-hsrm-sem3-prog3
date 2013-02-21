#include <stdio.h>
#include <string.h>
#include <math.h>

int ppm[500][500];
int breite = 500;
int hoehe = 500;


int out(void){
  int i,j;
  int r,g,b;
  int akt;

  printf("P3\n");
  printf("%d %d\n", breite, hoehe);
  printf("255\n");
  for(i = 0; i < breite; i++){
    for(j = 0; j < hoehe; j++){
      akt = ppm[i][j];
      r = ((akt >> 16) & 255);
      g = ((akt >> 8) & 255);
      b = (akt & 255);

      printf("%d %d %d\n", r, g, b);
    }
  }
  return 0;
}

int kreis(int farbe, int x, int y, int r){
  int i,j;
  for(i = 0; i < breite; i++){
    for(j = 0; j < hoehe; j++){
      int q = pow(x-i, 2) + pow(y-j, 2);
      if(q <= (r*r)){
	  ppm[i][j]= farbe;
      } 
    }
  }

  return 0;
}

int hintergrund(int farbe){
  int i,j;
  for(i = 0; i < breite; i++){
    for(j = 0; j < hoehe; j++){
      ppm[i][j] = farbe;
    }
  }
  return 0;
}

int rechteck(int farbe, int x1, int y1, int x2, int y2){
  int i,j;

  for(i = x1; i < (x2-x1); i++){
    for(j = y1; j < (y2-y1); j++){
      ppm[i][j] = farbe;
    }
  }
  return 0;
}

int generateColor(int r, int g, int b){
  int color;

  r = r << 16;
  g = g << 8;

  color = (r | g | b);
 
 return color;
}

int main(void){
  int magenta;
  int schwarz;

  magenta = generateColor(255, 0, 255);
  schwarz = generateColor(0, 0, 0);

  /* printf("r:%d, g:%d, b:%d, magenta: %d\n", r,g,b, magenta);*/


  hintergrund(schwarz);
  rechteck(magenta, 0, 0, 100, 100);
  kreis(magenta, 300, 300, 50);


  out();

  return 0;
}
