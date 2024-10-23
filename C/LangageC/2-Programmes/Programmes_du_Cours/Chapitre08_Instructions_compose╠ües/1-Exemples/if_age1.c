#include <stdio.h>
int main()
{
	int age ;

	printf("Entrez votre age : ");
	scanf("%d",&age);

	if (age >=65)
	  printf("En Retraite \n")    ;
	else
	  printf("Pas en Retraite \n");
}
