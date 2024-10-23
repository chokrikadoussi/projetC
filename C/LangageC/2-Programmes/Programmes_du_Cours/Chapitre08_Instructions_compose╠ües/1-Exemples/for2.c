#include <stdio.h>
#include <string.h>

int main()
{
  char s[20], c ;
  int i,j       ;

  printf("Entrez un texte:");
  scanf("%s",s);
  
  for (i=0,j=strlen(s)-1 ; i<j ; i++,j--)
  {
    c=s[i]   ;
    s[i]=s[j];
    s[j]=c   ;
    printf("i=%d, j=%d, c=%c  s=%s\n",i,j,c,s);
  }
  printf("Apres traitement: %s\n",s);
}
