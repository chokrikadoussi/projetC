/*
Création du schéma
*/ 

CREATE USER chokri IDENTIFIED BY motdepasse;

/*
Accord de privileges
*/

GRANT connect TO chokri;
GRANT create table TO chokri;
GRANT create view TO chokri;
GRANT create any index TO chokri;
GRANT create synonym TO chokri;
GRANT create sequence TO chokri;

