#include <stdio.h>
int main()
{
	char c1,c2 ;
	int i      ;

	printf("Entrez une lettre : ");
	scanf("%c",&c1);
	i  = c1  ;
	c2 = --i ;
	printf("Le caractere precedent est : %c\n",c2);
}
