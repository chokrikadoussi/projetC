/***************************************************************/
/*                                                             */
/*   Ce fichier est le fichier de definition du programme      */
/*   serveur_scolarite.c qui permet de creer les               */
/*   comptes nominatifs                                        */
/*                                                             */
/*  Jacquenod Frederic CICRP 05/97                             */
/*  email : jacqueno@cicrp.jussieu.fr                          */
/*  http  : http://www.cicrp.jussieu.fr/jacqueno               */
/*                                                             */
/***************************************************************/


/* Librairies standards permettant de faire appel a des fonctions */
/* predefinies */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


/* definition pour le cryptage du password */
#define      rand    random
#define      srand   srandom

/* Constantes du programmes */
#define VRAI 1
#define FAUX 0

/* Defini le groupe si il n'est reference nulle part */
#define UNKNOWN "UNKNOWN"

/* Destinataire des courriers en cas de problemes */
#define DEST_MAIL "jacqueno"

/* Chemin pour envoyer un courrier */
#define MAILER "/bin/mail"

/* Fichier nul */
#define FIC_NULL "/dev/null"

/* Commandes systeme pour la creation du compte et du group */
#define MKUSER "/bin/mkuser"
#define MKGROUP "/bin/mkgroup"
#define CHGROUP "/bin/chgroup"
#define CREATFS "/home/admin/cicadm/FRED/SCOLARITE3/LV/creat_group.ksh"
#define USER_MACHINE "/home/admin/cicadm/FRED/SCOLARITE3/DATA/user_machine"
#define GROUPE_MACHINE "/home/admin/cicadm/FRED/SCOLARITE3/DATA/groupe_machine"

/* Constantes pour la definition des tailles des variables */

/* Nombre de champ fournit dans le fichier de mise a jour de la scolarite */
#define NB_CHAMP 10

/* Longueur de la date et de l'heure */
#define LongForme 18 


/* Taille max d'un nom */
#define NB_MAX_NOM 50 

/* Taille max d'un prenom */
#define NB_MAX_PRENOM 50

/* Taille max d'un libelle de diplome */
#define NB_MAX_LIBELLE 100 

/* Nombre maximun d'elements dans le fichier passwd */
#define NB_ELET_PASSWD 100000

/* Nombre maximum d'utilisateurs par groupe */
#define LIMITE_USER_GROUPE 230 

/* Nombre maximum de groupes auxquels peut appartenir un user */
#define NB_GROUPE_DOSSIER 20

/* Taille max d'un nom de login */
#define TAILLE_LOGIN 8 

#define TAILLE_MAX 200
#define TAILLE_MAX_MAX 400
#define TAILLE_MED 80
#define TAILLE_TYPE_DIPLOME 30
#define TAILLE_MIN 20

/* Taille max d'un nom de groupe */
#define TAILLE_GROUPE 9 

/* 2500 represente 300 user * 8 caracteres + un rabe pour les virgules */
#define NB_TAILLE_UN_GROUPE_MAX 3500

/* Nombre max de groupes dans le fichier group */
#define NB_GROUPE_MAX 5000

/* Separateur possible dans le fichier fournit par la scolarite */
#define SEPARATEUR ':' 
#define SEPARATEURMAJ '~' 

/* Separateur entre les logins dans un meme groupe */
#define VIRGULE ','

/* Type du diplome pour un deug */
#define DEUG "D.E.U.G"

/* Chemin pour les fichiers de donnees */
#define DATA "/home/admin/cicadm/FRED/SCOLARITE3/DATA"

/* Chemin pour les fichiers de donnees */
#define RESULTAT "/home/admin/cicadm/FRED/SCOLARITE3/RESULTAT"

/* Chemin pour les fichiers de resultats pour le CICRP */
#define AIX "/home/distribg/distrib/SCOLARITE/AIX"

/* Nom du fichier de donnees pour le client */
#define FIC_CLIENT "donnees_client" 

/* Nom du fichier contenant la correspondance numero ufr -> nom groupe */
#define FICHIER_UFR_P6 "ufr_P6"
#define FICHIER_UFR_P7 "ufr_P7"

/* Argument passe au programme */
#define P6 "P6"
#define P7 "P7"

/* Fichier contenant les donnees fournies par la scolarite */
#define FICHIER_DONNEES_P6 "maj_P6"
#define FICHIER_DONNEES_P7 "maj_P7"

/* Fichiers contenant les noms ou les numeros de user et de groupe */
#define FICHIER_UID_NOM "uid.nom"
#define FICHIER_UID_UID "uid.uid"
#define FICHIER_GID_NOM "gid.nom"
#define FICHIER_GID_GID "gid.gid"

/* Fichier contenant les numeros des etudiants (carte etudiant) et les groupes */
/* dans lesquels ils sont */
#define FICHIER_NUM_DOSSIER "dossier.groupe"

/* Fichier contenant les user non traite pour cause de probleme */
#define FIC_USER_NON_TRAITE "non_traite"

/* Liste des diplomes de P6 et des lettres qui leurs sont associees */
#define FIC_TYPE_DIPLOME_P6 "type_diplome_P6"

/* Liste des diplomes de P7 et des lettres qui leurs sont associees */
#define FIC_TYPE_DIPLOME_P7 "type_diplome_P7"

/* Fichier contenant les groupes deja existant */
#define FIC_GROUP "group"

/* Fichier contenant les password deja existant */
#define FIC_PASSWD "passwd"

/* Commandes permettant de recuperer les differents elements mis dans les fichiers */
/* uid.nom ... */

#define RECUP_PASSWD_NOM "/bin/cat /home/admin/cicadm/FRED/SCOLARITE3/DATA/passwd | cut -f1 -d\":\""
#define RECUP_PASSWD_UID "/bin/cat /home/admin/cicadm/FRED/SCOLARITE3/DATA/passwd | cut -f3 -d\":\""
#define RECUP_GROUP_NOM "/bin/cat /home/admin/cicadm/FRED/SCOLARITE3/DATA/group | cut -f1 -d\":\""
#define RECUP_GROUP_GID "/bin/cat /home/admin/cicadm/FRED/SCOLARITE3/DATA/group | cut -f3 -d\":\""

/* Racine du directory d'un utilisateur */
#define HOME "/home"

/* Les fichiers crees */
#define passwdcicrp "/home/distribg/distrib/SCOLARITE/RESULTAT/passwd.cicrp"
#define securitypasswdcicrp "/home/distribg/distrib/SCOLARITE/RESULTAT/securitypasswd.cicrp"
#define passwdnormalise "/home/distribg/distrib/SCOLARITE/RESULTAT/passwd.normalise"
#define dossiergroupe "/home/distribg/distrib/SCOLARITE/RESULTAT/dossier.groupe"
#define groupcicrp "/home/distribg/distrib/SCOLARITE/RESULTAT/group.cicrp"
#define MAXUIDP6 "/home/admin/cicadm/FRED/SCOLARITE3/DATA/max_uidP6"
#define MAXGIDP6 "/home/admin/cicadm/FRED/SCOLARITE3/DATA/max_gidP6"
#define MAXUIDP7 "/home/admin/cicadm/FRED/SCOLARITE3/DATA/max_uidP7"
#define MAXGIDP7 "/home/admin/cicadm/FRED/SCOLARITE3/DATA/max_gidP7"

/* Nombre d'utilisateurs max pour P6 */
#define UIDDEBP6 70000

/* Nombre d'utilisateurs max pour P7 */
#define UIDDEBP7 70000

/* Shell par defaut pour les utilisateurs */
#define SHELL "/bin/ksh"

/* Numero de groupe par defaut en cas de probleme */
#define NUMERO_GROUPE_DEFAUT -10

/* Directives de compilation */
#define DEBUG 0
#define DEBUGControlegroupe 0
#define DEBUGLectureufr 0
#define DEBUGLectureugroup 0
#define DEBUGLecturedonnees 0
#define DEBUGCherchegroupe 0
#define DEBUGRecup_UID_et_GID 0
#define DEBUGCharge_UID 0
#define DEBUGCharge_GID 0
#define DEBUGCreation_nom 0
#define DEBUGCreation_compte 0
#define DEBUGrecupe_dossier 0
#define DEBUGrecupe_type_diplome 0
#define DEBUGTrouve_numero_groupe 0
#define DEBUGaix 0

#define ECRAN 1
/* Permet de commenter les commandes systemes qui creent le user, group, LV .. */
#define CREATLOCAL 0



/* Declaration de la forme d'une ligne du fichier mise-a-jour fournit */
/* par la scolarite */

typedef struct 
{
 char dossier[TAILLE_MIN];             /* Le numero de dossier (carte etudiant) unique */
 char nom[NB_MAX_NOM];                 /* Nom de l'utilisateur */
 char prenom[NB_MAX_PRENOM];           /* Prenom de l'utilisateur */
 char date_naissance[TAILLE_MIN];      /* Date de naissance */
 char annee[TAILLE_MIN];               /* Annee d'entree a la fac */
 char code_diplome[TAILLE_MIN];        /* code numerique du diplome */ 
 char numero_ufr[TAILLE_MIN];          /* Code referencant son ufr d'appartenance */ 
 char libelle_diplome[NB_MAX_LIBELLE]; /* Libelle du diplome qu'il prepare */
 char type_diplome[TAILLE_TYPE_DIPLOME];        /* Type de diplome prepare */
 char code_interne[TAILLE_MIN];        /* Code interne a la scolarite */
 char groupe[TAILLE_MIN];              /* Futur groupe de l'utilisateur non connu au depart */
}ligne;

/* Declaration d'un tableau d'utilisateur */
/* ligne user[NB_ELET_PASSWD]; */

/* Tableau contenant les elements du fichier ufr */
typedef struct
{
 char code_ufr[TAILLE_MED];     /* Code de reference de l'ufr */
 char libelle_ufr[TAILLE_MED];  /* Libelle de l'ufr pour la creation du groupe */
}ufr;

/* Declaration d'un tableau d'ufr */
ufr Tab_ufr[TAILLE_MAX];

/* Tableau contenant les elements du fichier FICHIER_NUM_DOSSIER */
typedef struct
{
 char numero_dossier[TAILLE_MED]; /* Numero unique referencant l'utilisateur (carte etudiant) */
 char login[10];                  /* Login de l'utilisateur */
 char groupe[NB_GROUPE_DOSSIER][TAILLE_GROUPE + 1]; /* Ensemble de groupe auxquels appartient l'utilisateur */
  int nb_groupe;                  /* Nombre de groupes auxquels appartient cet utilisateur */ 
}Un_dossier_groupe;

/* Declaration d'un tableau de dossiers */
/* Un_dossier_groupe Tab_numero_dossier[NB_ELET_PASSWD]; */

/* Tableau contenant les elements du fichier passwd */
typedef struct
{
 char nom[TAILLE_MED];  /* login de l'utilisateur */
 unsigned long int uid; /* Uid correspondant */
}uidstruct;

/* Declaration d'un tableau de UID */
/* uidstruct Tab_uid[NB_ELET_PASSWD]; */

/* Tableau contenant les elements du fichier group */
typedef struct
{
 char nom[TAILLE_MED];   /* Nom du groupe */
 unsigned long int gid;  /* Gid du groupe */
}gidstruct;

/* Declaration d'un tableau de GID */
gidstruct Tab_gid[TAILLE_MAX_MAX];

/* Structure definissant l'etat du fichier /etc/group */
typedef struct
{
 char nom[TAILLE_MIN];                  /* login de l'utilisateur */
 char etat[TAILLE_MIN];                 /* Password ou caractere de desactivation ! */
 unsigned long int gid;                 /* Gid du groupe */
 char lesnoms[NB_TAILLE_UN_GROUPE_MAX]; /* Ensemble des login affecte a ce groupe */
 int nbnoms;                            /* Nombre de login dans le groupe */
}ungroupe;

/* Declaration d'un tableau de groupe */
ungroupe Tab_group[NB_GROUPE_MAX];
 
/* Tableau contenant les types de diplomes et la lettre correspondante */
typedef struct
{
 char intitule[TAILLE_MED];   /* Intitule du diplome */
 char lettre[TAILLE_MED];     /* Lettre affecte a ce diplome */
}type_diplomestruct;

/* Declaration d'un tableau de type de diplome */
type_diplomestruct Tab_type_diplome[TAILLE_MED];


/* Structure pour un login */
typedef struct
{
 char login[TAILLE_LOGIN];             /* Login de l'utilisateur */
 unsigned long int uid;                /* Uid */
 char groupe[TAILLE_MED];              /* Groupe d'appartenance */
 int groupenum;                        /* Numero du groupe */
 char gecos[TAILLE_MAX];               /* Informations sur l'utilisateur gecos */
 char home[TAILLE_MED];                /* Home directory */
 char shell[TAILLE_MED];               /* Shell de connexion */ 
 char passwd[TAILLE_MIN];              /* Password de l'utilisateur */
 char numero_dossier[TAILLE_MED];      /* Numero de dossier (carte etudiant) */  
 char libelle_diplome[NB_MAX_LIBELLE]; /* Libelle du diplome */
 char type_diplome[TAILLE_TYPE_DIPLOME];        /* Type du diplome */
}info_user;

/* Declaration d'un tableau de login */
info_user login_user[NB_ELET_PASSWD];

/* Structure pour un couple nb_user:machine */
typedef struct
{
 int nb_user_machine;
 char machine[TAILLE_MIN]; 
}structum;

/* Declaration d'un tableau de user_machine */
structum tab_um[TAILLE_MIN];

/* Structure pour un couple groupe:machine */
typedef struct
{
 char groupe_machine[TAILLE_GROUPE];
 char machine[TAILLE_MIN]; 
}structgm;

/* Declaration d'un tableau de groupe_machine */
structgm tab_gm[NB_GROUPE_MAX];


/* Nombre d'utilisateur */
int nb_user=0;

/* Nombre de machines au CICRP */
int nb_machine;

/* Nombre de groupes sur les machines du CICRP */
int nb_groupe_machine;

/* Nombre de dossier */
int nb_numero_dossier=0;

/* Nombre de type de diplome */
int nb_type_diplome=0;

/* Nombre de nouveau utilisateurs traites */
int nb_new_user=0;

/* Nombre d'ufr repertoriee */
int nb_ufr=0;

/* Nombre d'uid total */
int nb_uid=0;

/* Nombre de gid total */
int nb_gid=0;

/* Nombre de groupe total */
int nb_groupe=0;

/* Dernier uid trouve */
unsigned long int last_uid=0;

/* Dernier gid trouve */
unsigned long int last_gid=0;

/* Type universite P6 ou P7 */
char univ[3];

/* Fichier de debbugage */
FILE *FDEBUG;

