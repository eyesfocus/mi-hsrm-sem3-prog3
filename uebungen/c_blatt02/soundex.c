#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void out(char wort[], char soundex[]){
  int i,j;
  int size_w = strlen(wort);
  int size_s =strlen(soundex);

  for(i=0; i<size_w; i++){
    putchar(wort[i]);
  }

  printf(" : ");

  for(j=0; j<size_s; j++){
    printf("%c", soundex[j]);
  }

  printf("\n");
}

char check(char akt){
  switch(akt){
  case 'b': case'f': case 'p': case 'v': return '1';
  case 'c': case'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z': return '2';
  case 'd': case 't': return '3';
  case 'l': return '4';
  case 'm': case 'n': return '5';
  case 'r': return '6';
  }
  return '0';
}

int generate(char wort []){
  char soundex [6];
  int size = strlen(wort);
  int soundsize = strlen(soundex);
  int i, j=1;
  char akt, gen;

  soundex[0] = wort[0];

  for(i=1; i<size && j<soundsize ; i++){
    akt = wort[i];
    gen = check(akt);

    if(gen != '0'){ 
      soundex[j++] = gen;
    
      if(soundex[j-1] == soundex[j-2]){
	j--;
      }
    }
  }

  if (j < soundsize){
    for(j=j; j<soundsize; j++){
      soundex[j] = '0';
    }
  }

  out(wort, soundex);

  return 0;
}

int main(int argc, char *argv[]){
  int i;
  for(i=1; i<argc; i++){
    generate(argv[i]);
  } 


  return 0;
}
