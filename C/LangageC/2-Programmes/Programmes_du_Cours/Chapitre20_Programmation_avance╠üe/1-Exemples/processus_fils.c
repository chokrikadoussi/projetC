/* ---------------- */
/* processus_fils.c */
/* ---------------- */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{/* ----- Déclaration --- */
 pid_t   pid;
 char rep[10],choix;

 /* Création du processus fils */
 pid = fork ();

 if (pid > 0)
 { /* Processus pere */
  choix='1';
  while(choix !='0')
  {
    printf("---Processus père ---\n");
    printf("-1- Numéros des processus\n");
    printf("-2- Hérarchie des processus\n");
    printf("-3- Tuer le processus fils\n");
    printf("-0- Quitter\n");
    printf("Choix:");
    scanf("%s",rep);
    choix=rep[0];
    switch(choix)
    {
      case '1' : printf("Processus shell:%d\n",getppid()); 
                 printf("Processus père :%d\n",getpid()); 
                 printf("Processus fils :%d\n",pid); 
                 break ;
      case '2' : system("ps -f");
                 break ;
      case '3' : kill(pid,SIGKILL);
                 break ;
    }
  }
 }
 else if (pid == 0)
 { /* Processus fils */
  while(1)
  {
    sleep(5);
    printf("FILS:Numéro          :%d\n",getpid());
    printf("FILS:Numéro du père  :%d\n",getppid());
  }
 }
 else
 {
  /* Traitement d'erreur */
  printf("erreur de création du processus fils\n");
 }
}

