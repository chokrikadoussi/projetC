#include <stdio.h>
int main()
{
	char c1,c2;
	int i ;

	printf("Entrez une lettre : ");
	c1=getchar();
	i=c1   ;
	c2=--i ;
	printf("Le caractere precedent est : ");
	putchar(c2);

	printf("\n");
}
