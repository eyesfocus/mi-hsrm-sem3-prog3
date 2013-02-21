#include <stdio.h>


int main(void){

	int c=1;

	while(c != EOF){
	  c = getchar();
	  if ('A' <= c && c  <= 'Z'){
	    c = (((c-'A')+13)%26)+'A';
	  }
	  if ('a' <= c && c  <= 'z'){
	    c = (((c-'a')+13)%26)+'a';
	  }
	  putchar(c);
	}

	return 0;
}
