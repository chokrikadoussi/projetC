#include <stdio.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM

int main()
{
  struct etudiant {
                    char nom[TAILLE_NOM]       ;
                    char prenom[TAILLE_PRENOM] ;
                    int age                    ;
                  } ;
  
  struct etudiant eleve ;


  printf("Entrez un nom:");
  scanf("%s",eleve.nom);
  
  printf("Entrez un prenom:");
  scanf("%s",eleve.prenom);
  
  printf("Entrez un age:");
  scanf("%d",&eleve.age);
  
  printf("Verification saisie :");
  printf("%s %s %d\n",eleve.nom,eleve.prenom,eleve.age);

}
