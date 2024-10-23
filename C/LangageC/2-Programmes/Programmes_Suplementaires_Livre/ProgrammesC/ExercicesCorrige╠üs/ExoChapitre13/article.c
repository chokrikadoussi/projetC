/* --------- */
/* article.c */
/* --------- */
#include <stdio.h>
#include <math.h>
#define NBPRODUITS 20
#define PRIXMAX 9999999

main()
{
  struct produit
         {
          char libelle[10] ;
          float prix       ;
          int quantite     ;
         };

  struct produit article, tab_articles[NBPRODUITS];
  int nbarticles=0, finir_saisie=0, i=0 ;
  int numcase=0 ;
  float prix_recherche,diff2,difference=PRIXMAX ;

  /* === programme === */
  /* boucle de saisie */
  while (! finir_saisie)
  {
     printf("Entrez un libelle d'article (fin pour terminer):");
     scanf("%s",article.libelle);

     finir_saisie=((strcmp(article.libelle,"fin"))==0);

     /* si la saisie n'est pas finie */
     /* on demande le reste des informations */
     if (! finir_saisie)
     {
        printf("Entrez un prix:");
        scanf("%f",&article.prix);
        printf("Entrez une quantite:");
        scanf("%d",&article.quantite);
        tab_articles[i]=article ;
        i++ ;
     }
  }
  /* on met a jour la variable de controle du tableau */
  nbarticles = i ;

  /* saisie de prix a rechercher */
  printf("Prix a rechercher : ");
  scanf("%f",&prix_recherche);

  /* boucle de recherche */

  for (i=0 ; i < nbarticles ; i++)
  {
    diff2=fabs(prix_recherche-tab_articles[i].prix) ;
    if (diff2<difference)
    {
      difference=diff2;
      numcase=i;
    }
  }

  printf("Resultat de la recherche :\n");
  printf("%10s ",tab_articles[numcase].libelle);
  printf("%6.2f ",tab_articles[numcase].prix);
  printf("%3d\n",tab_articles[numcase].quantite);
}
