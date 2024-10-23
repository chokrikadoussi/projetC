/* ------------------ */
/* tirage_au_sort.c   */
/* ------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMERO 48

int main()
{
 time_t nb_secondes, tp           ;
 int i, numero_boule, num_tirage  ;
 char lettre                      ;
 int initialisation               ;
 float numero                     ;

 /* récupération du nombre de secondes écoulées */
 /* depuis 1/1/1970 a 0h 0mn 0sec */
 nb_secondes = time(&tp);

 /* Initialisation de la fonction aléaoire */
 initialisation =  nb_secondes ;
 srand(initialisation);

 for (num_tirage=1;num_tirage<5;num_tirage++)
 {
   printf("Tirage numéro %d  ->  ",num_tirage);
   for (i=0;i<7;i++)
   {
    /* rand() retourne un entier compris entre 0 et RAND_MAX */
    numero = rand() ;
    numero_boule = ((numero/RAND_MAX)*MAX_NUMERO)+1 ;
    printf("%2d ",numero_boule);
   }
   printf("\n");
 }
}

