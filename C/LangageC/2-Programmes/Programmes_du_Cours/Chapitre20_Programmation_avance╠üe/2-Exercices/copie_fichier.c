/* --------------- */
/* copie_fichier.c */
/* --------------- */
#include <stdio.h>

int main(int argc, char *argv[])
{
 FILE *fichier1,*fichier2;
 char c;

 /* vérification du nombre d'arguments */
 if (argc<3)
 {
   printf("Usage: %s Fichier1 fichier2\n",argv[0]);
 }
 else
 { /* ouverture des fichiers */
   if ( (fichier1=fopen(argv[1],"r"))==NULL)
   {
     printf("impossible d'ouvrir %s\n",argv[1]);
   }
   else if ( (fichier2=fopen(argv[2],"w"))==NULL)
   {
     printf("impossible d'ouvrir %s\n",argv[2]);
   }
   else
   { /* boucle d'écriture */
     while ((c=getc(fichier1))!=EOF)
           putc(c,fichier2);
   }
 }
}


