#include <stdio.h>
#include <string.h>

int main()
{
  int i=10,j;
  char *pnom;
  char nom[10],ChaineFormat[20], nomcomplet[15];
  
  printf("Entrez un nom :");
  pnom=gets(nom);
  
  strcpy(nomcomplet,"M. ");
  strcat(nomcomplet,nom);
  
  puts(nomcomplet);

  sprintf(ChaineFormat,"resultat=%d",i);
  puts(ChaineFormat);

  strcpy(ChaineFormat,"10 20");
  sscanf(ChaineFormat,"%d %d",&i,&j);
  printf("i=%d j=%d\n",i,j);
}
