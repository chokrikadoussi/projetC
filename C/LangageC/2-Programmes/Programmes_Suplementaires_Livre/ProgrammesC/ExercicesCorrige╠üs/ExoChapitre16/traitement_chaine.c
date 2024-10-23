/* ------------------- */
/* traitement_chaine.c */
/* ------------------- */
#include <stdio.h>
#include <string.h>
#define MAX_CHAINE 30

char *concatenation(char ch1[],char ch2[]) ;
int monindex(char ch[],char sch[]) ;

main()
{
  char chaine1[10],chaine2[10],chaine3[20];
  int position ;

  printf("Cha