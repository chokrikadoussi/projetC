# Séance 4 - 24 oct. 2024

## MLD - Modèle Relationnel

### Exo 1

CHAINE(**Sigle**, Adresse, Nom, Tel)\
EMISSION(**Id_emission**, Titre, Duree, Code_CSA, #Id_cat)\
CAT_PROG(**Id_cat**, Libelle)\
DIFFUSER(**Id_diffusion, #Sigle, #Id_emission**, Jour, Heure)\

> Le couple #Sigle, #Id_emission ne garantie pas l'unicité totale (une chaine peut redifusser une même émission à une date différente). Pour cela, soit un ajoute un ID soit la PK est l'ensemble des attributs

### Exo 2

COMMUNE(**Code_com**)\
ILOTS(**Num_ilot**, #Code_com)\
LOGEMENT(**Id_log**, Annee, Surface, #Num_ilot, #Id_foyer)\
FOYER(**Id_foyer**, Nb_prsn, Nb_enf, Nb_etu, Nom_rep, Prof_rep, #Id_log)\

### Exo 3

REVUE(**Id_revue**, Nom, Periodicite)\
NUMERO(**Numero, Annee**, Nb_page, #Id_revue)\
ARTICLE(**Id_article**, Titre, Contenu)\
AUTEUR(**Email**, Nom, Prenom)\
CONTENIR(**#Id_article, #Numero, #Annee**, Page_debut, Page_fin)\
REFERENCER(**#Id_article**, #Numero, #Annee)\
ECRIRE(**#Email, #Id_article**)\

### Exo 4

SOLDAT(**Matricule**, Nom, Prenom)\
PARTICIPATION(**Num_participation**, Date, #Matricule)\
OBSTACLE(**Nom_obstacle**, Note_mini, #Code_niveau)\
NIVEAU_DIFFICULTE(**Code_niveau**, Libelle, Bonus)\
PASSER(**#Num_participation, #Nom_obstacle**, Note, Temps)

---

EXPLOITATION(**Id_exploitation**, Nom_exploitation, Commune, SAU)\
VALEUR_DROIT(**Id_valeur**, Montant, #Id_exploitation, #Id_droit, #Id_periode)\
PERIODE(**Id_periode**, Date_debut, Date_fin)\
DROIT(**Id_droit**, Libelle, Unite)

### Exo 5

> Trouver la correction

### Exo 6

> A FAIRE !

### Exo 7

- Oui => Cardinalité 1,N
- Non => Cardinalité 1,1
- Oui
- Oui

MEDECIN(**Matricule**, Nom, Prenom)\
CONSULTATION(**numConsultation**, Date_Heure, #Matricule, #numSS)\
MEDICAMENT(**codeSS**, nomCommercial)\
PATIENT(**numSS**, Nom, Prenom)\
PRESCRIRE(**#codeSS, #numConsultation**, Posologie)

### Exo 8

ETUDIANT(**codetu**, ninsee, Nom, Prenom, Adresse)\
ENSEIGNANT(**initens**, nomens, bureauens, telens)\
UNITE_VALEUR(**codeuv**, intuv, #initens)\
SUIVRE(**#codetu, #codeuv**)\
DISPO(**#codeuv, #initens**, jsem, hrens)

### Exo 9

ADRESSE(**Id_adresse**, Rue, Ville, CP)
LIEU(**Id_lieu**, Ville, CP)
CYCLISTE(**numLicence**, Nom, Prenom, Date_naissance, #Id_adresse)
COURSE(**Id_course**, Date, Ville, Longueur, #Id_lieu)
PARTICIPER(**#numLicence, #Id_course**, Temps, Rang)