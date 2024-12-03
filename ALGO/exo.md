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

### Exo 8

> A (RE)FAIRE

## Partie 5

### Exo 1

Début
    Variable num en numérique
    num <- 0
    TantQue num < 1 OU num > 3 ALORS
        ECRIRE "Entrez un numéro entre 1 et 3 :"
        LIRE num
    FinTantQue
Fin

### Exo 2

Début
    Variable num en numérique
    ECRIRE "Entrez un numéro entre 10 et 20 :"
    LIRE num
    TantQue num < 10 OU num > 20 ALORS
        SI num < 10  ALORS
            ECRIRE "Plus grand :"
        SINONSI num > 20 ALORS
            ECRIRE "Plus petit :"
        FINSI
        LIRE num
    FinTantQue
Fin

### Exo 3

Début
    Variables i, num en numérique
    ECRIRE "Entrez un numéro : "
    LIRE num
    i <- num + 10
    TantQue num < i ALORS
        num <- num + 1
        ECRIRE num
    FinTantQue
Fin

### Exo 4

Début
    Variables i, num en numériques
    ECRIRE "Entrez un numéro : "
    LIRE num
    POUR i <- 1 à 10
        ECRIRE num + i
    i SUIVANT
Fin

### Exo 5

Début
    Variables i, num en numériques
    ECRIRE "Entrez un numéro : "
    LIRE num
    ECRIRE "Table de ", num, " : "
    POUR i <- 1 A 10
        ECRIRE num, " x ", i, " = ", num * i
    i SUIVANT
Fin

### Exo 6

Début
    Variable num, i, total en numérique
    ECRIRE "Entrez un numéro :"
    LIRE num
    total <- 0
    POUR i <- 1 A num
        total <- total + i
    i SUIVANT
    ECRIRE "La somme est : ", total
Fin

### Exo 7

Début
    Variable num, i, total en numérique
    ECRIRE "Entrez un numéro :"
    LIRE num
    total <- 1
    POUR i <- 2 A num
        total <- total * i
    i SUIVANT
    ECRIRE "La somme est : ", total
Fin

**Valeurs tests :** 3

### Exo 8

Début
    Variables num, i, max en numériques
    ECRIRE "Entre le nombre numéro 1"
    LIRE max
    POUR i <- 2 A 20
        ECRIRE "Entrez le nombre numéro ", i
        LIRE num
        SI num > max ALORS
            max <- num
        FINSI
    i SUIVANT
    ECRIRE "Le plus grand de ces nombres est : ", max
Fin

---

Début
    Variables num, i, max, index en numériques
    ECRIRE "Entrez le nombre numéro 1"
    LIRE num
    max <- num
    index <- 1
    POUR i <- 2 A 20
        ECRIRE "Entrez le nombre numéro ", i
        LIRE num
        SI num > max ALORS
            max <- num
            index <- i
        FINSI
    i SUIVANT
    ECRIRE "Le plus grand de ces nombres est : ", max
    ECRIRE "C'était le nombre numéro : ", index
Fin


<> Il existe une seconde façon de faire, où tous les cas sont inclus dans la boucle POUR (voir ci-dessous).


### Exo 8 (2ème version)

Début
    Variables num, i, max en numériques
    POUR i <- 1 A 20
        ECRIRE "Entrez le nombre numéro ", i
        LIRE num
        SI i = 1 ALORS
            max <- num
        SINONSI num > max ALORS
            max <- num
        FINSI
    i SUIVANT
    ECRIRE "Le plus grand de ces nombres est : ", max
Fin

Début
    Variables num, i, max en numériques
    max <-- ???
    POUR i <- 1 A 20
        ECRIRE "Entrez le nombre numéro ", i
        LIRE num
        SI i = 1  OU num > max ALORS
            max <- num
        FINSI
    i SUIVANT
    ECRIRE "Le plus grand de ces nombres est : ", max
Fin

### Exo 9

Début
    Variables num, i, max, index en numériques
    ECRIRE "Entre le nombre numéro 1"
    LIRE num
    max <- num
    index <- 1
    i <- 2
    TantQue num != 0 ALORS
        ECRIRE "Entrez le nombre numéro ", i
        LIRE num
        SI num > max ALORS
            max <- num
            index <- i
        FINSI
        i <- i + 1
    FinTantQue
    ECRIRE "Le plus grand de ces nombres est : ", max
    ECRIRE "C'était le nombre numéro : ", index
Fin

### Exo 10

Début
    Variables prix, total, montant en numériques
    total <- 0
    TantQue prix != 0 ALORS
        ECRIRE "Entrez le prix d'un article"
        LIRE prix
        total <- total + prix
    FinTantQue
    ECRIRE "Le total est : ", total
    ECRIRE "Montant payé : "
    LIRE montant
    prix <- montant - total
    TantQue prix > 0 ALORS
        SI prix >= 10 ALORS
            ECRIRE "10 euros"
            prix <- prix - 10
        SINONSI prix >= 5 ALORS
            ECRIRE "5 euros"
            prix <- prix - 5
        SINON
            ECRIRE "1 euro"
            prix <- prix - 1
        FINSI
    FinTantQue
Fin

### Exo 11

Début
    Variables n, p, X, Y, i, n_fac, p_fac, np_fac en numériques
    ECRIRE "Nombre cheveaux partants, Nombre cheveaux joués : "
    LIRE n, p
    n_fac <- 1
    p_fac <-  1
    np_fac <- 1

    POUR i <- 2 à n
        n_fac <- n_fac * i
        SI i <= p ALORS
            p_fac <- p_fac * i
        FINSI
        SI  i <= n - p ALORS
            np_fac <- np_fac * i
        FINSI
    i SUIVANT

    X <-  n_fac / np_fac
    Y <- (1 / p_fac) * X
    ECRIRE "Dans l'ordre : une chance sur ", X, " de gagner"
    ECRIRE "Dans le désordre : une chance sur ", Y, " de gagner"

Fin

## Partie 6

### Exo 1

Début
    Variables T[6], i en numériques
    Pour  i <- 0 à 6
        T[i] <- 0
    i SUIVANT
Fin

### Exo 2

Début
    Variables T[5] en caractères
    T[0] <- "A"
    T[1] <- "E"
    T[2] <- "I"
    T[3] <- "O"
    T[4] <- "U"
    T[5] <- "Y"
Fin

### Exo 3

Début
    Variables T[8], i en numériques
    Pour  i <- 0 à 8
        ECRIRE "Entrez une note : "
        LIRE T[i]
    i SUIVANT
Fin

### Exo 4

> Affiche les carrés des 6 premiers nombres (départ à 0)

Début
    Variables i, T[5] en numériques
    Pour  i <- 0 à 5
        T[i] <- i * i
        ECRIRE T[i]
    i SUIVANT
Fin

### Exo 5

> Stock nombre impair

Début
    Variables i, k, T[6] en numériques
    k <- 1
    Pour i <- 0 à 6
        T[i] <- k + i
        k <- k + 1
    i SUIVANT
Fin

### Exo 6

> Suite Fibonacci

Début
    Variables Suite[7], i en numériques
    Suite[0] <- 1
    Suite[1] <- 1
    Pour  i <- 2 à 7
        Suite[i] <- Suite[i - 1] + Suite[i - 2]
        ECRIRE Suite[i]
    i SUIVANT
Fin

### Exo 7

Début
    Variables T[8], i, moyenne en numériques
    moyenne <- 0
    Pour  i <- 0 à 8
        ECRIRE "Entrez une note : "
        LIRE T[i]
        moyenne <- moyenne + T[i]
    i SUIVANT
    moyenne <- moyenne / 9
    ECRIRE "Moyenne : ", moyenne
Fin

### Exo 8

> O est comptabilisé comme un chiffre positif

Début
    Variables dim, T[], i, neg en numériques
    neg <- 0
    ECRIRE "Combien de valeurs ? "
    LIRE dim
    REDIM T[dim-1]
    Pour i <- 0 à dim - 1
        ECRIRE "Valeur ", i + 1, " : "
        LIRE T[i]
        SI T[i] < 0 ALORS
            neg <- neg + 1
        FINSI
    i SUIVANT
    ECRIRE "Nombre de valeurs négatives : ", neg
    ECRIRE "Nombre de valeurs positives : ", dim - neg
Fin

### Exo 9

Début
    Variables T[], sum, n, i en numériques
    /* SAISI DU TABLEAU, n étant la taille du tableau */
    Pour i <- 0 à n
        sum <- sum + T[i]
    i SUIVANT
    ECRIRE "Somme totale : ", sum
Fin

### Exo 10

Début
    Variables Ta[], Tb[], T[], i, n en numériques
    /* SAISI DU TABLEAU, n étant la taille du tableau */
    Pour i <- 0 à n
        T[i] <- Ta[i] + Tb[i]
    i SUIVANT
Fin

### Exo 11

Début
    Variables Ta[], Tb[], sch, i, j en numériques
    /* SAISI DU TABLEAU, *n* étant la taille de Ta et *p* de Tb */
    sch <- 0
    Pour i <- 0 à p
        Pour j <- 0 à n
            sch <- sch + Ta[i] * Tb[j]
        j SUIVANT
    i SUIVANT
    ECRIRE "Schtroumpf : ", sch
Fin

### Exo 12

Début
    Variables dim, T[], i en numériques
    ECRIRE "Combien de valeurs ? "
    LIRE dim
    REDIM T[dim-1]
    Pour i <- 0 à dim - 1
        ECRIRE "Valeur ", i + 1, " : "
        LIRE T[i]
        T[i] <- T[i] + 1
        ECRIRE T[i]
    i SUIVANT
Fin

### Exo 13

Début
    Variables dim, T[], i, max, index en numériques
    ECRIRE "Combien de valeurs ? "
    LIRE dim
    REDIM T[dim-1]
    Pour i <- 0 à dim - 1
        ECRIRE "Valeur ", i + 1, " : "
        LIRE T[i]
    i SUIVANT
    index <- 0
    Pour i <- 0 à dim - 1
        SI T[i] > T[index] ALORS
            index <- i
        FINSI
    i SUIVANT
    ECRIRE "Le max est ", max, " à la position ", index + 1
Fin

### Exo 14

Début
    Variables dim, T[], i, moy, sup en numériques
    ECRIRE "Combien de notes ? "
    LIRE dim
    REDIM T[dim-1]
    moy <- 0
    sup <- 0
    Pour i <- 0 à dim - 1
        ECRIRE "Note ", i + 1, " : "
        LIRE T[i]
        moy <- moy + T[i]
    i SUIVANT
    moy <- moy / dim
    Pour i <- 0 à dim - 1
        SI T[i] > moy ALORS
            sup <- sup + 1
        FINSI
    i SUIVANT
    ECRIRE "Moyenne : ", moy, " Nombre de notes supérieures à la moyenne : ", sup
Fin

## Partie 7

### Tri par sélection 

Début
[Tableau T de N cases] 
    POUR i <-- 0 à N - 2
        index <-- i
        POUR j <-- i + 1 à N - 1
            SI T[j] < T[index] ALORS
                index <-- j
            FINSI
        j SUIVANT
        echange <-- T[i]
        T[i] <-- T[index]
        T[index] <-- echange
    i SUIVANT
Fin

### Tri par sélection 2

Début
[Tableau T de N cases] 
    POUR i <-- 0 à N - 2
        POUR j <-- i + 1 à N - 1
            SI T[j] < T[i] ALORS
                echange <-- T[i]
                T[i] <-- T[j]
                T[j] <-- echange
            FINSI
        j SUIVANT
    i SUIVANT
Fin

### Tri à bulles

Début
    changement <-- VRAI
    TANTQUE changement
        changement <-- FAUX
        POUR i <-- 0 à N - 2
            SI T[i] > T[i + 1] ALORS
                base <-- T[i]
                T[i] <-- T[i+1]
                T[i+1] <-- base
                changement <-- VRAI
            FINSI
        i SUIVANT
    FINTANTQUE
Fin

