/* Sortiert eine gegebene Liste mittels MergeSort.
   l:     zu sortierende liste
   comp:  Vergleichsfunktion für zwei Zeiger auf void */

lptr sort(lptr l, int(*comp)(void *, void *)) {
  /* Abbruchfall: einelementige Liste */
  if (l->next == NULL)
    return l;

  /* Problem teilen: zwei listen */
  int list_size = size(l);
  lptr l1 = NULL;
  lptr l2 = l;

  int i;
  for (i=0; i<list_size/2; i++) {
    l1 = add_last(l1, l2->value);
    l2 = del(l2);
  }

  /* Teilprobleme aufrufen */
  lptr sort1 = sort(l1, comp);
  lptr sort2 = sort(l2, comp);

  /* Teillösungen zusammenfügen */
  lptr solved = NULL;
  /* solange nicht beide Listen leer sind... */
  while(sort1 != NULL || sort2 != NULL) {
    if ((sort1 != NULL && sort2 != NULL && comp(sort1->value, sort2->value) <= 0) 
	|| sort2 == NULL) {
      /* Wert aus erster Liste ist kleiner oder einzig vorhandener */
      solved = add_last(solved, sort1->value);
      sort1 = del(sort1);
    } else {
      /* Wert aus zweiter Liste ist kleiner oder einzig vorhandener */
      solved = add_last(solved, sort2->value);
      sort2 = del(sort2); 
    }
  }

  return solved;
}
