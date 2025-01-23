-- Création de la table Type_opération
CREATE TABLE
    IF NOT EXISTS TYPE_OPERATION (IDT_TYPE_OPE TEXT, LIBELLE TEXT) TABLESPACE data_pise;

-- Création de la table Catégorie
CREATE TABLE
    IF NOT EXISTS CATEGORIE (
        IDT_CATEGORIE TEXT,
        LIBELLE_CATEGORIE TEXT,
        IDT_TYPE_OPE TEXT
    ) TABLESPACE data_pise;

-- Création de la table Sous-catégorie
CREATE TABLE
    IF NOT EXISTS SOUS_CATEGORIE (
        IDT_SS_CATEGORIE TEXT,
        LIBELLE_SS_CATEGORIE TEXT,
        IDT_CATEGORIE TEXT
    ) TABLESPACE data_pise;

-- Création de la table Mode de règlement
CREATE TABLE
    IF NOT EXISTS MODE_REGLEMENT (IDT_MODE_REG TEXT, LIBELLE_MODE_REG TEXT) TABLESPACE data_pise;

-- Création de la table Statut
CREATE TABLE
    IF NOT EXISTS STATUT (IDT_STATUT TEXT, LIBELLE_STATUT TEXT) TABLESPACE data_pise;

-- Création de la table Ecriture
CREATE TABLE
    IF NOT EXISTS ECRITURE (
        NUMERO TEXT,
        DT_ECRITURE TEXT,
        FICHIER TEXT,
        LIBELLE TEXT,
        HT TEXT,
        TVA TEXT,
        TTC TEXT,
        EXERCICE_COMPTABLE TEXT,
        IDT_MODE_REG TEXT,
        IDT_STATUT TEXT,
        IDT_SS_CATEGORIE TEXT
    ) TABLESPACE data_pise;

COMMIT;