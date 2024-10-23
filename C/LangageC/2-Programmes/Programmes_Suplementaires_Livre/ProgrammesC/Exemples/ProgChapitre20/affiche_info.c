/* -------------- */
/* affiche_info.c */
/* -------------- */
#include <stdio.h>
#include <string.h>
#include <errno.h>
/* include pour stat() */
#include <sys/stat.h>
#include <sys/types.h>
/* include pour opendir() */
#include <dirent.h>
/* include pour l'heure*/
#include <locale.h>
#include <time.h>
/* include pour groupe et login*/
#include <pwd.h>
#include <grp.h>

#define MAX_NOM 60
#define MAX_CHAINE 20

/* Procedures et fonctions */
void AfficheObjetInfo(char NomObjetInfo[]);
void ListerRep(char NomRep[]);
char *TraitementLoginGroup(int UID,int GID);
char *TraitementDate(time_t Temps);

/* ------------------- */
/* Programme principal */
/* ------------------- */
main(int argc, char *argv[])
{
 /* Declaration des variables */
 char NomObjet[MAX_NOM];

 if (argc<2)
   printf("Usage: affiche_info Nom_Objet\n");
 else
 {
   strcpy(NomObjet,argv[1]);

   /* Appel de la procedure d'affichage */
   AfficheObjetInfo(NomObjet);
 }
}
/* ------------------------------------- */
void AfficheObjetInfo(char NomObjetInfo[])
/* ------------------------------------- */
{
 int code_erreur;
 struct stat TableInode ;
 off_t Taille ;
 short int Type_Objet,Proprietaire,Groupe ;
 /* Variable pour la date */
 char date_heure[MAX_CHAINE];
 /* Variable pour le nom de l'utilisateur */
 char Info_Login[MAX_NOM];

 /* Lecture des informations sur l'objet */
 code_erreur = stat(NomObjetInfo,&TableInode); 

 if (code_erreur==-1)
    fprintf(stderr,"%s:%s\n",NomObjetInfo,strerror(errno));
 else
 { /* On recupere les informations */
   Type_Objet=(TableInode.st_mode & S_IFMT);
   Proprietaire=TableInode.st_uid  ;
   Groupe      =TableInode.st_gid  ;
   Taille      =TableInode.st_size ;

   /* Appel du traitement du Login et du Groupe */
   strcpy(Info_Login,TraitementLoginGroup(Proprietaire,Groupe));

   /* Appel du traitement de la date */
   strcpy(date_heure,TraitementDate(TableInode.st_mtime));
   
   /* Affichage des informations */ 
   if (Type_Objet == S_IFDIR)
   { /* Liste du repertoire */
     ListerRep(NomObjetInfo);
   }
   else
   { /* Informations du fichier */
     printf("%-*s ",strlen(date_heure),date_heure);
     printf("%-*s ",strlen(Info_Login),Info_Login);
     printf("%10d ",Taille);
     printf("%-*s",strlen(NomObjetInfo),NomObjetInfo);
     printf("\n");
   }
 }
}
/* ------------------------- */
void ListerRep(char NomRep[])
/* ------------------------- */
{
 DIR *Rep  ; /* Descripteur du repertoire */
 struct dirent *Objet ; /* une entree dans le repertoire */
 char NomObjet[MAX_NOM],TmpNom[MAX_NOM];

 /* Ouverture du repertoire */
 Rep = opendir(NomRep);

 if (Rep == NULL)
 {
   fprintf(stderr,"Erreur d'acc