/* ---------- */
/* init_tab.c */
/* ---------- */
#include <stdio.h>
/* Taille de texte */
#define TAILLE 5000 
/* taille de image */
#define NBLIG 1000
#define NBCOL 500
/* taille de cube */
#define NBX 100
#define NBY 50
#define NBZ 30

main()
{
 int i,j,k,nbcases;

 char texte[TAILLE]      ;
 int image[NBLIG][NBCOL] ;
 int cube[NBX][NBY][NBZ] ;

 printf("Initialisation de TEXTE ...");
 /* Une dimension : 1 boucle */
 nbcases=0;
 for (i=0;i<TAILLE;i++)
 {
     nbcases++;
     texte[i]=' '; 
 }
 printf("%d cases\n",nbcases);

 printf("Initialisation de IMAGE ...");
 /* Deux dimensions : 2 boucles imbriquees */
 nbcases=0;
 for (i=0;i<NBLIG;i++)
     for (j=0;j<NBCOL;j++)
     {
         nbcases++ ;
         image[i][j]=0; 
     }
 printf("%d cases\n",nbcases);

 printf("Initialisation de CUBE ...");
 /* Trois dimensions : 3 boucles imbriquees */
 nbcases=0;
 for (i=0;i<NBX;i++)
     for (j=0;j<NBY;j++)
         for (k=0;k<NBZ;k++)
         {
             nbcases++ ;
             cube[i][j][k]=0; 
         }
 
 printf("%d cases\n",nbcases);
}
