#include <stdio.h>
#include <locale.h> /* pour setlocale UTF8 */

int main()
{
 char Nom[50] = {0}   ;

 setlocale (LC_ALL, "fr_FR.UTF-8") ; /* fixe la valeur a UTF-8 */

 printf("--- Saisie et affichage ---\n");
 printf("Entrez un nom avec des accents : ");
 scanf("%s",Nom)              ;
 printf("Nom   = %s\n",Nom)   ;
}
