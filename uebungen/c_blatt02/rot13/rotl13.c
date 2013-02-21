#include <stdio.h>

extern int set_rotate(int n);
extern int rotate(int c);


int main(void){
  set_rotate(13);
  rotate('A');

  return 0;
}
