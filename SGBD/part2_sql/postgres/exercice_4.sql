/* Création de la TABLESPACE */ 
CREATE TABLESPACE data_pise LOCATION 'C:\Program Files\PostgreSQL\16\data\pg_tblspc';

/* Attribution de la TABLESPACE à un schéma */
ALTER TABLESPACE data_pise OWNER TO chokri;