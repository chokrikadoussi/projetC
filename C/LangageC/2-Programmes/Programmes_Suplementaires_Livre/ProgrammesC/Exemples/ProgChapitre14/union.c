/* ------- */
/* union.c */
/* ------- */
#include <stdio.h>
main()
{
 union personne
 {
   char nom[10] ;
   char prenom[20] ;
   int age ;
 } ;

 union personne salarie ;

 /* saisie du nom */
 printf("Entrez un nom:");
 scanf("%s",salarie.nom);
 /* affichage du contenu de tous les membres */
 printf("Contenu des membres de l'union :\n");
 printf("Nom   :%s\n",salarie.nom);
 printf("Prenom:%s\n",salarie.prenom);
 printf("Age   :%d (hexa %x)\n",salarie.age,salarie.age);

}
