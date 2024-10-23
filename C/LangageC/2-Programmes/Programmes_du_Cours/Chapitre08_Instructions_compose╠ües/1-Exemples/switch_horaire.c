#include <stdio.h>
int main()
{
	int choix ;

	printf("Entrez votre choix : ");
	scanf("%d",&choix);

	switch (choix)
	{
	  case 1 : printf("Horaires\n");
	           break ;
	  case 2 :
	  case 3 : printf("Reservation & Tarifs\n");
	           break ;
	  default: printf("Choix Impossible\n");
	           break ;
	}
}
