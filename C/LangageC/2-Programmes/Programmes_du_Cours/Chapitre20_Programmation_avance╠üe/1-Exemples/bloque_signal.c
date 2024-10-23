/* --------------- */
/* bloque_signal.c */
/* --------------- */
#include <stdio.h>
#include <signal.h>

/* include pour getpid et getppid */
#include <sys/types.h>
#include <unistd.h>

/* déclaration de la fonction */
void ignore(int numsignal) ;

int main()
{/* ----- déclaration --- */
 char choix,saisie[20] ;
 /* déclaration de l'action */
 void (*action)(int);

 /* --- informations sur les processus --- */
 printf("Numéro du processus actuel:%d\n",getpid());
 printf("Numéro du processus père  :%d\n",getppid());

 /* --- traitement des signaux --- */
 action=ignore;

 /* l'action du CTRL-C: Action par défaut */
 signal(SIGINT,SIG_DFL);
 /* l'action du CTRL-Z: fonction ignore() */
 signal(SIGTSTP,ignore);
 printf("La frappe de CTRL-Z est ignoré 4 fois\n");

 /* boucle infinie */
 while(1)
 {
  printf("-1- Inhiber la frappe de CTRL-C\n");
  printf("-2- Activer la frappe de CTRL-C\n");
  printf("-3- Tuer le programme (Kill -9)\n");
  printf("Choix:");
  scanf("%s",saisie);
  choix=saisie[0];
  switch(choix)
  {
    case '1' : signal(SIGINT,SIG_IGN);
               break;
    case '2' : signal(SIGINT,SIG_DFL);
               break;
    case '3' : raise(9);
               break;
    default  : printf("Choix incorrect\n");
               break;
  }
 }
}
/* ---------- */
void ignore(int numsignal)
{
 static int nbCTRLZ=0;
 printf("\nCTRL-Z (%d) Frappe numéro:%d\n",numsignal,++nbCTRLZ);
 if(nbCTRLZ<4)
    signal(SIGTSTP,ignore);
 else
    signal(SIGTSTP,SIG_DFL);
}

