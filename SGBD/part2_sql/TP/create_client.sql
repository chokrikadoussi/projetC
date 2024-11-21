CREATE TABLE TCLIBDR
(
	MNETEX           VARCHAR(8)             NOT NULL,
	RAISOC           VARCHAR(90)            NOT NULL,
	NOMCRT           VARCHAR(27)            NOT NULL,
	CA3ISOPAYRES     VARCHAR(3)             NOT NULL,
	NOMVIL           VARCHAR(35)            NOT NULL,
	DATCRE           DATE                   NOT NULL,
	DATMOD           DATE,
	DATVAL           DATE
) tablespace data_pise;

ALTER TABLE TCLIBDR ADD ( CONSTRAINT PK_TCLIBDR PRIMARY KEY (MNETEX) );