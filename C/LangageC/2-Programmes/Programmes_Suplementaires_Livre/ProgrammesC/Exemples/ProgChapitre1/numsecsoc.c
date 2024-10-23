/* ------------- */
/* numsec.c      */
/* ------------- */

#include <stdio.h>

int main()
{
 /* --- declarations des variables --- */

 char Num_Sec[14], Libelle[9], Nom_Mois[10], Dept[3] ;
 int Sexe, Annee, Mois, Commune, Num_Ordre ;

 /* --- instructions --- */

 /* saisie du numero sous la forme d'une chaine */
 printf("Entrez votre numero de securite sociale : ");
 scanf("%s",Num_Sec);

 /* recuperation du numero 1 ou 2 du Sexe */
 Sexe = Num_Sec[0]-48 ;

 /* Affectation du Libelle */
 if (Sexe == 1)
	 strcpy(Libelle,"Monsieur");
 else
	 strcpy(Libelle,"Madame");

 /* recuperation de l'annee de naissance */

 Annee = ((Num_Sec[1]-48)*10) + (Num_Sec[2]-48) ;
 Annee = Annee + 1900 ;

 /* recuperation du mois de naissance */

 Mois = ((Num_Sec[3]-48)*10) + (Num_Sec[4]-48) ;
 switch (Mois)
 {
   case 1  : strcpy(Nom_Mois,"Janvier");
             break ;
   case 2  : strcpy(Nom_Mois,"Fevrier");
             break ;
   case 3  : strcpy(Nom_Mois,"Mars");
             break ;
   case 4  : strcpy(Nom_Mois,"Avril");
             break ;
   case 5  : strcpy(Nom_Mois,"Mai");
             break ;
   case 6  : strcpy(Nom_Mois,"Juin");
             break ;
   case 7  : strcpy(Nom_Mois,"Juillet");
             break ;
   case 8  : strcpy(Nom_Mois,"Aout");
             break ;
   case 9  : strcpy(Nom_Mois,"Septembre");
             break ;
   case 10 : strcpy(Nom_Mois,"Octobre");
             break ;
   case 11 : strcpy(Nom_Mois,"Novembre");
             break ;
   case 12 : strcpy(Nom_Mois,"Decembre");
             break ;
 }

 /* recuperation du departement             */
 /* qui reste une chaine (corse : 2A ou 2B) */
 Dept[0]=Num_Sec[5] ;
 Dept[1]=Num_Sec[6] ;
 Dept[2]='\0'       ;

 /* recuperation de la Commune */
 Commune = ((Num_Sec[7]-48)*100) + ((Num_Sec[8]-48)*10) + (Num_Sec[9]-48) ;

 /* recuperation du numero d'ordre */
 Num_Ordre = ((Num_Sec[10]-48)*100) + ((Num_Sec[11]-48)*10) + (Num_Sec[12]-48) ;

 /* Affichage des resultats */
 printf("Bonjour                %s\n",Libelle)     ;
 printf("Vous etes ne en        : %d\n",Annee)     ;
 printf("Au mois de             : %s\n",Nom_Mois)  ;
 printf("Dans le departement    : %s\n",Dept)      ;
 printf("Dans la commune        : %d\n",Commune)   ;
 printf("Avec le numero d'ordre : %d\n",Num_Ordre) ;

}

