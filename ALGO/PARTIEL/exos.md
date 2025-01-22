---
title: "PISE 2024-2025 - Algorithmique - Partiel"
author: "Chokri KADOUSSI"
date: "22/01/2025"
---

## Exercice 1

```
Fonction Décodage(texte en caractère) en caractère

    Variables decode, Tab_decode[], phrase, lettre en caractères
    Variables dollars_total, debut, fin, nb_mot, pas, i, compteur, dollars en numériques

    nb_mot <-- trouve(texte, "$") - 1
    REDIM Tab_decode[nb_mot]
    POUR i <-- 0 à nb_mot
        Tab_decode[i] <-- ""
    i SUIVANT

    dollars_total <-- 0
    debut <-- 1
    fin <-- nb_mot + 1
    pas <-- fin

    TantQue dollars_total != nb_mot
        dollars <-- 0
        compteur <-- 0
        POUR i <-- debut à fin
            lettre <-- mid(texte, i, 1)
            SI lettre = "$" ALORS
                dollars <-- dollars + 1
            FINSI
            SI mid(Tab_decode[compteur], len(Tab_decode[compteur]), 1) != "$" OU len(Tab_decode[compteur]) = 0 ALORS
                Tab_decode[compteur] <-- Tab_decode[compteur] & lettre
            SINON
                compteur <-- compteur + 1
            FINSI
            compteur <-- compteur + 1
        i SUIVANT
        debut <-- fin + 1
        pas <-- pas - dollars
        fin <-- fin + pas
        dollars_total <-- dollars_total + dollars
    FinTantQue

    phrase <-- ""

    POUR i <-- 0 à nb_mot - 1
        phrase <-- phrase & Tab_decode[i]
    i SUIVANT
    POUR i <-- 1 à len(phrase)-1
        SI mid(phrase, i, 1) = "$" ALORS
            decode <-- decode & " "
        SINON
            decode <-- mid(phrase, i, 1)
        FINSI
    i SUIVANT

    RENVOYER decode
Fin Fonction
```

## Exercice 2

```
Procédure Principale() 
    Structure Question
        Num_question en numérique * 3
        Libelle en caractère * 50
    Fin Structure
    Structure Reponse
        Num_reponse en numérique * 3
        Texte en caractère * 30
        Bonne_reponse en caractère * 1
    Fin Structure

    Variable Liste_Question[] en Question
    Variable Liste_Reponse[] en Reponse
    Variables i, j, total_question, total_reponse, bonne_reponse, prop, total en numériques

    total_question <-- 0
    Ouvrir "Questions.txt" sur 1 en Lecture
    TantQue Non EOF(1)
        total_question <-- total_question + 1
        REDIM Liste_Question[total_question - 1]
        LireFichier 1, Liste_Question[total_question - 1]
    FinTantQue
    Fermer 1

    Ouvrir "Propositions.txt" sur 2 en Lecture
    POUR i <-- 0 à 9
        nb_question <-- Ent(Alea() * total_question + 1)
        total_reponse <-- 0

        TantQue Non EOF(2)
            LireFichier 2, Reponse
            SI Reponse.Num_reponse = nb_question ALORS
                total_reponse <-- total_reponse + 1
                REDIM Liste_Reponse[total_reponse-1]
                Liste_Reponse[total_reponse-1] <-- Reponse
            FINSI
        FinTantQue

        ECRIRE "Question n°", nb_question
        ECRIRE Liste_Question[nb_question].Libelle

        POUR j <-- 0 à total_reponse - 1
            ECRIRE j, ". ", Liste_Reponse[j].Texte
            SI Liste_Reponse[j].Bonne_reponse = "X" ALORS
                bonne_reponse <-- j
            FINSI
        j SUIVANT

        ECRIRE "Entrez votre proposition : "
        LIRE prop

        SI prop <= 0 OU prop > total_reponse ALORS
            ECRIRE "Proposition non valide. La bonne réponse était : ", bonne_rep, ". ", Liste_Reponse[bonne_rep].Texte
        SINONSI prop = bonne_rep ALORS
            ECRIRE "Réponse correcte"
            total <-- total + 1
        SINON
            ECRIRE "Mauvaise réponse. La bonne réponse était : ", bonne_rep, ". ", Liste_Reponse[bonne_rep].Texte
        FINSI
    i SUIVANT

    Fermer 2
    ECRIRE "Vous avez répondu correctement à ", total, " questions sur 10"
Fin Procédure
```