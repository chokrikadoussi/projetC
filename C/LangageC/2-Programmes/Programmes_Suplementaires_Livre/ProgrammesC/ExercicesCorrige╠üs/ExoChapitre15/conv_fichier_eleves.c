/* --------------------- */
/* conv_fichier_eleves.c */
/* --------------------- */
#include <stdio.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 2*TAILLE_NOM
#define MAX_ETUDIANTS 50

main()
{
  char nomfichier[20]   ;
  FILE *fichier         ;
  int nbeleves=0,nb     ;
  int code1,code2,code3 ;
  /* declaration du type etudiant */
  struct etudiant {
                 char nom[TAILLE_NOM]       ;
                 char prenom[TAILLE_PRENOM] ;
                 int age                    ;
               } ;
  
  /* declaration du tableau des eleves */
  struct etudiant tab_eleves[MAX_ETUDIANTS] ;
  struct etudiant eleve ;

  /* ==== LECTURE DU FICHIER TEXTE ==== */
  /* --- chargement du fichier --- */
  printf("Nom du fichier texte :");
  scanf("%s",nomfichier);
  fichier=fopen(nomfichier,"r");

  while(! feof(fichier))
  { 
    /* lecture du fichier */
    code1=fscanf(fichier,"%s",eleve.nom);
    code2=fscanf(fichier,"%s",eleve.prenom);
    code3=fscanf(fichier,"%d",&eleve.age);
    if ( (code1!=EOF) && (code2!=EOF) && (code3!=EOF) )
    {
      /* rangement dans le tableau */
      tab_eleves[nbeleves++]=eleve;
    }
  }
  printf("%d 