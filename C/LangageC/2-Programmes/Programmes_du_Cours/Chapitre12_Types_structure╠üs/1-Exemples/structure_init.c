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
  
  struct etudiant eleve = {
                             "Dupont","Alain",28
                          } ;

  printf("Entrez un nom (%s):",eleve.nom);
  scanf("%s",eleve.nom);
  
  printf("Entrez un prenom (%s):",eleve.prenom);
  scanf("%s",eleve.prenom);
  
  printf("Entrez un age (%d):",eleve.age);
  scanf("%d",&eleve.age);
  
  printf("Verification saisie :");
  printf("%s %s %d\n",eleve.nom,eleve.prenom,eleve.age);
}
