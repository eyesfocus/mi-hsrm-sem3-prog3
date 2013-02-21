#include <stdio.h>
#include <strings.h>

extern int my_strcasecmp(const char *s1, const char *s2);
extern const char *my_index(const char *s, int c);


int main(void){
  /*WAS WENN z.B 'u' mitgegeben wird, das nicht enthalten ist?*/
  printf("Index: 'Hallo', 'H': \n");
  printf("Bib: %d, %c\n", *index("Hallo", 'H'), 72);
  printf("meins: %d, %c\n", *my_index("Hallo", 'H'), 72);


  printf("\nstrcmp: hallo hello\n");

   printf("\nHIER:");

 printf("Bib: %d\n", strcasecmp("Hallo", "hallo"));
  printf("meins: %d\n",my_strcasecmp("Hallo", "hallo"));

printf("Bib: %d\n", strcasecmp("Hallo", "hallo"));
  printf("meins: %d\n",my_strcasecmp("Hallo", "hallo"));

printf("Bib: %d\n", strcasecmp("hAlLo", "HaLlO"));
  printf("meins: %d\n", my_strcasecmp("hAlLo", "HaLlO"));

printf("Bib: %d\n", strcasecmp("hallo", "hello"));
  printf("meins: %d\n",my_strcasecmp("hallo", "hello"));

  return 0;
}
