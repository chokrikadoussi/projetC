#include <stdio.h>
int main()
{
	char choix ;

	printf("Entrez votre choix (a, b ou c) : ");
	scanf("%c",&choix);

	switch (choix)
	{
	  case 'a' : printf("Horaires\n");
	           break ;
	  case 'b' :
	  case 'c' : printf("Reservation & Tarifs\n");
	           break ;
	  default: printf("Choix Impossible\n");
	           break ;
	}
}
