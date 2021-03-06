#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *next;
  char* data;
};

typedef struct node *pointer;

int is_empty(pointer pt){
  return (pt == NULL);
}

pointer add(pointer pt, char* data){
  pointer new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if(is_empty(pt)){
    pt = new_node;
  } else if(pt->next == NULL){
    pt->next = new_node;
    new_node->next = pt;
    pt = new_node;
  } else {
    new_node->next = pt->next;
    pt->next = new_node;
    pt = new_node;
  }

  return pt;
}

pointer del(pointer pt, int no){

  if (!is_empty(pt) || pt->next == NULL){

      int i;
      pointer befdel = pt;
      pointer temp;

      printf("pt:%s\n", pt->data);
      printf("pt.next:%s\n", pt->next->data);
      printf("pt.next:%s\n", pt->next->next->data);


      for(i = 1; i < no; i++){
	befdel = befdel->next;
      }
      
      pt = befdel->next->next;
      temp = befdel->next;

      befdel->next = pt;

      printf("gelöscht:%s\n", temp->data);
      printf("pt:%s\n\n", pt->data);

      free(temp);

      if(pt->next == pt){  /*wenn nur ein element drin*/
	pt->next = NULL;  /*damit es nicht auf sich selbst zeigt*/
      }
  }
  return pt;
}

char *get(pointer pt, int no){
  pointer temp;
 
  if(!is_empty(pt)){
    int i;
    temp = pt;

    for(i=0; i<no; i++){
      temp = temp->next;
    }
  }
  return temp->data;
}

int main(int argc, char *argv[]){
  int silben = 4; /*atoi(argv[1]);*/
  int sizeOfList = 0;
  int i;
  pointer ringlist = NULL;

  ringlist = add(ringlist, "Tina");
  sizeOfList++;
  ringlist = add(ringlist, "Paul");
  sizeOfList++;    
  ringlist = add(ringlist, "Mario");
  sizeOfList++;    
  ringlist = add(ringlist, "Marcel");
  sizeOfList++;    
  ringlist = add(ringlist, "Marc");
  sizeOfList++;    
  ringlist = add(ringlist, "Tobi");
  sizeOfList++;
  

  while (sizeOfList>1){
    ringlist = del(ringlist, silben);
    sizeOfList--;
  }

  printf("Gewinner: %s\n", get(ringlist, 0));

  return 0;
}
