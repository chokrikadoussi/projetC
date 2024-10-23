/* -------------- */
/* sous_masque2.c */
/* -------------- */
#include <stdio.h>

main()
{
 union trame
 {
   unsigned int complete ;
   unsigned char octets[4];
 };
 /* declaration des variables */
 union trame adr_ip, s_masque ;
 union trame adr_reseau, adr_machine ;
 unsigned int i0,i1,i2,i3 ;

 /* --- affichage des adresses des membres --- */
 printf("Adresse de adr_ip.complete  %p\n",&adr_ip.complete);
 printf("Adresse de adr_ip.octets[0] %p\n",&adr_ip.octets[0]);
 printf("Adresse de adr_ip.octets[1] %p\n",&adr_ip.octets[1]);
 printf("Adresse de adr_ip.octets[2] %p\n",&adr_ip.octets[2]);
 printf("Adresse de adr_ip.octets[3] %p\n",&adr_ip.octets[3]);
 printf("\n");

 /* --- ADRESSE IP --- */
 /* saisie de 4 entiers */
 printf("Entrez une adresse IP (134.155.18.250):");
 scanf("%d.%d.%d.%d",&i3,&i2,&i1,&i0);

 /* affectation dans les octets de l'union */
 adr_ip.octets[0]=i0;
 adr_ip.octets[1]=i1;
 adr_ip.octets[2]=i2;
 adr_ip.octets[3]=i3;

 /* affichage du membre int sur 32 bits */
 printf("adr_ip.complete=%x \n\n",adr_ip.complete);
 
 /* --- SOUS-MASQUE --- */
 /* saisie de 4 entiers */
 printf("Entrez un sous masque (255.255.255.0):");
 scanf("%d.%d.%d.%d",&i3,&i2,&i1,&i0);

 /* affectation dans les octets de l'union */
 s_masque.octets[0]=i0;
 s_masque.octets[1]=i1;
 s_masque.octets[2]=i2;
 s_masque.octets[3]=i3;
 
 /* affichage du membre int sur 32 bits */
 printf("s_masque.complete=%x \n\n",s_masque.complete);

 /* calcul de l'adresse du reseau sur les 4 octets */
 adr_reseau.complete=adr_ip.complete & s_masque.complete ;

 /* calcul de l'adresse de la machine sur les 4 octets */
 adr_machine.complete=adr_ip.complete & ~s_masque.complete ;

 printf("l'adresse  ");
 printf("%d.%d.",adr_ip.octets[3],adr_ip.octets[2]);
 printf("%d.%d",adr_ip.octets[1],adr_ip.octets[0]);
 printf(" est d