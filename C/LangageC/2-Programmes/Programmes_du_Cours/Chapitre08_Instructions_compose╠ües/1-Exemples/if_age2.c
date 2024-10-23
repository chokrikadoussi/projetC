#include <stdio.h>
int main()
{
	int age,nban ;

	printf("Entrez votre age : ");
	scanf("%d",&age);

	if (age >=65)
	  {
		nban=age-65 ;
	    printf("Retraite depuis %d ans\n",nban);
	  }

	else
	  printf("Pas en Retraite \n");
}
