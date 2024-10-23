/* -------------- */
/* selection_jo.c */
/* -------------- */
#include <stdio.h>
#define LIMITE_H_H 2
#define LIMITE_H_M 15
#define LIMITE_F_H 2
#define LIMITE_F_M 35

int main()
{
 char Sexe ;
 int Heures, Minutes ;
 int Selection_Homme,Selection_Femme  ;
 float MeilleurTemps,LimiteH,LimiteF  ;

 LimiteH=LIMITE_H_H+(LIMITE_H_M/60.0);
 LimiteF=LIMITE_F_H+(LIMITE_F_M/60.0);

 printf("Home ou Femme (H/F) :");
 scanf("%c",&Sexe);
 
 printf("Meilleure performance (2h 25m):");
 scanf("%dh %dm",&Heures,&Minutes);
 MeilleurTemps = Heures+(Minutes/60.0);

 /* utilisation de deux booleens */
 Selection_Homme = (Sexe=='H')&&(MeilleurTemps<=LimiteH);
 Selection_Femme = (Sexe=='F')&&(MeilleurTemps<=LimiteF);
 
 if (Selection_Homme || Selection_Femme)
	 printf("Vous 