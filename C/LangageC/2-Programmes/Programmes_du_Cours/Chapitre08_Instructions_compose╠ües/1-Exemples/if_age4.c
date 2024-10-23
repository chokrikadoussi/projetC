#include <stdio.h>
int main()
{
	int age ;

	printf("Entrez votre age : ");
	scanf("%d",&age);

	if (age < 16)
	  printf("A l’Ecole \n")    ;
	else
	  if (age >=65)
	  	printf("En Retraite \n");
	  else
	  	printf("En Activite \n");
}
