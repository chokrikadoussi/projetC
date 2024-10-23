#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM

int main()
{
  struct etudiant {
                    char nom[TAILLE_NOM]       ;
                    char prenom[TAILLE_PRENOM] ;
                    int age                    ;
                  } ;
  
  struct etudiant *p_eleve ;
  
  p_eleve = (struct etudiant *) malloc(sizeof(struct etudiant));


  printf("Entrez un nom:");
  scanf("%s",(*p_eleve).nom);
  
  printf("Entrez un prenom:");
  scanf("%s",(*p_eleve).prenom);
  
  printf("Entrez un age:");
  scanf("%d",&(*p_eleve).age);
  
  printf("Verification saisie :");
  printf("%s %s %d\n",(*p_eleve).nom,(*p_eleve).prenom,(*p_eleve).age);

}
