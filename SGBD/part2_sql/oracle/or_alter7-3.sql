SPOOL "C:\temp\log\exo7-3.log"

CONNECT chokri/motdepasse

PROMPT >> Modifier ELEVE Paul DUPOND : changement de ville
UPDATE ELEVE
SET ADR_VILLE_ELEVE = 'Bobigny'
WHERE NOM_ELEVE = 'DUPOND' AND PRENOM_ELEVE = 'Paul' ;

PROMPT >> Modifier ELEVE Sylvie DIMI : changement de ville
UPDATE ELEVE
SET ADR_VILLE_ELEVE = 'Nice'
WHERE NOM_ELEVE = 'DIMI' AND PRENOM_ELEVE = 'Sylvie' ;

PROMPT >> Modifier ELEVE Thomas DEDIEUX : changement de ville 
UPDATE ELEVE
SET ADR_VILLE_ELEVE = 'Argenteuil'
WHERE NOM_ELEVE = 'DEDIEUX' AND PRENOM_ELEVE = 'Thomas' ;

DISCONNECT

SPOOL off
