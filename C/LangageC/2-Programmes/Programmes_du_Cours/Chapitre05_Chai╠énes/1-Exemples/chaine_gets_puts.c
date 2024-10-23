#include <stdio.h>
#include <string.h>

int main()
{
	char Nom[10], NomComplet[15];
	char *pnom ;

	printf("Entrez Nom : ");
	pnom=gets(Nom)  ;

	strcpy(NomComplet,"M. ") ;
	strcat(NomComplet,Nom) ;

	puts(NomComplet) ;
}
