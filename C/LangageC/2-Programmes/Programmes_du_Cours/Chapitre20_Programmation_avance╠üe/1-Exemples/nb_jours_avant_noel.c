/* --------------------- */
/* nb_jours_avant_noel.c */
/* --------------------- */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#define NB_MAX_CAR 100 

int main()
{
   // Variables pour la date actuelle
  time_t maintenant ;
  struct tm tm_maintenant ;

  // Variables pour la date de Noël
  struct tm tm_Noel = {0}; // Initialisation
  time_t Noel ;

  // Variables pour le calcul de la différence entre les dates
  time_t diff_entre_dates ;
  struct tm tm_diff_entre_dates ;
  int total_nb_jours_restant ;

  // Variables pour le décompte des mois suivants
  struct tm tm_date_mois_suivant = {0}; // Initialisation
  time_t date_mois_suivant ;
  int i=0, tot_nb_jours_mois_suiv=0, tot_nb_jours_mois_suiv_sauve=0 ;
  int Decompte_mois_depasse=0;
  int nb_mois_restant=0, nb_jours_restant=0;

  // Pour l"affichage des dates formatées
  char date_formatee[NB_MAX_CAR];

  /* positionnement de l'environnement contenu dans la variable LANG*/
  /* LANG=fr ou fr_FR pour le francais */
  setlocale(LC_ALL,"");

  // récupération de la date actuelle en temps universel
  maintenant = time (NULL) ;

  // récupération de la date actuelle en structure tm
  tm_maintenant = *localtime (&maintenant);

  // Formatage de la date pour affichage
  strftime (date_formatee, sizeof date_formatee, "%A %d %B %Y (%d/%m/%Y)",&tm_maintenant);
  printf("Nous sommes le             : %s\n",date_formatee);  

  // Initialisation de la date du prochain Noël Année/mois/jour
  tm_Noel.tm_year = tm_maintenant.tm_year;
  tm_Noel.tm_mon  = 12 - 1 ;
  tm_Noel.tm_mday = 25 ;

  // Ajustement de la date de Noël
  Noel = mktime(&tm_Noel);

  // Formatage de la date pour affichage
  strftime (date_formatee, sizeof date_formatee, "%A %d %B %Y (%d/%m/%Y)",&tm_Noel);
  printf("Le prochain Noël sera le   : %s\n",date_formatee);  

  // Calcul de la différence
  // En temps universel
  diff_entre_dates    = difftime(Noel,maintenant)           ;
  // En structure tm
  tm_diff_entre_dates = *gmtime (&diff_entre_dates)   ;

  total_nb_jours_restant = tm_diff_entre_dates.tm_yday ;
  printf("-> Il reste %d jours avant Noël\n",total_nb_jours_restant);

  i = 1;
  tot_nb_jours_mois_suiv = 9999;
  
  // Boucle de traduction du nombre de jours restant en mois et jours
  while ((i<14) && (!Decompte_mois_depasse))
  {
    // Initialisation de la date du prochain Noël Année/mois/jour
    tm_date_mois_suivant.tm_year = tm_maintenant.tm_year;
    tm_date_mois_suivant.tm_mon  = tm_maintenant.tm_mon +i ;
    tm_date_mois_suivant.tm_mday = tm_maintenant.tm_mday ;

    // Ajustement de la date
    date_mois_suivant = mktime(&tm_date_mois_suivant);

    // Calcul de la différence
    // En temps universel
    diff_entre_dates = difftime(date_mois_suivant,maintenant);
    // En structure tm
    tm_diff_entre_dates = *gmtime (&diff_entre_dates)   ;
 
    tot_nb_jours_mois_suiv = tm_diff_entre_dates.tm_yday ;
 
    strftime (date_formatee, sizeof date_formatee, "%A %d %B %Y (%d/%m/%Y)",&tm_date_mois_suivant);

    if (tot_nb_jours_mois_suiv > total_nb_jours_restant) 
        Decompte_mois_depasse=1;
    else
        tot_nb_jours_mois_suiv_sauve=tot_nb_jours_mois_suiv;
    i++;
  }
  nb_mois_restant  = i-2;
  nb_jours_restant = total_nb_jours_restant-tot_nb_jours_mois_suiv_sauve;

  printf("-> soit %d mois et %d jours avant Noël\n",nb_mois_restant,nb_jours_restant);
} 
