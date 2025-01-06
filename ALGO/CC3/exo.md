---
title: "PISE 2024-2025 - Algorithmique - Interrogation 3"
author: "Chokri KADOUSSI"
date: "06/01/2025"
---

## Exercice 1

```
Fonction EstPalindrome(chaine en caractère) en booléen
    Variables i, long en numériques
    Variable pal en booléen
    pal <-- VRAI
    long <-- len(chaine)
    POUR i <-- 1 à Ent(long/2)
        SI mid(chaine, i, 1) != mid(chaine, long - i + 1, 1) ALORS
            pal <-- FAUX
        FINSI
    i SUIVANT
    RENVOYER pal
FinFonction
```

**Valeurs tests :** radar / camion / " "

## Exercice 2

```
Fonction CommunCaractere(textA, textB en caractères) en caractère
    Variables commun, lettre en caractères
    Variable i en numérique
    commun <-- ""
    POUR i <-- 1 à len(textA)
        lettre <-- mid(textA, i, 1)
        SI trouve(textB, lettre) != 0 ET trouve(commun, lettre) = 0 ALORS
            commun <-- commun & lettre
        FINSI
    i SUIVANT
    RENVOYER commun
FinFonction
```

**Valeurs tests :** bonjour ; monsieur / bonjour ; ciel