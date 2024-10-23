/* -------------------- */
/* liste_variable_arg.c */
/* -------------------- */
#include <stdio.h>
#include <stdarg.h>

/* declaration de la fonction */
int operation(int nb, char signe,...) ;

/* ------------------------------- */
main()
{
  int res ;

  /* multiplication de 2 arguments */
  res=operation(2,'*',10,20);
  printf(" 10*20       = %d\n",res);

  /* soustraction de 3 arguments */
  res=operation(3,'-',10,20,30);
  printf("-10-20-30    = %d\n",res);

  /* somme de 4 arguments */
  res=operation(4,'+',10,20,30,40);
  printf(" 10+20+30+40 = %d\n",res);
}

/* ------------------------------- */
int operation(int nb, char signe,...)
{
  va_list liste_arg ;
  int arg,resultat=0, i ;

  /* initialisation de la liste */
  va_start(liste_arg,signe);

  /* initialisation du calcul */
  if (signe=='*')
     resultat=1;

  /* boucle de recuperation des arguments */
  /* et de calcul */
  for (i=0 ; i<nb ; i++)
  {
    arg=va_arg(liste_arg, int);
    if (signe=='+')
       resultat+=arg;
    else if (signe=='-')
       resultat-=arg;
    else if (signe=='*')
       resultat*=arg;
  }

  /* nettoyage de la liste */
  va_end(liste_arg);

  return resultat ;
}


