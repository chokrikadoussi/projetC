#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() 
{
 setlocale(LC_ALL,"fr_FR.UTF-8");
 wprintf(L"wprintf : -1- wprintf = OK! Caractères étendus\n");
 printf("printf : -2- Pas d'impression de caractères!\n");
 wprintf(L"wprintf : -3- wprintf = OK! Caractères étendus\n");
 printf("printf : -4- Pas d'impression de caractères!\n");
}
