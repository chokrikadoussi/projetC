#include <stdio.h>
int main()
{
	unsigned char c1;
	signed char c2  ;
	int i1, i2 ;


	c1 = -1 ;
	c2 = -1 ;

	i1 = c1 ;  /* 255 */
	i2 = c2 ;  /*  -1 */


    printf("i1 = %d\n",i1);
    printf("i2 = %d\n",i2);
}
