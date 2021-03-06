#include <stdio.h>
#include <stdlib.h>

typedef struct queue *lqueue;


extern int is_empty(lqueue lq);
extern lqueue enter(lqueue lq, int x);
extern int front(lqueue lq);
extern lqueue leave(lqueue lq);


int main(void){
  
  lqueue queue = NULL;
  int i;
  for(i=0; i<200; i++){
    queue = enter(queue, i);
    printf("front: %d\n", front(queue));
  }
  printf("leer: %d\n", is_empty(queue));

  for(i=0; i<200; i++){
    printf("front: %d\n", front(queue));
    queue = leave(queue);
  }

  printf("leer: %d\n", is_empty(queue));
  return 0;
}
