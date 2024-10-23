/* ------- */
/* menu2.c */
/* ------- */
#include <stdio.h>

int main()
{
 int choix ;

 printf("-10- Reservation\n");
 printf("-20- Horaires\n");
 printf("-30- Tarifs\n");
 printf("- 0- quitter\n");
 printf("\nChoix:");
 scanf("%d",&choix);

 switch(choix)
 {
   case 10: printf("Reservation ...\n");
            break ;
   case 20: printf("Horaires ...\n");
            break ;
   case 30: printf("Tarifs ...\n");
            break ;
   case 0 : printf("Au revoir\n");
            break ;
   default : printf("Erreur de saisie\n");
             break ;
 }
}
