#include <stdio.h>
int main()
{
	int nb, filtre, resultat;

	printf("Entrez le nombre à filtrer : ");
	scanf("%d",&nb);
	filtre = 0177  ;
	resultat = nb & filtre ;
	printf("resultat : %d\n",resultat);
}
