---
title: "PISE 2024-2025 - Algorithmique - Interrogation 1"
author: "Chokri KADOUSSI"
date: "19/11/2024"
---

## Exercice 1

Début
    Variables nom1, nom2 en caractères
    Variables j1, m1, a1, j2, m2, a2 en numériques
    SI a1 = a2 ET m1 = m2 ET j1 = j2 ALORS
        ECRIRE "Les deux personnes ont le même age"
    SINONSI a1 < a2 OU (a1 = a2 ET m1 < m2) OU (a1 = a2 ET m1 = m2 ET j1 < j2) ALORS
        ECRIRE nom1, " est plus âgé(e) que ", nom2
    SINON
        ECRIRE nom2, " est plus âgé(e) que ", nom1
    FINSI
Fin

**Valeurs tests :** 01/01/2000 ET 01/01/2010; 01/01/2000 ET 01/10/2000; 01/01/2000 ET 15/01/2000; 01/01/2000 ET 01/01/2000

## Exercice 2

Début
    Variables pere, mere, enf en numériques
    Variable pere_aristo, mere_aristo en booléens
    ECRIRE "Entrez le rang numérique du père puis de la mère (0 = "Puant", 1 = "Honorable",  2 = "Noble" et 3 = "Soleil"): "
    LIRE pere, mere
    pere_aristo <- pere > 0
    mere_aristo <- mere > 0

    SI mere_aristo ET pere_aristo ALORS
        ECRIRE "Mariage Interdit ! Les parents sont tous deux aristocrates."
    SINON
        SI mere_aristo ALORS
            enf <- mere
        SINONSI pere_aristo ALORS
            enf <- pere - 1
        SINON
            enf <- 0 
        FINSI

        SI enf = 1 ALORS
            ECRIRE "Vos enfants sont des Honorables !"
        SINONSI enf = 2 ALORS
            ECRIRE "Vos enfants sont des Nobles !"
        SINONSI enf = 3 ALORS
            ECRIRE "Vos enfants sont des Soleils !"
        SINON
            ECRIRE "Vos enfants sont des Puants !"
        FINSI
    FINSI
Fin

**Valeurs tests :** 3 ET 3; 0 ET 0; 0 ET 1; 1 ET 0; 3 ET 0