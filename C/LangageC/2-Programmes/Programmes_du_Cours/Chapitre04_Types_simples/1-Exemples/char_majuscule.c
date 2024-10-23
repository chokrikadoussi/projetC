#include <stdio.h>
int main()
{
	char c;

	printf("Entrez une lettre : ");
	scanf("%c",&c);

	if ( (c>='A') && (c<='Z') )
	{
		printf("C'est une majuscule\n");
	}
}
