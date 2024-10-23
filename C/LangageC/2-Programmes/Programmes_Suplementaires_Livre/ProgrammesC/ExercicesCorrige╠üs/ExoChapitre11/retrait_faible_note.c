/* --------------------- */
/* retrait_faible_note.c */
/* --------------------- */
#include <stdio.h>
#define TAILLE 10

main()
{ /* declarations */
  int i, num_plus_faible=0, nbnotes=TAILLE ;
  float tab_notes[TAILLE], plus_faible ;
  
  /* --- SAISIE des notes --- */
  printf("Entrez les 10 notes:");
  for (i=0 ; i<nbnotes ; i++)
    scanf("%f",&tab_notes[i]);
  
  /* === Recherche de la note la plus faible === */
  /* initialisation a une valeur tres grande */
  plus_faible=9999999.0;
  /* boucle de recherche */
  for (i=0 ; i < nbnotes ; i++)
  {
     if (tab_notes[i] < plus_faible)
     {
       /* on memorise la nouvelle note la plus faible */
       plus_faible=tab_notes[i] ;
       /* on memorise sa case */
       num_plus_faible=i;
     }
  } 

  printf("La plus faible note est : %5.2f\n",plus_faible);
  /* on decale les cases vers la gauche */
  /* a partir de la case contenant la plus faible note */
  for (i=num_plus_faible ; i<nbnotes  ; i++)
      tab_notes[i] = tab_notes[i+1] ;
  /* on actualise le nombre de notes */
  nbnotes--;

/* affichage du resultat */
  printf("Notes restantes:\n");
  for (i=0 ; i<nbnotes ; i++)
    printf("%6.1f",tab_notes[i]);
  printf("\n");
}
