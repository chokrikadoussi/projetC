/* --------------------- */
/* affiche_directives2.c */
/* --------------------- */
#include <stdio.h>

#define LINUX 0
#define AIX 1
#define WINDOWS 2

#define SYSTEME LINUX

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
#endif

#ifdef REPERTOIRE
printf("REPERTOIRE=%s\n",REPERTOIRE);
#endif
}
