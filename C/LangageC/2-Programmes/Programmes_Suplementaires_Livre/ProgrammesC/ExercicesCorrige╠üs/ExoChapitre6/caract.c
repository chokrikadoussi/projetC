/* -------- */
/* caract.c */
/* -------- */
#include <stdio.h>
#include <ctype.h>

main()
{
 char Majuscule, minuscule ;
 
 printf("Entrez une majuscule :");
 scanf("%c",&Majuscule);
 minuscule=tolower(Majuscule);
 printf("La minuscule est : %c\n",minuscule);
}
