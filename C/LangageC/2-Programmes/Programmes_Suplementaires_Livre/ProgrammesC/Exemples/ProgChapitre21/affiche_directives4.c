/* --------------------- */
/* affiche_directives4.c */
/* --------------------- */
#include <stdio.h>

#define LINUX 1
#define AIX 2
#define WINDOWS 3
#define MACOS 4

main()
{
#if SYSTEME == LINUX
#define REPERTOIRE "/var/logs"
#elif SYSTEME == AIX
#define REPERTOIRE "/usr/local/logs"
#elif SYSTEME == WINDOWS
#define REPERTOIRE "c:\\local"
#else
#undef REPERTOIRE
#line 3
#error ERREUR DEFINITION REPERTOIRE
#endif

#ifdef REPERTOIRE
printf("REPERTOIRE=%s\n",REPERTOIRE);
#else
printf("REPERTOIRE NON DEFINI\n",);
#endif
}
