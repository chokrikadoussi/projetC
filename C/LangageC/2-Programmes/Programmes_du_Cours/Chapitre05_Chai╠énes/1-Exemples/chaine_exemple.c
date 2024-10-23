#include <stdio.h>
#include <string.h>

int main()
{
	char Nom[10],Prenom[20];
	char NomComplet[30];
	char InitialeNom   ;
	int longueur ;

	printf("Entrez Nom : ")   ;
	scanf("%s",Nom)           ;
	printf("Entrez Prenom : ");
	scanf("%s",Prenom);

	strcpy(NomComplet,Prenom) ;
	strcat(NomComplet," ") ;
	strcat(NomComplet,Nom) ;
	InitialeNom= Nom[0]  ;

	longueur=strlen(NomComplet) ;

	printf("Le Nom complet est : %s\n",NomComplet);
	printf("Sa longueur est    : %d\n",longueur);
	printf("L’initiale  est    : %c\n",InitialeNom);
}
