update ecriture
set
    ht = replace (ht, ' ', '');

update ecriture
set
    ht = replace (ht, ',', '.');

update ecriture
set
    tva = replace (tva, ' ', '');

update ecriture
set
    tva = replace (tva, ',', '.');

update ecriture
set
    ttc = replace (ttc, ' ', '');

update ecriture
set
    ttc = replace (ttc, ',', '.');

COMMIT;