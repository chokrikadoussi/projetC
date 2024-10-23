/* -------------------- */
/* trouve_date_future.c */
/* -------------------- */
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define NB_MAX_CAR 40 

int main() 
{
  int secondes=0, minutes=0, heure=0 ;
  int jour_du_mois, mois, annee      ;
  int nb_jours_ajout = 0             ;
  int nb_heures_ajout, nb_minutes_ajout, nb_secondes_ajout;
  time_t nb_secondes_Temps_Universel ;
  struct tm Date_Saisie              ;

  struct tm heure_jour_mois ;
  size_t resultat ;

  char nom_jour_semaine[NB_MAX_CAR] ;
  char nom_mois[NB_MAX_CAR] ;
  int num_jour_semaine, jour_de_l_annee, heure_d_ete ;


  /* positionnement de l'environnement contenu dans la variable LANG*/
  /* LANG=fr ou fr_FR pour le francais */
  setlocale(LC_ALL,"");

  /* Saisie de la date */
  printf("Entrez une date (ex: 03/05/2021) : ") ;
  scanf("%d/%d/%d",&jour_du_mois,&mois,&annee)  ;

  Date_Saisie.tm_mday = jour_du_mois;
  Date_Saisie.tm_mon  = mois -1     ;
  Date_Saisie.tm_year = annee -1900 ;

  Date_Saisie.tm_hour = 0    ;
  Date_Saisie.tm_min  = 0    ;
  Date_Saisie.tm_sec  = 0    ; 

  /* récupération du nombre de secondes écoulées */
  /* depuis 1/1/1970 a 0h 0mn 0sec */
  nb_secondes_Temps_Universel = mktime( &Date_Saisie );
  printf( "Nom de secondes en temps universel : %ld\n", nb_secondes_Temps_Universel );


  printf("Entrez le nombre de jours à ajouter à cette date : ") ;
  scanf("%d",&nb_jours_ajout)  ;

  /* Conversion en nombre de secondes */
  nb_heures_ajout   = nb_jours_ajout * 24 ;
  nb_minutes_ajout  = nb_heures_ajout * 60;
  nb_secondes_ajout = nb_minutes_ajout * 60;

  nb_secondes_Temps_Universel+=nb_secondes_ajout;

  // récupération des informations de la nouvelle date 
  heure_jour_mois = *localtime(&nb_secondes_Temps_Universel);

  // récupération du nom du jour de la semaine 
  resultat = strftime(nom_jour_semaine,NB_MAX_CAR,"%A",&heure_jour_mois);
  // récupération du nom du mois 
  resultat = strftime(nom_mois,NB_MAX_CAR,"%B",&heure_jour_mois);

  // récupération des champs 
  secondes = heure_jour_mois.tm_sec  ;
  minutes  = heure_jour_mois.tm_min  ;
  heure    = heure_jour_mois.tm_hour ;

  jour_du_mois = heure_jour_mois.tm_mday       ;
  mois         = heure_jour_mois.tm_mon +1     ;
  annee        = heure_jour_mois.tm_year +1900 ;

  num_jour_semaine = heure_jour_mois.tm_wday     ;
  jour_de_l_annee  = heure_jour_mois.tm_yday +1  ;
  heure_d_ete      = heure_jour_mois.tm_isdst    ;

  // affichage de tous les champs 
  printf("--- Nouvelle date ---\n");
  printf("Heure : %02d:%02d:%02d\n",heure,minutes,secondes);
  printf("Date  : %02d/%02d/%04d\n",jour_du_mois,mois,annee);
  printf("     -> %02d %s %04d\n",jour_du_mois,nom_mois,annee);
  printf("Jour de la semaine : %s\n",nom_jour_semaine);
  if (num_jour_semaine==1)
    printf("                  -> %d er jour de la semaine\n",num_jour_semaine);
  else
    printf("                  -> %d ème jour de la semaine\n",num_jour_semaine);
  printf("Jour de l'année    : %d\n",jour_de_l_annee);

  if (heure_d_ete)
        printf("Heure d'été \n");
  else
        printf("Heure d'hiver \n");
            
}