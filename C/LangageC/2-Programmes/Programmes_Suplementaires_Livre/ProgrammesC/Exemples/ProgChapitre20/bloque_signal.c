/* --------------- */
/* bloque_signal.c */
/* --------------- */
#include <stdio.h>
#include <signal.h>

/* include pour getpid et getppid */
#include <sys/types.h>
#include <unistd.h>

/* declaration de la fonction */
void ignore(int numsignal) ;

main()
{/* ----- declaration --- */
 char choix,saisie[20] ;
 /* declaration de l'action */
 void (*action)(int);

 /* --- informations sur les processus --- */
 printf("Num