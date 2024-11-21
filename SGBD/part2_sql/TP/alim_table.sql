SET TIMING ON

DECLARE
	v_nb_limit	NUMBER := 300001 ;
	v_cpt NUMBER := 1;
	v_nom VARCHAR2(50);
	v_prenom VARCHAR2(50);

BEGIN
	WHILE v_cpt < v_nb_limit
	LOOP
		
		v_nom := DBMS_RANDOM.string('x',50) ;
		v_prenom := DBMS_RANDOM.string('x',50) ;
		
		INSERT INTO PERSONNE VALUES (v_cpt, v_nom, v_prenom);
		
		IF (v_cpt = 10)
		THEN
			INSERT INTO PERSONNE VALUES(10, 'ONGAGNA', 'Alexis');
		ELSIF (v_cpt = 20)
		THEN
			INSERT INTO PERSONNE VALUES(11, 'LOVE', 'Kevin');
		END IF;
		
		COMMIT ;
	
		v_cpt := v_cpt + 1 ;
	END LOOP ;
	
END;
/