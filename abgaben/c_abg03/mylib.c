#include <stdio.h>

/*Tina Schedlbauer*/


int my_strcasecmp(const char *s1, const char *s2){
  int dist = ('a'-'A'); /*Abstand zwischen Gross- und Kleinbuchstabe*/
 
  while(*s1 != '\0' || *s2 != '\0'){
    if(*s1 == *s2){
      s1++;
      s2++;
    } else if (((*s1+dist) == *s2) && ('A' <= *s1 && *s1 <= 'Z')){
      s1++;
      s2++;
    } else if (((*s1-dist) == *s2) && ('a' <= *s1 && *s1 <= 'z')){
      s1++;
      s2++;
    } else {
      return (*s1-*s2);
    }
  }
  return 0;
}

const char *my_index(const char *s, int c){
  while(*s){
    if (*s == c){
      return s;
    }
    ++s;
  }
  return NULL; 
}
