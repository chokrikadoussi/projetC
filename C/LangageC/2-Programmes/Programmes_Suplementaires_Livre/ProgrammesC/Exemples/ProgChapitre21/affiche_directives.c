/* -------------------- */
/* affiche_directives.c */
/* -------------------- */
#include <stdio.h>

#define LINUX 0
#define AIX 1

#define DEBUG 0
#define SYSTEM LINUX

main()
{
#if (DEBUG == 0) && (SYSTEM == LINUX)
printf("DEBUG=%d && SYSTEM=LINUX\n",DEBUG);
#endif

#if (! DEBUG ) && (SYSTEM == LINUX)
printf("! DEBUG && SYSTEM=LINUX\n",DEBUG);
#endif

#if (SYSTEM == LINUX) || (SYSTEM == AIX)
printf("SYSTEM=LINUX || SYSTEM=AIX\n");
#endif
}
