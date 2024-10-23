/* ------------ */
/* heure_date.c */
/* ------------ */

#include <stdio.h>
#include <time.h>
#include <locale.h>

#define NB_MAX_CAR 40 

main()
{
  size_t resultat ;
  time_t nb_secondes_Temps_Universel, tp ;

  struct tm heure_jour_mois ;
  int secondes, minutes, heure ;
  int jour_du_mois, mois, annee ;
  int num_jour_semaine, jour_de_l_annee, heure_d_ete ;

  char nom_jour_semaine[NB_MAX_CAR] ;
  char nom_mois[NB_MAX_CAR] ;

  /* positionnement de l'environnement contenu dans la variable LANG */
  /* LANG=fr ou fr_FR pour le francais */
  setlocale(LC_ALL,"");

  /* recuperation du nombre de secondes ecoulees */
  /* depuis 1/1/1970 a 0h 0mn 0sec */
  nb_secondes_Temps_Universel = time(&tp);

  /* recuperation des informations */
  heure_jour_mois = *localtime(&nb_secondes_Temps_Universel);

  /* recuperation du nom du jour de la semaine */
  resultat = strftime(nom_jour_semaine,NB_MAX_CAR,"%A",&heure_jour_mois);
  /* recuperation du nom du mois */
  resultat = strftime(nom_mois,NB_MAX_CAR,"%B",&heure_jour_mois);

  /* recuperation des champs */
  secondes = heure_jour_mois.tm_sec  ;
  minutes  = heure_jour_mois.tm_min  ;
  heure    = heure_jour_mois.tm_hour ;

  jour_du_mois = heure_jour_mois.tm_mday       ;
  mois         = heure_jour_mois.tm_mon +1     ;
  annee        = heure_jour_mois.tm_year +1900 ;

  num_jour_semaine = heure_jour_mois.tm_wday     ;
  jour_de_l_annee  = heure_jour_mois.tm_yday +1  ;
  heure_d_ete      = heure_jour_mois.tm_isdst    ;


  /* affichage de tous les champs */

  printf("Heure : %02d:%02d:%02d\n",heure,minutes,secondes);
  printf("Date  : %02d/%02d/%04d\n",jour_du_mois,mois,annee);
  printf("     -> %02d %s %04d\n",jour_du_mois,nom_mois,annee);

  printf("Jour de la semaine : %s\n",nom_jour_semaine);
  printf("                  -> %d 