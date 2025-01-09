SPOOL "C:\temp\log\or_exo9_dml.log"

host cls

connect chokri/motdepasse

PROMPT >> 1- Employes avec commission
SELECT *
FROM Emp
WHERE COMM IS NOT NULL
ORDER BY COMM DESC ;

PROMPT >> 2- Employes embauche avant 1er sept 2006
SELECT NOME
FROM Emp
WHERE EMBAUCHE >= TO_DATE('01/09/2006', 'dd/mm/yyyy');

PROMPT >> 3- Employes travaillant Creteil
SELECT NOME --La liste des employés est demandé : mettre * ?
FROM Emp
INNER JOIN Dept ON Emp.NUMD = Dept.NUMD
WHERE UPPER(Dept.LIEU) = 'CREEIL';

PROMPT >> 4- Nb employe et salaire moy par dep
SELECT COUNT(NOME) AS "Nombre Employe", AVG(SALAIRE) AS "Salaire Moyen"
FROM Emp
INNER JOIN Dept ON Emp.NUMD = Dept.NUMD 
GROUP BY Dept.NOMD;

PROMPT >> 5- A FAIRE

PROMPT >> 6- Salaire moyen entreprise
SELECT AVG(SALAIRE) AS "Salaire Moyen"
FROM Emp;

PROMPT >> 7- Nb com non nul
SELECT COUNT(NOME) AS "Nombre Commission"
FROM Emp
WHERE COMM IS NOT NULL;

PROMPT >> 8- Employes gagnant plus que la moy
SELECT *
FROM Emp
WHERE SALAIRE >= ANY(
    SELECT AVG(SALAIRE) AS "Salaire Moyen"
    FROM Emp
    ) ;

PROMPT >> 9- Calcul masse salariale totale
SELECT SUM(COMM + SALAIRE) AS "Masse Salariale"
FROM Emp ;

commit ;

SPOOL OFF