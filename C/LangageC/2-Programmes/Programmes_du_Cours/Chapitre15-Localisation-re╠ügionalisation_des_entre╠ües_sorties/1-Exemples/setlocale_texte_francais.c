#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main ()
{
   wprintf(L"----------------------\n");
   wprintf(L"Locale is : %s\n", setlocale(LC_ALL, "C"));
   wprintf(L"Caractères étendu accentués\n");
   wprintf(L"----------------------\n");
   wprintf(L"Locale : %s\n", setlocale(LC_ALL, "fr_FR.UTF-8"));
   wprintf(L"Caractères étendu accentués\n");
   wprintf(L"----------------------\n");
}

