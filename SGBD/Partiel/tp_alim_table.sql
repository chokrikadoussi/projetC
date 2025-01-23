COPY chokri.TYPE_OPERATION (IDT_TYPE_OPE, LIBELLE)
FROM
    'C:\temp\import_csv\TypeOperation_table.csv' DELIMITER ';' HEADER;

COPY chokri.CATEGORIE (IDT_CATEGORIE, LIBELLE_CATEGORIE, IDT_TYPE_OPE)
FROM
    'C:\temp\import_csv\Categorie_table.csv' DELIMITER ';' HEADER;

COPY chokri.SOUS_CATEGORIE (
    IDT_SS_CATEGORIE,
    LIBELLE_SS_CATEGORIE,
    IDT_CATEGORIE
)
FROM
    'C:\temp\import_csv\SousCategorie_table.csv' DELIMITER ';' HEADER;

COPY chokri.MODE_REGLEMENT (IDT_MODE_REG, LIBELLE_MODE_REG)
FROM
    'C:\temp\import_csv\ModeReglement_table.csv' DELIMITER ';' HEADER;

COPY chokri.STATUT (IDT_STATUT, LIBELLE_STATUT)
FROM
    'C:\temp\import_csv\Statut_table.csv' DELIMITER ';' HEADER;

COPY chokri.ECRITURE (
    NUMERO,
    DT_ECRITURE,
    FICHIER,
    LIBELLE,
    HT,
    TVA,
    TTC,
    EXERCICE_COMPTABLE,
    IDT_MODE_REG,
    IDT_STATUT,
    IDT_SS_CATEGORIE
)
FROM
    'C:\temp\import_csv\Ecriture_Table.csv' DELIMITER ';' HEADER;

COMMIT;