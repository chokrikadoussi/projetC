---
title: "PISE 2024-2025 - Algorithmique - Interrogation 2"
author: "Chokri KADOUSSI"
date: "20/12/2024"
---

## Exercice 1

```
Début
    Variables nbval, Ensemble[], i, Positif[], nbval_positif en numériques
    ECRIRE "Nombre total de valeurs : "
    LIRE nbval
    REDIM Ensemble[nbval-1]
    Pour i <-- 0 à nbval-1
        ECRIRE "Valeur n°", i+1, " : "
        LIRE Ensemble[i]
    i SUIVANT
    nbval_positif <-- 0
    Pour i <-- 0 à nbval-1
        SI Ensemble[i] > 0 ALORS
            REDIM Positif[nbval_positif]
            Positif[nbval_positif] <-- Ensemble[i]
            nbval_positif <-- nbval_positif + 1
        FINSI
    i SUIVANT
Fin
```

**Valeurs tests :** 5 Valeurs => -8 / 9 / 10 / 3 / -6 ; 3 Valeurs => - 10 / -1 / 0

## Exercice 2

```
Début
    Variables Tab[24], i, j en numériques
    Variable double en booléen
    double <-- Vrai
    TantQue double
        double <-- Faux
        POUR i <-- 0 à 24
            ECRIRE "Valeur n°", i+1, " : "
            LIRE Tab[i]
        i SUIVANT
        POUR i <-- 0 à 23
            POUR j <-- i+1 à 24
                SI Tab[i] = Tab[j] ALORS
                    double <-- Vrai
                FINSI
            j SUIVANT
        i SUIVANT
        SI double ALORS
            ECRIRE "Saisie incorrect, recommencez"
        FINSI
    FinTantQue
    ECRIRE "Tout est ok"
Fin
```

**Valeurs tests :** 8 / 9 / 10 / 3 / 9 ; 8 / 9 / 10 / 3 / 6