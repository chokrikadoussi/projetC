/* ------------- */
/* sous_masque.c */
/* ------------- */
#include <stdio.h>

main()
{
 /* adress IP en 4 elements */
 int ip1,ip2,ip3,ip4 ;
 /* sous masque en 4 elements */
 int sm1,sm2,sm3,sm4 ;
 /* adresse reseau en 4 elements */
 int ar1,ar2,ar3,ar4 ;
 /* adresse machine en 4 elements */
 int am1,am2,am3,am4 ;
 
 printf("Entrez une ipresse IP (134.157.15.38):");
 scanf("%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);
 
 printf("Entrez un sous masque (255.255.255.0):");
 scanf("%d.%d.%d.%d",&sm1,&sm2,&sm3,&sm4);

 /* calcul de l'adresse du reseau */
 ar1 = ip1 & sm1;
 ar2 = ip2 & sm2;
 ar3 = ip3 & sm3;
 ar4 = ip4 & sm4;

 /* calcul de l'adresse de la machine */
 am1 = ip1 & (~sm1) ;
 am2 = ip2 & (~sm2) ;
 am3 = ip3 & (~sm3) ;
 am4 = ip4 & (~sm4) ;

 printf("\nl'adresse %d.%d.%d.%d est d