/* ------- */
/* menu3.c */
/* ------- */
#include <stdio.h>

main()
{
 char choix ;

 printf("-1- Reservation\n");
 printf("-2- Horaires\n");
 printf("-3- Tarifs\n");
 printf("-q- quitter\n");
 printf("\nChoix:");
 scanf("%c",&choix);

 switch(choix)
 {
   case '1': printf("Reservation ...\n");
             break ;
   case '2': printf("Horaires ...\n");
             break ;
   case '3': printf("Tarifs ...\n");
             break ;
   case 'q' : printf("Au revoir\n");
             break ;
   default : printf("Erreur de saisie\n");
             break ;
 }
}
