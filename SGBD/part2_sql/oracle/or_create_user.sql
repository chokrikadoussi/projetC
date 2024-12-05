spool "C:\temp\log\exercice_2.log"

PROMPT '>> Connexion en tant que DBA' 
CONNECT system/motdepasse 

PROMPT '>> Création du schéma chokri'
CREATE USER chokri IDENTIFIED BY motdepasse;

PROMPT '>> Accès aux privilièges'
GRANT connect TO chokri;
GRANT create table TO chokri;
GRANT create view TO chokri;
GRANT create any index TO chokri;
GRANT create synonym TO chokri;
GRANT create sequence TO chokri;

spool off