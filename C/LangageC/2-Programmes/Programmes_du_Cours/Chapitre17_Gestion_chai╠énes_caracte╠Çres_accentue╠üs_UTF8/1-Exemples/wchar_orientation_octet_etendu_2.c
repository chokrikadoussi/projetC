#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() 
{
 setlocale(LC_ALL,"fr_FR.UTF-8");
 printf("printf : -1- printf = OK! Caractères étendus\n");
 wprintf(L"wprintf : -2- Pas d'impression de caractères!\n");
 printf("printf : -3- printf = OK! Caractères étendus\n");
 wprintf(L"wprintf : -4- Pas d'impression de caractères!\n");
}
