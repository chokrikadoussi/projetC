SPOOL "C:\temp\log\exo7-1.log"

CONNECT chokri/motdepasse

PROMPT >> Modifier champ DATE_NAIS_ELEVE de ELEVE : non nullable

ALTER TABLE ELEVE
MODIFY DATE_NAIS_ELEVE NOT NULL ; 

DISCONNECT

SPOOL off
