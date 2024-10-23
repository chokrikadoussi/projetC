#include <stdio.h>
#include <string.h>

int main()
{
  char ch1[]="Bonjour",nomref[]="Dupont";
  char ch2[20], nom[20], prenom[30], nomcomplet[50], pattern[10];
  char *pcar ;
  int i,taille,longueur ;
  char caract;
  
  printf("ch1=|%s|\n",ch1);
  taille=strlen(ch1);
   printf("Taille=%d\n",taille);

  for (i=0;i<taille+1;i++)
  {
    printf("Num %d : %c = %d\n",i,ch1[i],ch1[i]);  
  }

  strcpy(ch2,ch1);
  printf("ch2=%s  taille=%d\n",ch2,strlen(ch2));
  
  printf("Entre un nom et un prenom: ");
  scanf("%s %s",nom,prenom);
  printf("strcmp %s  %s  = %d\n",nom,nomref,strcmp(nom,nomref));
  printf("comparaison 3 carac %s  %s  = %d\n",nom,nomref,strncmp(nom,nomref,3));

  strcat(nomcomplet,nom);
  strcat(nomcomplet," ");
  strcat(nomcomplet,prenom);
  printf("nomcomplet:%s\n",nomcomplet);

  strncpy(ch2,"1234567890",3);
  printf("copie de 3 caract de 1234567890 : %s\n",ch2);

  strcpy(ch2,"");
  strncat(ch2,nom,5);
  strncat(ch2,prenom,1);
  printf("concat des initiales %s et %s : %s\n",nom,prenom,ch2);
  
  fflush(stdin);
  
  printf("caractere a rechercher dans %s :",nom);
  scanf("%c",&caract);
  pcar=strchr(nom,caract);
  printf("resulta recherche 1ere occurence->%s<-\n",pcar);
  pcar=strrchr(nom,caract);
  printf("resulta recherche derniere occurence->%s<-\n",pcar);

  printf("pattern a rechercher dans %s :",nom);
  scanf("%s",pattern);

  longueur=strspn(nom,pattern);
  printf("longueur prefix=%d\n",longueur);
  
  pcar=strpbrk(nom,pattern);
  printf("strpbrk de %s est ->%s<-\n",nom,pcar);


  pcar=strstr(nom,pattern);
  printf("strstr de %s est ->%s<-\n",nom,pcar);

}
