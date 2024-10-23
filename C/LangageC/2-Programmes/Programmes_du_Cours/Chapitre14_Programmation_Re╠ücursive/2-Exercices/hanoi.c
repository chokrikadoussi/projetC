#include <stdio.h>

void deplacer(int nb_disques, int depart, int arrivee, int intermediaire) ;

int main()
{ 
  int nbd ;

  printf("Entrez le nombre de disques : ");
  scanf("%d",&nbd);
  printf(" coup    déplacement\n");
  printf("--------------------\n");
  deplacer(nbd,1,3,2); /* Appel initial de la procédure */
}
void deplacer(int nb_disques, int depart, int arrivee, int intermediaire)
{ 
  static int coup=0;

  if (nb_disques == 1) /* Déplacement d'un seul disque */
    printf("%4d      %d -> %d\n",++coup,depart,arrivee);
  else /* Déplacement d'une pile de disques */
  { 
    deplacer(nb_disques-1,depart,intermediaire,arrivee);
    deplacer(1,depart,arrivee, intermediaire);
    deplacer(nb_disques-1,intermediaire,arrivee,depart);
  }
}
