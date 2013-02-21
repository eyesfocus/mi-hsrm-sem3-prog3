#include <stdio.h>
#include <strings.h>

struct bla{
  int anz;
  char *strings[80]; 
};

struct bla split (char *str, char *delim){
  struct bla b;
  int counter=0;
  
  while(*str){
    
    if(*str == *delim){
      b.strings[counter] = '\0';
      counter++;
    }
    b.strings[counter] = *str;
    b.strings[counter]++;
  }

  b.anz = counter;
  
  return b;
}


int main(int argc, char *argv[]){
  char *splitter = argv[1];
  int i,j;
  struct bla hallo;

  if (argc > 2){
    for(i = 3; i< argc; i++){
      hallo = split(splitter, argv[i]);

    }

    for(j = 0; j < hallo.anz; j++){
      printf("%s\n", hallo.strings[j]); 
    }
  }


  return 0;

}
