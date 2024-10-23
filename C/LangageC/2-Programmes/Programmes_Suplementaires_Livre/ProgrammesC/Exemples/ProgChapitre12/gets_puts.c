/* ----------- */
/* gets_puts.c */
/* ----------- */
#include <stdio.h>

main()
{
  char Nom[10], Libelle[30];
  char *pnom ;

  printf("Entrez Nom : ");

  /* saisie du Nom */
  pnom=gets(Nom)  ;

  /* Formatage d'une chaine en sortie */
  sprintf(Libelle,"Bonjour M. %s",Nom) ;

  /* impression d'une chaine */
  puts(Libelle) ;
}

