/* -------- */
/* chaine.c */
/* -------- */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

main()
{
  char Nom[10],Prenom[10];
  char NomComplet[20];
  char InitialeNom, InitialePrenom ;
  int longueur ;

  /* Saisie du Nom et du Prenom */
  printf("Entrez Nom : ")   ;
  scanf("%s",Nom)           ;
  printf("Entrez Prenom : ");
  scanf("%s",Prenom);

  /* recuperation des initiales */
  InitialeNom    = toupper(Nom[0])   ;
  InitialePrenom = toupper(Prenom[0]);

  /* Mise a jour des Initiales */
  Nom[0]    = InitialeNom    ;
  Prenom[0] = InitialePrenom ;

  /* concatenation du Nom et Prenom */
  strcpy(NomComplet,Prenom) ;
  strcat(NomComplet," ")    ;
  strcat(NomComplet,Nom)    ;

  /* calcul de la longueur du Nom */
  longueur=strlen(Nom) ;

  /* affichage */
  printf("Le Nom complet est : %s\n",NomComplet);
  printf("Les initiales sont : %c%c\n",InitialePrenom,InitialeNom);
  printf("Longueur du nom    : %d\n",longueur);
}

