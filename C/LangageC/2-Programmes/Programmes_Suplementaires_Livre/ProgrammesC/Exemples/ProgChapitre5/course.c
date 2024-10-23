/* -------- */
/* course.c */
/* -------- */
#include <stdio.h>

int main()
{
 int Heures, Minutes, Secondes ;
 int NbHeures, NbMin, NbSec ;
 float Temps1, Temps2, Temps3  ;
 float TempsTotal  ;

 printf("Temps du 1er  coureur (1h 15m 30s):");
 scanf("%dh %dm %ds",&Heures,&Minutes,&Secondes);
 Temps1 = Heures+(Minutes/60.0)+(Secondes/3600.0);

 printf("Temps du 2eme coureur (1h 30m 10s):");
 scanf("%dh %dm %ds",&Heures,&Minutes,&Secondes);
 Temps2 = Heures+(Minutes/60.0)+(Secondes/3600.0);

 printf("Temps du 3eme coureur (1h 1m 45s):");
 scanf("%dh %dm %ds",&Heures,&Minutes,&Secondes);
 Temps3 = Heures+(Minutes/60.0)+(Secondes/3600.0);

 TempsTotal = Temps1+Temps2+Temps3;

 /* NbHeures est la partie entiere de TempsTotal */
 NbHeures = TempsTotal ;
 
 /* NbMin est la partie entiere du    */
 /* TempsTotal - le nombre d'heures   */
 NbMin = (TempsTotal-NbHeures)*60 ;
 
 /* NbSec est la partie entiere du                         */
 /* TempsTotal - (le nombre d'heures+le nombre de minutes) */
 NbSec = (TempsTotal-(NbHeures+(NbMin/60.0)))*3600 ;

 printf("Temps Total : %d h %d m %d s\n",NbHeures,NbMin,NbSec);
}
