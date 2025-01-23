-- Nombre de client par ville (Londres)
SELECT
    nomvil,
    COUNT(*) Nb_client
FROM
    TCLIBDR
GROUP BY
    nomvil
HAVING
    --UPPER(nomvil) LIKE '%LONDON%'
    Nb_client > 1000
ORDER BY
    nomvil ASC;