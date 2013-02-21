#include <stdio.h>

int rot_n = 0;


int set_rotate(int n){
  rot_n = n;

  return 0;
}


int rotate(int c){
  if ('A' <= c && c  <= 'Z'){
	   c = (((c-'A')+rot_n)%26)+'A';
	}
  
	if ('a' <= c && c  <= 'z'){
	  c = (((c-'a')+rot_n)%26)+'a';
	}
	
	putchar(c);	
       
 

return 0;

}
