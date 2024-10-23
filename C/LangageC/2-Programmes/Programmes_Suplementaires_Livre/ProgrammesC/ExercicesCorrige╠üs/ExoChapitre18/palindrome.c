/* ------------ */
/* palindrome.c */
/* ------------ */
#include <stdio.h>
#include <stdlib.h>

main()
{
 char *phrase, lettre ;
 char *i,*j ;
 int taille=0, palindrome=1 ;

 /* allocation dynamique */
 phrase=(char *)malloc(30);
 /* saisie */
 printf("Entrez une phrase :");
 i=phrase;
 while ((*i=getchar())!='\n')
 {
   i++ ;
   taille++ ;
 }
 /* ajout du delimiteur de fin de phrase */
 *(phrase+taille)='\0';

 /* Initialisation au debut et a la fin de la phrase */
 i=phrase;
 j=(phrase+taille-1);

 /* boucle de comparaison caractere par caractere */
 /* si deux caracteres different ou si tous les   */
 /* caracteres ont ete compares, on sort          */
 while (palindrome && (i<j))
 {
   palindrome = (*i==*j);
   i++;
   j--;
 }

 if (palindrome)
    printf("\"%s\" est un palindrome\n",phrase);
 else
    printf("\"%s\" n'est pas un palindrome\n",phrase);
}
