/* --------------------- */
/* tableau_et_pointeur.c */
/* --------------------- */
#include <stdio.h>

main()
{ 
  int Tab_Carre[10], i ;
  /* declaration d'un pointeur d'entier */
  int *adr_case ;

  /* boucle d'initialisation */
  for (i=0;i<10;i++)
      Tab_Carre[i]=i*i;

  /* boucle d'affichage par les numeros */
  printf("Contenu du tableau (indice de cases):\n");
  for (i=0;i<10;i++)
      printf("%3d",Tab_Carre[i]);
  printf("\n");

  /* adresse de la premiere case */
  adr_case = Tab_Carre ;
  /* boucle d'affichage utilisant le pointeur*/
  printf("Contenu du tableau (pointeur de cases):\n");
  for (i=0;i<10;i++)
  {
      printf("%3d",*adr_case);
      adr_case++ ;
  }
  printf("\n");
}
