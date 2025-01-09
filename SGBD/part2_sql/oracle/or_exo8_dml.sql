SPOOL "C:\temp\log\or_exo8_dml.log"

connect chokri/motdepasse

PROMPT >> a- Changer Ville
UPDATE F
SET VilleF = 'Toulouse'
WHERE NumF = 3 ;

PROMPT >> b- Afficher infos usines
SELECT *
FROM U ;

PROMPT >> c- Afficher infos usines de Paris
SELECT *
FROM U
WHERE UPPER(VilleU) = 'PARIS' ;

PROMPT >> d- 
SELECT NumF
FROM F
INNER JOIN PUF ON PUF.NumF = F.NumF
WHERE NumU = 2 AND NumP = 100 ;

PROMPT >> e-
SELECT NomP, Couleur
FROM P
INNER JOIN PUF ON PUF.NumP = P.NumP
WHERE NumF = 2 ;

PROMPT >> f-
SELECT NumF
FROM F
INNER JOIN PUF ON PUF.NumF = F.NumF
INNER JOIN P ON PUF.NumP = P.NumP
WHERE NumU = 2 AND UPPER(P.Couleur) = 'ROUGE' ; 

PROMPT >> g-
SELECT NumF
FROM F
INNER JOIN PUF ON PUF.NumF = F.NumF
INNER JOIN P ON PUF.NumP = P.NumP
INNER JOIN U ON PUF.NumU = U.NumU
WHERE UPPER(U.VilleU) IN ('PARIS', 'CRETEIL') AND UPPER(P.Couleur) = 'ROUGE' ; 

PROMPT >> h-
SELECT NumP
FROM P
INNER JOIN PUF ON PUF.NumP = P.NumP
INNER JOIN U ON PUF.NumU = U.NumU
INNER JOIN F ON PUF.NumF = F.NumF
WHERE UPPER(U.VilleU) = 'PARIS' AND  UPPER(F.VilleF) = 'PARIS' ;

PROMPT >> i-
SELECT NumP
FROM P
WHERE Poids = MIN(Poids) ;

SPOOL OFF