/* ---------- */
/* retraite.c */
/* ---------- */
#include <stdio.h>
#define AGE_LEGAL_RETRAITE 65

int main()
{
  int Age, Retraite_Dans, Retraite_Depuis ;

  printf("Entrez votre age :");
  scanf("%d",&Age);

  if (Age >= AGE_LEGAL_RETRAITE)
  {
     Retraite_Depuis = Age-AGE_LEGAL_RETRAITE;
     printf("Vous 