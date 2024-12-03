CREATE TABLESPACE DATA_SC_PISE 
DATAFILE 
'C:/Apps/Oracle/oradata/Data_Sc_Pise_1.dbf' SIZE 256 m,
'C:/Apps/Oracle/oradata/Data_Sc_Pise_2.dbf' SIZE 256 m,
'C:/Apps/Oracle/oradata/Data_Sc_Pise_3.dbf' SIZE 256 m 
SEGMENT SPACE MANAGEMENT AUTO;

CREATE TABLESPACE INDX_SC_PISE
DATAFILE 
'C:/Apps/Oracle/oradata/Indx_Sc_Pise_1.dbf' SIZE 128 m,
'C:/Apps/Oracle/oradata/Indx_Sc_Pise_2.dbf' SIZE 128 m
SEGMENT SPACE MANAGEMENT AUTO;