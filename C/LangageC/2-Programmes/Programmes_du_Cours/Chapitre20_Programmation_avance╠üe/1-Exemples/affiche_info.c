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
#define MAX_CHAINE 50

/* Procédures et fonctions */
void AfficheObjetInfo(char NomObjetInfo[]);
void ListerRep(char NomRep[]);
void TraitementLoginGroup(int UID,int GID, char *ChaineInfo) ;
void TraitementDate(time_t Temps, char *ChaineHeureDate) ;

/* ------------------- */
/* Programme principal */
/* ------------------- */
int main(int argc, char *argv[])
{
 /* Déclaration des variables */
 char NomObjet[MAX_NOM];

 setlocale(LC_ALL,"fr_FR.UTF-8"); /* Prise en charges des caractères accentués UTF8 */
     
 if (argc<2)
   printf("Usage: affiche_info Nom_Objet\n");
 else
 {
   strcpy(NomObjet,argv[1]);

   /* Appel de la procédure d'affichage */
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
 { /* On récupère les informations */
   Type_Objet   = (TableInode.st_mode & S_IFMT);
   Proprietaire = TableInode.st_uid  ;
   Groupe       = TableInode.st_gid  ;
   Taille       = TableInode.st_size ;

   /* Appel du traitement du Login et du Groupe */
   TraitementLoginGroup(Proprietaire,Groupe,Info_Login) ;

   /* Appel du traitement de la date */
   TraitementDate(TableInode.st_mtime, date_heure) ;
   
   /* Affichage des informations */ 
   if (Type_Objet == S_IFDIR)
   { /* Liste du répertoire */

     /* Informations du fichier */
     printf("Répertoire :  ");
     printf("%-*s ",(int)strlen(date_heure),date_heure);
     printf("%-*s ",(int)strlen(Info_Login),Info_Login);
     printf("%10d ",(int)Taille);
     printf("%-*s",(int)strlen(NomObjetInfo),NomObjetInfo);
     printf("\n");



     ListerRep(NomObjetInfo);
   }
   else
   {
     /* Informations du fichier ou le répertoire */
     printf("Fichier    :  ");
     printf("%-*s ",(int)strlen(date_heure),date_heure);
     printf("%-*s ",(int)strlen(Info_Login),Info_Login);
     printf("%10d ",(int)Taille);
     printf("%-*s",(int)strlen(NomObjetInfo),NomObjetInfo);
     printf("\n");
   }
 }
}
/* ------------------------- */
void ListerRep(char NomRep[])
/* ------------------------- */
{
 DIR *Rep  ; /* Descripteur du répertoire */
 struct dirent *Objet ; /* une entrée dans le répertoire */
 char NomObjet[MAX_NOM],TmpNom[MAX_NOM];


 /* Ouverture du répertoire */
 Rep = opendir(NomRep);

 if (Rep == NULL)
 {
   fprintf(stderr,"Erreur d'acces a %s:%s\n",NomRep,strerror(errno));
 }
 else
 {
   do
   {
     /* Lecture d'une entrée dans le répertoire */
     Objet = readdir(Rep);

     if (Objet!=NULL)
     {  /* On récupère le nom de l'objet */
        strcpy(NomObjet,(*Objet).d_name);
        /* On affiche les informations */
        if ((strcmp(NomObjet,".")!=0)&&(strcmp(NomObjet,"..")!=0))
        {
           strcpy(TmpNom,NomRep);
           strcat(TmpNom,"/");
           strcat(TmpNom,NomObjet);
           strcpy(NomObjet,TmpNom);
           AfficheObjetInfo(NomObjet); 
        }
     }
   }
   while(Objet!=NULL);

   /* Fermeture du répertoire */
   closedir(Rep);
 }
}
/* -------------------------------------- */
void TraitementLoginGroup(int UID,int GID, char *ChaineInfo)
/* -------------------------------------- */
{
 /* Variables pour l'utilisateur */
 char NomLogin[MAX_NOM],NomGroupe[MAX_NOM];
 struct passwd UserInfo ;
 struct group GroupInfo ;

 /* --- Traitement du login  --- */
 if (getpwuid(UID) == NULL)
 {
   sprintf(NomLogin,"%8d",UID);
 }
 else
 {
   UserInfo = *getpwuid(UID)         ;
   strcpy(NomLogin, UserInfo.pw_name);
 }

 /* --- Traitement du groupe --- */
 if (getgrgid(GID) == NULL)
 {
   sprintf(NomGroupe,"%8d",GID);
 }
 else
 {
   GroupInfo = *getgrgid(GID)       ;
   strcpy(NomGroupe, GroupInfo.gr_name);
 }
 /* Mise en forme finale */
 sprintf(ChaineInfo,"%8s %8s",NomLogin,NomGroupe);

}
/* ----------------------------- */
void TraitementDate(time_t Temps, char *ChaineHeureDate)
/* ----------------------------- */
{
   /* Variables pour la date */
   time_t nb_sec_TU;
   struct tm heure_jour_mois       ;
   int secondes,minutes,heure,j_mois,mois,annee;
   char ChaineDate[MAX_CHAINE],ChaineHeure[MAX_CHAINE];
   char nom_mois[MAX_CHAINE]       ;

   /* Positionnement de l'environnement */
   /* LANG=fr ou fr_FR                  */
   //setlocale(LC_ALL,"");
   setlocale(LC_ALL,"fr_FR.UTF-8"); /* Prise en charges des caractères accentu?s UTF8 */
      
   /* récupération du nombre de secondes     */
   /* ecoulees depuis 1/1/1970 a 0h 0mn 0sec */
   nb_sec_TU = Temps;
        
   /* récupération des informations */
   heure_jour_mois = *localtime(&nb_sec_TU);

   /* Récupération des champs */
   secondes = heure_jour_mois.tm_sec  ; 
   minutes  = heure_jour_mois.tm_min  ;
   heure    = heure_jour_mois.tm_hour ;
   j_mois = heure_jour_mois.tm_mday       ;
   mois   = heure_jour_mois.tm_mon +1     ;
   annee  = heure_jour_mois.tm_year +1900 ;

   /* récupération du nom du mois */
   strftime(nom_mois,MAX_CHAINE,"%B",&heure_jour_mois);
   /* Limitation du nom a 3 caracteres */
   //nom_mois[3]='\0';

   /* Mise en forme finale de l'heure et de la date */
   sprintf(ChaineHeure,"%02d:%02d",heure,minutes);
   sprintf(ChaineDate ,"%02d-%s-%4d",j_mois,nom_mois,annee);
   sprintf(ChaineHeureDate ,"%s %s",ChaineHeure,ChaineDate);
}

