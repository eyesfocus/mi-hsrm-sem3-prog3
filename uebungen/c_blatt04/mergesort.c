#include "doppliste.c"
#include <stdio.h>
#include <string.h>

/* Interpretiert zwei Pointer auf void als
   Strings und vergleicht diese. */

int compare(void *val1, void *val2) {
  return strcmp((char *)val1, (char *)val2);
}

/* Steckt alle Komandozeilenparameter in eine 
doppelt verkettete Liste, gibt die Liste aus,
sortiert sie und gibt die sortierte Liste aus. */

int main(int argc, char *argv[]) {
  lptr l = NULL;
  int i;
  for (i=1; i<argc; i++) {
    l = add_last(l, argv[i]);
  }

  printf("Zu sortieren:  ");
  show(l);

  /*l = sort(l, compare);
  printf("Sortiert:      ");
  output_string_list(l);

  del_all(l);*/

  return 0;
}
