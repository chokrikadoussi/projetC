/* ------------------------ */
/* moyenne_via_pointeurs2.c */
/* ------------------------ */
#include <stdio.h>
#include <stdlib.h>

main()
{
  float *pr1,*pr2,*pr3, somme=0;
  int i ;

  /* allocation dynamique */
  pr1=malloc(sizeof(float));
  pr2=malloc(sizeof(float));
  pr3=malloc(sizeof(float));

  /* saisie */
  printf("Entrez 3 notes : ");
  scanf("%f %f %f",pr1,pr2,pr3);

  /* calcul de la somme */
  somme=*pr1 + *pr2 + *pr3 ;

  /* calcul de la moyenne */
  printf("Moyenne:%6.2f\n",somme/3);

  /* liberation de la memoire */
  free(pr1);
  free(pr2);
  free(pr3);
}

