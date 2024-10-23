/* -------------------- */
/* jour_de_la_semaine.c */
/* -------------------- */
#include <stdio.h>

int main()
{
 enum Jour_Semaine { Lundi,
                     Mardi,
                     Mercredi,
                     Jeudi,
                     Vendredi,
                     Samedi,
                     Dimanche };

 enum Jour_Semaine Jour;

 printf("Voici les jours de la semaine\n");
 printf("Lundi    = %d\n",Lundi);
 printf("Mardi    = %d\n",Mardi);
 printf("Mercredi = %d\n",Mercredi);
 printf("Jeudi    = %d\n",Jeudi);
 printf("Vendredi = %d\n",Vendredi);
 printf("Samedi   = %d\n",Samedi);
 printf("Dimanche = %d\n",Dimanche);
 printf("Entrez un jour (Par ex : 0):");

 scanf("%d",&Jour);

   if ((Jour==Samedi)||(Jour==Dimanche))
      printf("Bon Cong