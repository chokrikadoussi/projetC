/* ------------------ */
/* tirage_au_sort.c   */
/* ------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMERO 48

main()
{
 time_t nb_secondes, tp           ;
 int i, numero_boule, num_tirage  ;
 char lettre                      ;
 int initialisation               ;
 float numero                     ;

 /* Recuperation du nombre de secondes ecoulees */
 /* depuis 1/1/1970 a 0h 0mn 0sec */
 nb_secondes = time(&tp);

 /* Initialisation de la fonction aleatoire */
 initialisation =  nb_secondes ;
 srand(initialisation);

 for (num_tirage=1;num_tirage<5;num_tirage++)
 {
   printf("Tirage num