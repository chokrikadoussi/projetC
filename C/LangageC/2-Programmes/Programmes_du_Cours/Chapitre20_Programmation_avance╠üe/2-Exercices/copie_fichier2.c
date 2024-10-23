/* ---------------- */
/* copie_fichier2.c */
/* ---------------- */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
 FILE *fichier1,*fichier2;
 char c;
 int code_erreur=0, num_arg=0;

 /* initialisation de la varaible globale errno */
 errno=0;

 /* vérification du nombre d'arguments */
 if (argc<3)
 {
   printf("Usage: %s Fichier1 fichier2\n",argv[0]);
   code_erreur=EINVAL ; /* Invalid arguments */
   num_arg=0;
 }
 else
 { /* ouverture des fichiers */
   if ((fichier1=fopen(argv[1],"r"))==NULL)
   {
     code_erreur=errno;
     num_arg=1;
   }
   else if ((fichier2=fopen(argv[2],"w"))==NULL)
   {
     code_erreur=errno;
     num_arg=2;
   }
   else
   { 
     /* boucle d'écriture */
     while ((c=getc(fichier1))!=EOF)
           putc(c,fichier2);
   }
 }
 /* affichage d'un message d'erreur */
 if (code_erreur)
 {
   /* affichage de l'erreur sur stderr */
   fprintf(stderr,"erreur sur %s\n",argv[num_arg]);
   fprintf(stderr,"%s\n",strerror(code_erreur));
 }
 exit(code_erreur);
}

