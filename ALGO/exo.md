# Séance 4 -  23 oct. 2024

## Partie 3 

### Exo 3

Début
    Variables nom1, nom2, nom3 en caractères
    ECRIRE  "Entrez 3 noms : "
    LIRE nom1, nom2, nom3
    SI nom1 < nom 2 ET nom2 < nom3 ALORS
        ECRIRE "Ordre alphabétique"
    SINON 
        ECRIRE "Pas dans l'ordre alphabétique"
    FINSI
Fin

### Exo 4

Début
    Variable nb en numériques
    ECRIRE "Entrez un nombre : "
    LIRE nb
    SI  nb > 0 ALORS
        ECRIRE "Positif"
    SINONSI nb = 0 ALORS
        ECRIRE  "Nul"
    SINON
        ECRIRE "Négatif"
    FINSI
Fin

**Var test :** -10 ; 0; 9

### Exo 5

Début
    Variables A, B en numériques
    ECRIRE "Entrez deux nombres : "
    LIRE A, B
    SI A = 0 ou B = 0 ALORS
        ECRIRE "Produit nul"
    SINONSI A < 0 XOR B < 0 ALORS
        ECRIRE "Produit négatif"
    SINON
        ECRIRE "Produit positif"
    FINSI
Fin

**Var test :** -10/-1 ; 10/5; 0/13; -3/4

### Exo 6

Début
    Variables Age en numérique
    ECRIRE "Entrez l'age de l'enfant : "
    SI Age < 6 ALORS
        ECRIRE "Age non valide (min 6 ans)"
    SINONSI Age <= 7 ALORS
        ECRIRE "Poussin"
    SINONSI Age <= 9 ALORS
        ECRIRE "Pupille"
    SINONSI Age <= 11 ALORS
        ECRIRE "Minime"
    SINON
        ECRIRE "Cadet"
    FINSI
Fin

**Var test :** -10 ; 7; 9; 15

## Partie 4

### Exo 1

Début
    SI Tutu <= Toto + 4 ET Tata != "OK" ALORS
        Tutu <- Tutu - 1
    SINON
        Tutu <- Tutu + 1
    FINSI
Fin

### Exo 2

Début
    Variables H, M en numériques
    ECRIRE "Entrez l'heure (H [espace] M) : "
    LIRE H, M
    SI M < 59 ALORS
        M <- M + 1
    SINON
        M <- 0
        H <- H + 1
        SI H = 24 ALORS
            H <- 0
        FINSI
    FINSI
    ECRIRE "Dans une minute, il sera ", H, " heure(s) ", M
Fin

**Var test :** 15:04 ; 9:59 ; 23:59

### Exo 3

Début
    Variables H, M, S en numériques
    ECRIRE "Entrez l'heure (H [espace] M [espace] S) : "
    LIRE H, M, S
    SI S < 59 ALORS
        S <- S + 1
    SINON
        S <- 0
        M <- M + 1
        SI M = 60 ALORS
            M <- 0
            H <- H + 1
            SI H = 24 ALORS
                H <- 0
            FINSI
        FINSI
    FINSI
    ECRIRE "Dans une minute, il sera ",  H, " heure(s) ", M
Fin

**Var test :** 15:04:33 ; 9:15:59 ; 23:59:59

### Exo 4

Début
    Variable NB en numériques
    ECRIRE "Entrez le nombre de photocopies : "
    LIRE NB
    SI NB <= 10 ALORS
        ECRIRE "Prix total :",  NB * 0.10, " euros"
    SINONSI NB  <= 30 ALORS
        ECRIRE "Prix total :",  10 * 0.10 + (NB - 10) * 0.09, " euros"
    SINON
        ECRIRE "Prix total :",  10 * 0.10 + 20 * 0.09 + (NB - 30) * 0.08, " euros"
    FINSI
Fin

**Var test :** 4; 17; 50

### Exo 5

Début
    Variables Age, Sexe en numériques
    ECRIRE "Entrez votre age et sexe : "
    LIRE Age, Sexe
    SI Age < 18 OU (Sexe = "Homme" ET Age <= 20) OU (Sexe = "Femme" ET Age > 35) ALORS
        ECRIRE "Impôt : 0 euros"
    SINON
        ECRIRE "Impôt : X euros"
    FINSI
Fin

**Var test :** H/15 ; H/19 ; H/25 ; F/12 ; F/22 ; F/45

### Exo 6

Début
    Variable A, B, C, D en numériques
    ECRIRE "Entrez les 4 scores : "
    LIRE A, B, C, D
    SI A >= 50 ALORS
        ECRIRE "Elu"
    SINONSI A >= 12.5 ALORS
        SI A > B ET A > C ET A > D ALORS
            ECRIRE "Ballotage favorable"
        SINONSI B < 50 ET C < 50 ET D < 50 ALORS
            ECRIRE "Ballotage défavorable"
        SINON
            ECRIRE "Battu"
        FINSI
    SINON
        ECRIRE "Battu"
    FINSI
Fin

**Var test (!piège) :** 20 - 5 - *60* - 15

### Exo 7

Catégorie :
0 => refusé
1 => rouge
2 => orange
3 => vert
4 => bleu

Début
    Variables age, permis, nb_acc, fidelite, categorie en numérique
    Variable a, p en booléens
    ECRIRE "Entrez votre age, année de permis, nombre d'accident, nombre d'année de fidélité :"
    LIRE age, permis, nb_acc, fidelite
    a <- age > 25
    p <- permis > 2
    SI a et p ALORS
        categorie <- 3
    SINONSI a xor p ALORS
        categorie <- 2
    SINON
        categorie <- 1
    FINSI
    SI fidelite >= 5 ET categorie > 0 ALORS
        categorie <- categorie + 1
    FINSI
    ECRIRE "Votre contrat est : ", categorie - nb_acc

    
> L'exercice demande de "traiter [le] problème" ; s'il faut ajouter la traduction de la catégorie de contrat, voici l'algo :

    SI categorie = 1 ALORS
        ECRIRE "Contrat rouge"
    SINONSI categorie = 2 ALORS
        ECRIRE "Contrat orange"
    SINONSI categorie = 3 ALORS
        ECRIRE "Contrat vert"
    SINONSI categorie = 4 ALORS
        ECRIRE "Contrat bleu"
    SINON
        ECRIRE "Contrat refusé"
    FINSI
Fin