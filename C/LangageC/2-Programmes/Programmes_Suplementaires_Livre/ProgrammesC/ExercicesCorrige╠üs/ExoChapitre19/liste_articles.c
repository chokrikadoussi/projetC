/* ---------------- */
/* liste_articles.c */
/* ---------------- */
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_LIBELLE 20
#define ERROR -1

/* --- sous-programmes --- */
int lecture_fichier();
void tri()   ;
void affichage();

/* --- variables globales --- */
struct article {
             struct article *pred     ;
             char libelle[TAILLE_LIBELLE] ;
             float prix               ;
             int quantite             ;
             struct article *succ     ;
            } ;

struct article *debut_liste,*fin_liste;
int nb_article=0;

/* ===== PROGRAMME ===== */
main()
{
  int retour ;
  debut_liste = NULL;
  fin_liste   = NULL;

  printf("===lecture du fichier===\n");
  retour=lecture_fichier();

  if (retour != ERROR)
  {
    affichage();
    printf("===Tri===\n");
    tri();
    affichage(); 
  }
}
/* === affichage de la liste === */
void affichage()
{
  struct article *article_actuel;
  /* --- boucle d'affichage --- */
  article_actuel=debut_liste ;
  while (article_actuel != NULL )
  {
    printf("%-10s",article_actuel->libelle) ;
    printf("%10.2f",article_actuel->prix)   ;
    printf("%6d\n",article_actuel->quantite);
    article_actuel = article_actuel->succ ;
  } 
}
/* === chargement de la liste === */
int lecture_fichier()
{
  FILE *entree;
  char nomfichier[50];
  struct article *nouv_article,*article_actuel;
  int code1,code2,code3, erreur_code=0 ;

  printf("Fichier:");
  scanf("%s",nomfichier);
  entree=fopen(nomfichier,"r");
  if (entree==NULL)
  {
     printf("Fichier %s non trouv