## Partie 4

### Exercice 7

Début
    Variables age, permis, nb_acc, fidelite, categorie, Points en numérique
    ECRIRE "Entrez votre age, année de permis, nombre d'accident, nombre d'année de fidélité :"
    LIRE age, permis, nb_acc, fidelite
    Points <- nb_acc
    Si age < 25 Alors
        Points ← Points + 1
    FinSi
    Si permis < 2 Alors
        Points ← Points + 1
    FinSi
    Si P < 3 et fidelite > 5 Alors
        Points ← Points + 1
    FinSi
    [TRADUCTION DES POINTS]
Fin

### Exercice 8

Début
    Variables j, m, a en numériques
    Variables jours31, jours30, jours29, jours29 en booléens
    ECRIRE "Entrez le jour, le mois et l'année :"
    LIRE j, m, a
    jours31 <- (m = 1 ou m = 3 ou m = 5 ou m = 7 ou m = 8  ou m = 10 ou m = 12) ET j <= 31 ET j >= 1
    jours30 <- (m = 2 ou m = 4 ou m = 6 ou m = 9 ou m = 11) ET j <= 30 ET j >= 1
    BIS <- a dp 4 ET NON(a dp 100) OU a dp 400
    jours29 <- m = 2  ET j <= 29 ET j >= 1 ET BIS
    jours28 <- m = 2  ET j <= 28 ET j >= 1
    SI jours31 OU jours30 OU jours29 OU jours28 ALORS
        ECRIRE "Date valide"
    SINON
        ECRIRE "Date invalide"
    FINSI
Fin