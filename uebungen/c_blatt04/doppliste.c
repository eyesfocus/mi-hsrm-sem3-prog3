#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *next;
  struct node *prev;
  void *data;
};

typedef struct node *lptr;

int size(lptr l) {
  int size = 0;
  while(l != NULL) {
    size++;
    l = l->next;
  }
  return size;
}

lptr add(lptr l, void *data){ /*check*/
  lptr new_node = malloc(sizeof(struct node));
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = data;

  /*bisher kein element vorhanden*/
  if(l == NULL){
    l = new_node;
    return l;
  }
  
  l->prev = new_node;
  new_node->next = l;
  l = new_node;
  
  return l;
}

lptr add_ith(lptr l, int ith, void *data){ /*check*/
  lptr new_node = malloc(sizeof(struct node));
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = data;

  /*falls leer*/
  if(l == NULL){
    l = new_node;
    return l;
  }

  int i;
  lptr temp = l;

  for (i=0; i<ith-1; i++){
    if(temp->next){
      temp = temp->next;
    }
  }

  /*falls erstes*/
   if(ith == 0){
    new_node->next = l;
    l->prev = new_node;
    l = new_node;
    return l;
  }

  /*falls letztes*/
  if(temp->next == NULL){
    temp->next = new_node;
    new_node->prev = temp;
    return l;
  }

  /*falls mitte*/
  temp->next->prev = new_node;
  new_node->next = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
 
  return l;
}

lptr add_last(lptr l, void *data){ /*check*/
  lptr new_node = malloc(sizeof(struct node));
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = data;

  if(l == NULL){
    l = new_node;
    return l;
  }

  lptr temp = l;
  
  while(temp->next){
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
  

  return l;
}

lptr del(lptr l){ /*check*/
  lptr temp;

  if(l != NULL){
    temp = l;
    if(temp->next){ /*mehrelementig*/
      temp->next->prev = NULL;
    }
    l = l->next;

    free(temp);
  }

  return l;
}

lptr del_ith(lptr l, int ith){ /*check*/
  lptr temp;
  lptr del;
  int i;

  /*falls leer*/
  if (l == NULL){
    return l;
  }

  temp = l;
  
  for(i=0; i<ith-1; i++){
    if(temp->next){
      temp = temp->next;
    }
  }

  /*erstes element soll geloescht werden*/
  if(ith == 0){
    l = l->next;
    if(l != NULL){ /*wenn mehrelementig*/
      l->prev = NULL;
    }
    free(temp);
    return l;
  }

  /*letztes element*/
  if(temp->next->next == NULL){
    lptr del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return l;
  }

  /*kein ith element vorhanden*/
  if(temp->next == NULL){
    printf("...");
    return l; /*Speicherzugriffsfehler*/
  }

  /*mittiges element*/
  del = temp->next;
  temp->next = del->next;
  if(del->next != NULL){ /*nicht letztes*/
    del->next->prev = temp;
  }
  free(del);

  return l;
}

lptr del_last(lptr l){ /*check*/
  lptr temp;
  lptr del;

  if(l != NULL){
    temp = l;
   
    if(l->next == NULL){ /*einelementig*/
      l = NULL;
      free(temp);
    } else { /*mehrelementig*/
      while (temp->next->next){
	temp = temp->next;
      }
      
      del = temp->next;
      temp->next = NULL;
      free(del);
    }
  }
  return l;
}

void del_all(lptr l){ /*check*/
  lptr del;

  while(l != NULL){
    del = l;
    l = l->next;

    if (l != NULL){
      l->prev = NULL; 
    }
    free(del);
  }
}

void del_all_custom(lptr l, void (*custom) (void*)){ /*HILFE*/
  lptr del;

  while(l != NULL){
    del = l;
    l = l->next;

    if (l != NULL){
      l->prev = NULL; 
    }
    custom(del->data);
    free(del);
  }
}

lptr copy(lptr l){ /*check*/

  lptr nl = NULL;

  if(l == NULL){
    return nl;
  }

  while (l != NULL){
    nl = add_last(nl, l->data);
    l = l->next;
  }

  return nl;


  /* lptr nl = NULL;
  lptr nn;
  int first = 1;

  if(l == NULL){
    return nl;
  }

  lptr temp = NULL;
 
  while (l != NULL){
    nn = malloc(sizeof(struct node));

    nn->next = NULL;
    nn->data = l->data;

    if(first){
      first = 0;
      nn->prev == NULL;
      nl = nn;
      temp = nl;
    } else {
        nn->prev = temp;
	temp->next = nn;
	temp = temp->next;
    }

    l = l->next;
  }


  return nl;*/
}


lptr copy_custom(lptr l, void * (*custom) (void*)){ /*HILFE*/
  return NULL;
}

void show(lptr l){
  lptr zeiger = l;
  if(zeiger == NULL){
    printf("Liste leer\n\n");
    return;
  }
  while (zeiger != NULL){
    printf("%d\n", *((int *) zeiger->data));
    zeiger = zeiger->next;
  }
  printf("Ende\n\n");

}



/*int main(void){
  lptr mylist = NULL;
  int a = 5;
  int *ap = &a;
  int b = 6;
  int *bp = &b;
  int c = 7;
  int *cp = &c;
  int d = 8;
  int *dp = &d;
  int e = 9;
  int *ep = &e;
  int f = 10;
  int *fp = &f;
  int g = 11;
  int *gp = &g;
  


  mylist = add(mylist, ap);
  mylist = add(mylist, bp);
  mylist = add(mylist, cp);
  mylist = add_last(mylist, dp);
  printf("my:\n");

  show(mylist);


  lptr clist = copy(mylist);
  show(clist);

  mylist = del(mylist);
  printf("my:\n");

  show(mylist);
  show(clist);



  return 0;
  }*/
