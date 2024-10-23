/* ---------------- */
/* fic_bin_direct.c */
/* ---------------- */
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NBMAX 10
#define NOM_FICHIER "liste_entiers.dat"

main()
{
 FILE *fichier ;
 int i, tabpair[NBMAX],nb,erreur ;
 long int deplacement,nboctets ;
 char message[20];

 /* === production du fichier binaire === */
 printf("Ecriture d'un fichier %s\n",NOM_FICHIER);
 printf("avec les valeurs suivantes\n");

 for (i=0 ; i<NBMAX ; i++)
 {
   tabpair[i]=i*2;
   printf("%4d",i*2);
 }
 printf("\n");

 /* ouverture du fichier en ecriture binaire */
 fichier=fopen(NOM_FICHIER,"wb");

 /* ecriture de la totalite du tableau */
 nb=fwrite(tabpair,sizeof(int),NBMAX,fichier);

 /* fermeture du fichier */
 fclose(fichier);

 /* === acces direct au fichier binaire === */

 /* ouverture du fichier en lecture binaire */
 fichier=fopen(NOM_FICHIER,"rb");

 erreur=0;
 /* positionnement au debut du fichier */
 rewind(fichier);

 while (!erreur)
 {
   printf("Deplacement dans le fichier :");
   scanf("%d",&deplacement);
   /* calcul du deplacement en octets */
   nboctets=deplacement*sizeof(int);

   /* acces direct dans le fichier */
   erreur=fseek(fichier,nboctets,SEEK_CUR);

   if (!erreur)
   {
     /* lecture de l'element suivant */
     nb=fread(&i,sizeof(int),1,fichier);
     printf("valeur lue : %d\n",i);
   }
 }
 /* construction du message */
 sprintf(message,"Acces %s",NOM_FICHIER);

 /* affichage du message d'erreur */
 perror(message);

 /* fermeture du fichier */
 fclose(fichier);
}
