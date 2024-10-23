/* ---------------- */
/* processus_fils.c */
/* ---------------- */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

main()
{/* ----- Declaration --- */
 pid_t   pid;
 char rep[10],choix;

 /* Creation du processus fils */
 pid = fork ();

 if (pid > 0)
 {
  choix='1';
  while(choix !='0')
  {
    /* Processus pere */
    printf("---Processus p