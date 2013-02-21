#include <stdio.h>

int main(void){
  unsigned int eingabe;
  scanf("%ud", &eingabe);


  unsigned int m = (sizeof(unsigned int)*8);
  unsigned int n = 1 << (m-1);
  unsigned int gesetzt = 0;

  while(n > 0){
    if (eingabe & n){
      putchar('1');
      gesetzt = 1;
    } else if((gesetzt == 1) |(n == 1)) {
      putchar('0');		
    }
    n = n >> 1;
  }
  printf("\n");

  return 0;

}
