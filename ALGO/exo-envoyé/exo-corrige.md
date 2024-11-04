## Partie 4

### Exercice 2

Début
    Variables h, m en numériques
    ECRIRE "Entrez l'heure (format HH MM) : "
    LIRE h, m
    SI m = 59 ALORS
        m <- 0
        h <- h + 1
        SI h = 24 ALORS
            h <- 0
        FINSI
    SINON
        m <- m + 1
    FINSI
    ECRIRE "Dans une minute, il sera ", h, "  heure(s) ", m
Fin


### Exercice 3

Début
    Variables h, m, s en numériques
    ECRIRE "Entrez l'heure (format HH MM SS) : "
    LIRE h, m, s
    SI s = 59 ALORS
        s <- 0
        m <- m + 1
        SI m = 60 ALORS
            m <- 0
            h <- h + 1
            SI h = 24 ALORS
                h <- 0
            FINSI
        FINSI
    SINON
        s <- s + 1
    FINSI
    ECRIRE "Dans une seconde, il sera ", h, "  heure(s) ", m, " minute(s) ", s
Fin

### Exercice 4

Début
    Variables nb, prix en numériques
    ECRIRE "Combien de copie(s) ? "
    LIRE nb
    SI nb <= 10 ALORS
        ECRIRE "Total : ", nb * 0.10
    SINONSI nb <= 30 ALORS
        ECRIRE "Total : ", 10 * 0.10 + (nb - 10) * 0.09
    SINON
        ECRIRE "Total : ", 10 * 0.10 + 20 * 0.09 + (nb - 30) * 0.08
    FINSI
Fin

### Exercice 5

Début
    Variable age en numérique
    Variable sexe en caractère
    ECRIRE "Entrez votre sexe (H/F) puis votre age : "
    LIRE sexe, age
    SI (sexe = "H" ET age > 20) OU (sexe = "F" ET age >= 18 ET age <= 35) ALORS
        ECRIRE "Vous payez l'impôt"
    SINON
        ECRIRE "Vous êtes exonéré"
    FINSI 
Fin

### Exercice 6

Début
    Variables a, b, c, d en numériques
    ECRIRE "Entrez les scores : "
    LIRE a, b, c, d
    SI a >= 50 ALORS
        ECRIRE "Elu"
    SINONSI b >= 50 ou c >= 50 ou d >= 50 ALORS
        ECRIRE "Battu"
    SINONSI a >= 12.5 ALORS
        SI a > b ET a > c ET a > d ALORS
            ECRIRE "Ballotage favorable"
        SINON
            ECRIRE "Ballotage défavorable"
        FINSI
    SINON
        ECRIRE "Battu"
    FINSI
Fin

### Exercice 7

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

### Exercice 8


> On imagine que les chiffres sont des entiers naturels (int unsigned)


Début
    Variables j, m, a en numériques
    SI j > 31 ET m > 12 ALORS
        ECRIRE "Date invalide"
    SINONSI m = 2 ALORS
        SI (a dp 4 ET a !dp 100 ET a dp 400 ET j > 29) OU j > 28 ALORS
            ECRIRE "Date invalide"
        SINON
            ECRIRE "Date valide"
        FINSI
    SINONSI (m = 2 ou m = 4 ou m = 6 ou m = 9 ou m = 11) ET j = 31 ALORS
        ECRIRE "Date invalide"
    SINON
        ECRIRE "Date valide"
    FINSI
Fin
