SPOOL "C:\temp\log\exo7-4.log"

CONNECT chokri/motdepasse

PROMPT >> Modifier Annee naissance pour eleve à Paris
UPDATE ELEVE
SET DATE_NAIS_ELEVE = TO_DATE('1990', 'YYYY')
WHERE ADR_VILLE_ELEVE = 'Paris' ;


DISCONNECT

SPOOL off
