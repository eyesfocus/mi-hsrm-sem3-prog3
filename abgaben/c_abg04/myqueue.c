#include <stdio.h>
#include <stdlib.h>

/*Tina Schedlbauer*/


struct queue{
  struct queue *next;
  int value;
};

typedef struct queue *lqueue;

int is_empty(lqueue lq){
  return (lq == NULL);
}

lqueue enter(lqueue lq, int x){
  lqueue newnode = malloc(sizeof(struct queue));
  newnode->value = x;
  newnode->next = NULL;
  
  if(is_empty(lq)){
    lq = newnode;
  } else {
    lqueue akt = lq;
    while (akt->next != NULL){
      akt = akt->next;
    }
    akt->next = newnode;
  }

  return lq;
}

int front(lqueue lq){
  return lq->value;
}

lqueue leave (lqueue lq){
  if(!is_empty(lq)){
    lqueue leaver = lq;
    lq = lq->next;
    free(leaver);
  }
 
  return lq;
}
