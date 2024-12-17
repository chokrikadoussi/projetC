spool "C:\temp\log\exercice_4.log"

PROMPT '>> Connexion en tant que DBA' 
CONNECT system/motdepasse 

PROMPT '>> Création de Tablespace DATA'
CREATE TABLESPACE DATA_SC_PISE 
DATAFILE 
    'C:/Apps/oradata/PISE/Data_Sc_Pise_1.dbf' SIZE 256 m,
    'C:/Apps/oradata/PISE/Data_Sc_Pise_2.dbf' SIZE 256 m,
    'C:/Apps/oradata/PISE/Data_Sc_Pise_3.dbf' SIZE 256 m 
SEGMENT SPACE MANAGEMENT AUTO;

PROMPT '>> Création de Tablespace INDEX'
CREATE TABLESPACE INDX_SC_PISE
DATAFILE 
    'C:/Apps/oradata/PISE/Indx_Sc_Pise_1.dbf' SIZE 128 m,
    'C:/Apps/oradata/PISE/Indx_Sc_Pise_2.dbf' SIZE 128 m
SEGMENT SPACE MANAGEMENT AUTO;

PROMPT '>> Tablespace par défault + Accès pour chokri'
ALTER USER chokri DEFAULT TABLESPACE DATA_SC_PISE;
ALTER USER chokri QUOTA UNLIMITED ON DATA_SC_PISE;
ALTER USER chokri QUOTA UNLIMITED ON INDX_SC_PISE;

spool off-