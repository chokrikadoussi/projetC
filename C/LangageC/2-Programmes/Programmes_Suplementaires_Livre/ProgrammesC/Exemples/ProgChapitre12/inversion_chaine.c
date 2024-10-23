/* ------------------ */
/* inversion_chaine.c */
/* ------------------ */
#include <stdio.h>
#include <string.h>

main()
{
 char nom[20], lettre ;
 int i,j ;

 printf("Entrez un nom :");
 scanf("%s",nom);

 for(i=0,j=strlen(nom)-1;i<j;i++,j--)
 {
   lettre=nom[i] ;
   nom[i]=nom[j] ;
   nom[j]=lettre ;
 }

 printf("Nom invers