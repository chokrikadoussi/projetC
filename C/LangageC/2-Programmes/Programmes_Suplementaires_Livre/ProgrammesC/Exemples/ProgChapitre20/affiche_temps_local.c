/* --------------------- */
/* affiche_temps_local.c */
/* --------------------- */
#include <stdio.h>
#include <time.h>

main()
{
 time_t tp,nbsec;
 struct tm hjm ;
 
 nbsec=time(&tp);

 hjm=*localtime(&nbsec);

 printf("%02d:%02d:%02d\n",hjm.tm_hour,hjm.tm_min,hjm.tm_sec);
 
 printf("tzname[0]: %s\n",tzname[0]);
 printf("tzname[1]: %s\n",tzname[1]);
 printf("timezone: %d\n",timezone);
 printf("daylight: %d\n",daylight);
}
