/* ------------ */
/* word_count.c */
/* ------------ */
#include <stdio.h>
#define LF '\n'
#define CR '\r'
#define ESPACE ' '

main()
{
 int nbmots=0, nblignes=0, nbcaract=0 ;
 char nomfichier1[20],nomfichier2[20] ;
 FILE *fichier1,*fichier2 ;
 char caract ;

 printf("Nom du fichier 