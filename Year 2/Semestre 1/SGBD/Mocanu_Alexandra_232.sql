CREATE TABLE CUSCA (
    ID_CUSCA INT PRIMARY KEY,
    NUMAR_LOCURI INT
);

CREATE TABLE SECTOR (
    ID_SECTOR INT PRIMARY KEY,
    TIP_NEVOIE VARCHAR(255),
    NUMAR_LOCURI INT
);

CREATE TABLE SECTIE (
    ID_SECTIE INT PRIMARY KEY,
    NUME VARCHAR(255),
    ID_CUSCA INT,
    FOREIGN KEY (ID_CUSCA) REFERENCES CUSCA (ID_CUSCA)
);


CREATE TABLE SECTIE_SECTOR (
    ID_SECTIE INT,
    ID_SECTOR INT,
    PRIMARY KEY (ID_SECTIE, ID_SECTOR),
    FOREIGN KEY (ID_SECTIE) REFERENCES SECTIE (ID_SECTIE),
    FOREIGN KEY (ID_SECTOR) REFERENCES SECTOR (ID_SECTOR)
);

CREATE TABLE MEDICAMENT (
    NUMAR INT PRIMARY KEY,
    DENUMIRE_PRODUS VARCHAR(255),
    CANTITATE INT
);

CREATE TABLE FARMACIE (
    ID_FARMACIE INT PRIMARY KEY,
    NUME VARCHAR(255),
    TELEFON VARCHAR(255),
    PROGRAM VARCHAR(255),
    NUMAR INT,
    FOREIGN KEY (NUMAR) REFERENCES MEDICAMENT (NUMAR)
);

--tabel asociativ intre medicament si farmacie 
CREATE TABLE MED(
    ID_FARMACIE INT,
    NUMAR INT,
    PRIMARY KEY(ID_FARMACIE, NUMAR),
    FOREIGN KEY (ID_FARMACIE) REFERENCES FARMACIE (ID_FARMACIE),
    FOREIGN KEY (NUMAR) REFERENCES MEDICAMENT (NUMAR) 
);


CREATE TABLE MAGAZIN (
    ID_MAGAZIN INT PRIMARY KEY,
    ID_CONTRACT INT,
    NUME VARCHAR(255),
    TELEFON VARCHAR(255),
    PROGRAM VARCHAR(255)
);

CREATE TABLE HRANA (
    NUMAR INT PRIMARY KEY,
    DENUMIRE_PRODUS VARCHAR(255),
    CANTITATE INT,
    ID_MAGAZIN INT,
    FOREIGN KEY (ID_MAGAZIN) REFERENCES MAGAZIN (ID_MAGAZIN)
);

CREATE TABLE VIZITATOR (
    CNP VARCHAR(13) PRIMARY KEY,
    NUME VARCHAR(255),
    PRENUME VARCHAR(255),
    TELEFON VARCHAR(255),
    EMAIL VARCHAR(255)
);

CREATE TABLE VETERINAR (
    CNP VARCHAR(13) PRIMARY KEY,
    NUME VARCHAR(255),
    PRENUME VARCHAR(255)
);


CREATE TABLE ANIMAL (
    ID_ANIMAL INT PRIMARY KEY,
    NUME VARCHAR(255),
    RASA VARCHAR(255),
    VARSTA INT,
    SEX VARCHAR(255),
    DATA_SOSIRE DATE,
    ID_CUSCA INT,
    ID_VETERINAR VARCHAR(13),
    FOREIGN KEY (ID_CUSCA) REFERENCES CUSCA (ID_CUSCA),
    FOREIGN KEY (ID_VETERINAR) REFERENCES VETERINAR (CNP)
);

CREATE TABLE CARTE_DE_SANATATE (
    ID_ANIMAL INT PRIMARY KEY,
    VACCINURI VARCHAR(255),
    DATA_NASTERE DATE,
    ANTECEDENTE_MEDICALE VARCHAR(255),
    ID_VETERINAR VARCHAR(13),
    FOREIGN KEY (ID_VETERINAR) REFERENCES VETERINAR (CNP)
);

CREATE TABLE CONSULTATIE (
    ID_CONSULTATIE INT PRIMARY KEY,
    ID_ANIMAL INT,
    DATA DATE,
    ID_VETERINAR VARCHAR(13),
    FOREIGN KEY (ID_VETERINAR) REFERENCES VETERINAR (CNP)
);

CREATE TABLE CERERE_ADOPTIE (
    SERIE VARCHAR(255),
    ID_ANIMAL INT,
    ID_VIZITATOR VARCHAR(13),
    DATA DATE,
    --APROBATA_DE_DIRECTOR BOOLEAN DEFAULT FALSE,
    PRIMARY KEY (SERIE, ID_ANIMAL, ID_VIZITATOR),
    FOREIGN KEY (ID_ANIMAL) REFERENCES ANIMAL (ID_ANIMAL),
    FOREIGN KEY (ID_VIZITATOR) REFERENCES VIZITATOR (CNP)
);

CREATE TABLE CLINICA_VETERINARA (
    ID_CLINICA INT PRIMARY KEY,
    DENUMIRE VARCHAR(255),
    ADRESA VARCHAR(255),
    TELEFON VARCHAR(255),
    EMAIL VARCHAR(255),
    ID_VETERINAR VARCHAR(13),
    FOREIGN KEY (ID_VETERINAR) REFERENCES VETERINAR (CNP)
);

CREATE TABLE CONTRACT (
    NUMAR INT PRIMARY KEY,
    DATA_EMITERE DATE,
    DURATA INT,
    TIP VARCHAR(255),
    id_magazin INT,
    id_farmacie INT,
    id_clinica INT,
    FOREIGN KEY (id_magazin) REFERENCES MAGAZIN (id_magazin),
    FOREIGN KEY (id_farmacie) REFERENCES FARMACIE (id_farmacie),
    FOREIGN KEY (id_clinica) REFERENCES CLINICA_VETERINARA (ID_CLINICA)
);


CREATE TABLE ANGAJAT (
    ID_ANGAJAT INT PRIMARY KEY,
    NUME VARCHAR(255),
    PRENUME VARCHAR(255),
    CNP VARCHAR(13),
    ADRESA VARCHAR(255),
    TELEFON VARCHAR(255),
    EMAIL VARCHAR(255),
    ID_CONTRACT INT,
    FOREIGN KEY (ID_CONTRACT) REFERENCES CONTRACT (NUMAR)
);

CREATE TABLE DIRECTOR (
    ID_DIRECTOR INT,
    ID_CONTRACT INT,
    ID_ANGAJAT INT,
    FOREIGN KEY (ID_CONTRACT) REFERENCES CONTRACT (NUMAR),
    FOREIGN KEY (ID_ANGAJAT) REFERENCES ANGAJAT (ID_ANGAJAT)
);

-- Tabela CUSCA --
INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (1, 5);
INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (2, 10);
INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (3, 4);
INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (4, 6);
INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (5, 5);

-- Tabela SECTOR --
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (1, 'Deparazitare interna si externa', 100);
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (2, 'Analize de sange', 30);
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (3, 'Vaccinari', 10);
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (4, 'Chirurgie generala', 20);
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (5, 'Dermatologie', 40);

-- Tabela SECTIE --
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (1, 'Sectia 1', 1);
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (2, 'Sectia 2', 2);
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (3, 'Sectia 3', 3);
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (4, 'Sectia 4', 4);
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (5, 'Sectia 5', 5);

-- Tabela SECTIE_SECTOR --
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (1, 1);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (1, 2);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (1, 3);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (2, 2);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (2, 4);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (3, 3);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (3, 5);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (4, 4);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (4, 1);
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (5, 5);

-- Tabela MEDICAMENT --
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (1, 'Wyzium', 50);
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (2, 'KalmVet', 50);
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (3, 'RX Nutricalm', 50);
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (4, 'Entero-Chronic', 50);
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (5, 'Calmex', 50);

-- Tabela FARMACIE --
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (1, 'ANIMAX VET SRL', '33522396', '9 AM - 6 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (2, 'PET BOUTIQUE', '38440980', '10 AM - 8 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (3, 'ANIMAL AREA', '39898404', '12 AM - 6 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (4, ' GROOM VET C&A SRL', '41654738', '8 AM - 8 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (5, 'PETMART ONLINE SRL', '32167601', '24/7', 1);


-- Tabela MAGAZIN --
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (1, 1, 'Animax – Pet Store', '987-654-3456', '10 AM - 8 PM');
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (2, 2, 'PetMart', '865-153-3210', '9 AM - 4 PM');
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (3, 3, 'Maxi-Pet', '235-864-3210', '12 AM - 10 PM');
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (4, 4, 'Shop4Pet', '987-654-2355', '10 AM - 8 PM');
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (5, 5, 'PerfectPet', '987-654-3210', '10 AM - 8 PM');

-- Tabela HRANA --
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN)
VALUES (1, 'Hrana uscata pentru caini Pedigree Adult', 100, 1);
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN)
VALUES (2, 'Hrana uscata pentru caini Brit Premium, Adult', 120, 2);
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN)
VALUES (3, 'Hrana uscata pentru caini Bosch Adult cu miel si orez', 80, 3);
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN)
VALUES (4, 'Hrana umeda pentru caini Petkult Adult cu vanat', 100, 4);
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN)
VALUES (5, 'Hrana umeda pentru caini Petkult Adult cu rata', 140, 5);

-- Tabela VIZITATOR --
INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1891123456789', 'Ion', 'Popescu', '0721123456', 'ion.popescu@example.com');
INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('2900501234567', 'Elena', 'Ionescu', '0750123456', 'elena.ionescu@example.com');
INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1810412345678', 'Mihai', 'Georgescu', '0741123456', 'mihai.georgescu@example.com');
INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('2930412345678', 'Maria', 'Stefanescu', '0771123456', 'maria.stefanescu@example.com');
INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1971001234567', 'Andrei', 'Popa', '0730123456', 'andrei.popa@example.com');


-- Tabela VETERINAR --
INSERT INTO VETERINAR (CNP, NUME, PRENUME)
VALUES ('1820701234567', 'Mihai', 'Popescu');
INSERT INTO VETERINAR (CNP, NUME, PRENUME)
VALUES ('1910501234567', 'Ana', 'Ionescu');
INSERT INTO VETERINAR (CNP, NUME, PRENUME)
VALUES ('1950412345678', 'Maria', 'Georgescu');
INSERT INTO VETERINAR (CNP, NUME, PRENUME)
VALUES ('1860301234567', 'Ion', 'Stefanescu');
INSERT INTO VETERINAR (CNP, NUME, PRENUME)
VALUES ('1830412345678', 'Elena', 'Popa');


-- Tabela ANIMAL --
INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (1, 'Rex', 'Cocker Spaniel', 3, 'Masculin', TO_DATE('2022-01-15', 'YYYY-MM-DD'), 1, '1820701234567');
INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (2, 'Lola', 'Beagle', 2, 'Feminin', TO_DATE('2023-03-22', 'YYYY-MM-DD'), 1, '1910501234567');
INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (3, 'Max', 'Labrador Retriever', 1, 'Masculin', TO_DATE('2023-05-10', 'YYYY-MM-DD'), 2, '1950412345678');
INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (4, 'Daisy', 'Golden Retriever', 2, 'Feminin', TO_DATE('2023-02-18', 'YYYY-MM-DD'), 2, '1860301234567');
INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (5, 'Rocky', 'German Shepherd', 4, 'Masculin', TO_DATE('2022-11-05', 'YYYY-MM-DD'), 3, '1830412345678');


-- Tabela CARTE_DE_SANATATE --
INSERT INTO CARTE_DE_SANATATE (ID_ANIMAL, VACCINURI, DATA_NASTERE, ANTECEDENTE_MEDICALE, ID_VETERINAR)
VALUES (1, 'Vaccin Leptospiroza, Vaccin Parvoviroza', TO_DATE('2019-05-12', 'YYYY-MM-DD'), 'Niciuna', '1820701234567');
INSERT INTO CARTE_DE_SANATATE (ID_ANIMAL, VACCINURI, DATA_NASTERE, ANTECEDENTE_MEDICALE, ID_VETERINAR)
VALUES (2, 'Vaccin Leucemie Felina, Vaccin Rabie', TO_DATE('2023-03-22', 'YYYY-MM-DD'), 'Vaccin alergie', '1910501234567');
INSERT INTO CARTE_DE_SANATATE (ID_ANIMAL, VACCINURI, DATA_NASTERE, ANTECEDENTE_MEDICALE, ID_VETERINAR)
VALUES (3, 'Vaccin Parvoviroza, Vaccin Distemper', TO_DATE('2023-05-10', 'YYYY-MM-DD'), 'Niciuna', '1950412345678');
INSERT INTO CARTE_DE_SANATATE (ID_ANIMAL, VACCINURI, DATA_NASTERE, ANTECEDENTE_MEDICALE, ID_VETERINAR)
VALUES (4, 'Vaccin Rabie, Vaccin Parainfluenza', TO_DATE('2023-02-18', 'YYYY-MM-DD'), 'Vaccin diabet', '1860301234567');
INSERT INTO CARTE_DE_SANATATE (ID_ANIMAL, VACCINURI, DATA_NASTERE, ANTECEDENTE_MEDICALE, ID_VETERINAR)
VALUES (5, 'Vaccin Bordeteloza, Vaccin Parvoviroza', TO_DATE('2022-11-05', 'YYYY-MM-DD'), 'Niciuna', '1830412345678');


-- Tabela CONSULTATIE --
INSERT INTO CONSULTATIE (ID_CONSULTATIE, ID_ANIMAL, DATA, ID_VETERINAR)
VALUES (2, 3, TO_DATE('2023-08-01', 'YYYY-MM-DD'), '1950412345678');
INSERT INTO CONSULTATIE (ID_CONSULTATIE, ID_ANIMAL, DATA, ID_VETERINAR)
VALUES (3, 2, TO_DATE('2023-08-02', 'YYYY-MM-DD'), '1910501234567');
INSERT INTO CONSULTATIE (ID_CONSULTATIE, ID_ANIMAL, DATA, ID_VETERINAR)
VALUES (4, 5, TO_DATE('2023-08-03', 'YYYY-MM-DD'), '1830412345678');
INSERT INTO CONSULTATIE (ID_CONSULTATIE, ID_ANIMAL, DATA, ID_VETERINAR)
VALUES (5, 4, TO_DATE('2023-08-04', 'YYYY-MM-DD'), '1860301234567');


-- Tabela CERERE_ADOPTIE --
INSERT INTO CERERE_ADOPTIE (SERIE, ID_ANIMAL, ID_VIZITATOR, DATA)
VALUES ('DEF456', 3, '1971001234567', TO_DATE('2023-08-02', 'YYYY-MM-DD'));
INSERT INTO CERERE_ADOPTIE (SERIE, ID_ANIMAL, ID_VIZITATOR, DATA)
VALUES ('GHI789', 2, '1810412345678', TO_DATE('2023-08-03', 'YYYY-MM-DD'));
INSERT INTO CERERE_ADOPTIE (SERIE, ID_ANIMAL, ID_VIZITATOR, DATA)
VALUES ('JKL012', 5, '2900501234567', TO_DATE('2023-08-04', 'YYYY-MM-DD'));
INSERT INTO CERERE_ADOPTIE (SERIE, ID_ANIMAL, ID_VIZITATOR, DATA)
VALUES ('MNO345', 4, '2930412345678', TO_DATE('2023-08-05', 'YYYY-MM-DD'));


-- Tabela CLINICA_VETERINARA --
INSERT INTO CLINICA_VETERINARA (ID_CLINICA, DENUMIRE, ADRESA, TELEFON, EMAIL, ID_VETERINAR)
VALUES (1, 'Clinica Veterinara "VetCare"', 'Strada Vesela, nr. 789', '555-111-2222', 'vetcare@example.com', '1830412345678');
INSERT INTO CLINICA_VETERINARA (ID_CLINICA, DENUMIRE, ADRESA, TELEFON, EMAIL, ID_VETERINAR)
VALUES (2, 'Clinica Veterinara "AnimalCare"', 'Strada Centrala, nr. 456', '555-987-6543', 'clinicavet@example.com', '1950412345678');
INSERT INTO CLINICA_VETERINARA (ID_CLINICA, DENUMIRE, ADRESA, TELEFON, EMAIL, ID_VETERINAR)
VALUES (3, 'Clinica Veterinara "VetExpert"', 'Strada Mica, nr. 789', '555-456-7890', 'vetexpert@example.com', '1820701234567');
INSERT INTO CLINICA_VETERINARA (ID_CLINICA, DENUMIRE, ADRESA, TELEFON, EMAIL, ID_VETERINAR)
VALUES (4, 'Clinica Veterinara "PetHealth"', 'Strada Mare, nr. 101', '555-789-0123', 'pethealth@example.com', '1910501234567');
INSERT INTO CLINICA_VETERINARA (ID_CLINICA, DENUMIRE, ADRESA, TELEFON, EMAIL, ID_VETERINAR)
VALUES (5, 'Clinica Veterinara "HappyPets"', 'Strada Munte, nr. 543', '555-012-3456', 'happypets@example.com', '1860301234567');



-- Tabela CONTRACT --
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (101, TO_DATE('2023-07-15', 'YYYY-MM-DD'), 2, 'Servicii Veterinare', 1, NULL, 2);
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (102, TO_DATE('2023-07-16', 'YYYY-MM-DD'), 2, 'Consultatii Medicale', 2, 1, 3);
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (103, TO_DATE('2023-07-17', 'YYYY-MM-DD'), 2, 'Analize Medicale', 3, 3, 1);
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (104, TO_DATE('2023-07-18', 'YYYY-MM-DD'), 2, 'Chirurgie Veterinara', 4, 2, 5);
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (105, TO_DATE('2023-07-19', 'YYYY-MM-DD'), 2, 'Vaccinari Animale', 5, 5, 4);



-- Tabela ANGAJAT --
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (1, 'Ana', 'Popa', '5678901234567', 'Strada Angajatului, nr. 6', '555-555-6666', 'ana@example.com', 101);
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (2, 'Maria', 'Popescu', '1234567890123', 'Strada Angajatului, nr. 2', '555-111-2222', 'maria@example.com', 102);
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (3, 'Ion', 'Ionescu', '2345678901234', 'Strada Angajatului, nr. 3', '555-222-3333', 'ion@example.com', 103);
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (4, 'Elena', 'Georgescu', '3456789012345', 'Strada Angajatului, nr. 4', '555-333-4444', 'elena@example.com', 104);
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (5, 'Mihai', 'Stef?nescu', '4567890123456', 'Strada Angajatului, nr. 5', '555-444-5555', 'mihai@example.com', 105);

-- Sterg constragerile pentru tabela director, deoarece exista un singur director
--ALTER TABLE DIRECTOR
--DROP CONSTRAINT SYS_C00129012018;

-- Tabela DIRECTOR --
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 101, 1);
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 102, 2);
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 103, 3);
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 104, 4);
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 105, 5);



-- cerinta 6

CREATE OR REPLACE PROCEDURE actualizare_hrana(
    p_id_animal IN NUMBER,
    p_nume_hrana IN VARCHAR2,
    p_cantitate_aditionala IN NUMBER
) AS
    -- Variabila pentru a stoca cantitatea de hrana actualizata
    cantitate_actualizata NUMBER;

BEGIN
    -- Actualizarea cantitatii de hrana
    UPDATE HRANA
    SET CANTITATE = CANTITATE + p_cantitate_aditionala
    WHERE ID_MAGAZIN = p_id_animal AND DENUMIRE_PRODUS = p_nume_hrana;

    cantitate_actualizata := SQL%ROWCOUNT; 

    IF cantitate_actualizata > 0 THEN
        COMMIT;
        DBMS_OUTPUT.PUT_LINE('Cantitatea de hrana pentru animalul cu ID ' || p_id_animal || ' și ' || p_nume_hrana || ' a fost actualizata cu ' || p_cantitate_aditionala || ' unitați.');
    ELSE
        -- Gestionarea cazului în care nu exista înregistrare pentru actualizare
        DBMS_OUTPUT.PUT_LINE('Nu s-au gasit date pentru ID-ul animalului ' || p_id_animal || ' și ' || p_nume_hrana);
    END IF;
EXCEPTION
    WHEN OTHERS THEN
        -- Gestionarea altor erori
        DBMS_OUTPUT.PUT_LINE('A aparut o eroare: ' || SQLERRM);
END;
/


--set serveroutput on;


-- apelarea procedurii
-- pentru un ID valid:
DECLARE
    v_id_animal NUMBER := 1; -- ID-ul animalului pentru care se vrea actualizarea hranei
    v_nume_hrana VARCHAR2(255) := 'Hrana uscata pentru caini Pedigree Adult'; -- Numele hranei
    v_cantitate_aditionala NUMBER := 2; -- Cantitatea aditionala de hrana
BEGIN
    actualizare_hrana(
        p_id_animal => v_id_animal,
        p_nume_hrana => v_nume_hrana,
        p_cantitate_aditionala => v_cantitate_aditionala
    );
END;
/

-- pentru un ID invalid:
DECLARE
    v_id_animal NUMBER := 123456787654; -- ID-ul animalului pentru care se vrea actualizarea hranei
    v_nume_hrana VARCHAR2(255) := 'Hrana uscata pentru caini Pedigree Adult'; -- Numele hranei
    v_cantitate_aditionala NUMBER := 2; -- Cantitatea aditionala de hrana
BEGIN
    actualizare_hrana(
        p_id_animal => v_id_animal,
        p_nume_hrana => v_nume_hrana,
        p_cantitate_aditionala => v_cantitate_aditionala
    );
END;
/



-- cerinta 6 modificata

CREATE OR REPLACE PROCEDURE actualizare_hrana(
    p_id_animal IN NUMBER,
    p_nume_hrana IN VARCHAR2,
    p_cantitate_aditionala IN NUMBER
) AS
    -- Variabile pentru a stoca cantitatea de hrana actualizata
    cantitate_actualizata NUMBER;
    
    -- Tabel indexat
    TYPE Hrane_Indexate IS TABLE OF VARCHAR2(255) INDEX BY PLS_INTEGER;
    hrane_disponibile Hrane_Indexate;

    -- Tabel imbricat
    TYPE Hrane_Imbricate IS TABLE OF VARCHAR2(255);
    hrane_animal Hrane_Imbricate := Hrane_Imbricate();

BEGIN
    -- Adăugarea hranei disponibile în tabelul indexat
    hrane_disponibile(1) := 'Hrana uscata pentru caini Pedigree Adult';
    hrane_disponibile(2) := 'Hrana umeda pentru pisici Whiskas';
    
    -- Actualizarea cantitatii de hrana
    UPDATE HRANA
    SET CANTITATE = CANTITATE + p_cantitate_aditionala
    WHERE ID_MAGAZIN = p_id_animal AND DENUMIRE_PRODUS = p_nume_hrana;

    cantitate_actualizata := SQL%ROWCOUNT; 

    IF cantitate_actualizata > 0 THEN
        COMMIT;
        DBMS_OUTPUT.PUT_LINE('Cantitatea de hrana pentru animalul cu ID ' || p_id_animal || ' și ' || p_nume_hrana || ' a fost actualizata cu ' || p_cantitate_aditionala || ' unitați.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Nu s-au gasit date pentru ID-ul animalului ' || p_id_animal || ' și ' || p_nume_hrana);
    END IF;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('A aparut o eroare: ' || SQLERRM);
END;
/

--Tabel Indexat (Hrane_Indexate)
--Tabel Imbricat (Hrane_Imbricate)
--Vector (Vector_Hrane)


-- apelare

DECLARE
    v_id_animal NUMBER := 1;
    v_nume_hrana VARCHAR2(255) := 'Hrana uscata pentru caini Pedigree Adult'; 
    v_cantitate_aditionala NUMBER := 2; 
BEGIN
    actualizare_hrana(
        p_id_animal => v_id_animal,
        p_nume_hrana => v_nume_hrana,
        p_cantitate_aditionala => v_cantitate_aditionala
    );
END;
/

DECLARE
    v_id_animal NUMBER := 123456787654; 
    v_nume_hrana VARCHAR2(255) := 'Hrana uscata pentru caini Pedigree Adult';
    v_cantitate_aditionala NUMBER := 2; 
BEGIN
    actualizare_hrana(
        p_id_animal => v_id_animal,
        p_nume_hrana => v_nume_hrana,
        p_cantitate_aditionala => v_cantitate_aditionala
    );
END;
/


    


-- cerinta 7

CREATE OR REPLACE PROCEDURE afisare_animale_adoptate(
    dataAdoptie IN DATE
) AS
    -- Declaram cursorul pentru animale adoptate
    CURSOR curAnimaleAdoptate IS
        SELECT ca.SERIE, a.NUME, a.RASA, a.VARSTA, a.SEX, a.DATA_SOSIRE, v.NUME || ' ' || v.PRENUME AS NUME_VETERINAR, a.ID_ANIMAL
        FROM CERERE_ADOPTIE ca
        JOIN ANIMAL a ON ca.ID_ANIMAL = a.ID_ANIMAL
        JOIN VETERINAR v ON a.ID_VETERINAR = v.CNP
        WHERE ca.DATA = dataAdoptie;

    -- Declaram variabila pentru ID_ANIMAL
    v_ID_ANIMAL INT;
    v_au_fost_adoptate BOOLEAN := FALSE;

BEGIN
    -- Parcurgem animalele adoptate
    FOR animalAdoptat IN curAnimaleAdoptate LOOP
        -- Salvam ID_ANIMAL in variabila
        v_ID_ANIMAL := animalAdoptat.ID_ANIMAL;
        v_au_fost_adoptate := TRUE;

        DBMS_OUTPUT.PUT_LINE('----------------------------------------');
        DBMS_OUTPUT.PUT_LINE('Serie: ' || animalAdoptat.SERIE);
        DBMS_OUTPUT.PUT_LINE('Nume: ' || animalAdoptat.NUME);
        DBMS_OUTPUT.PUT_LINE('Rasa: ' || animalAdoptat.RASA);
        DBMS_OUTPUT.PUT_LINE('Varsta: ' || animalAdoptat.VARSTA);
        DBMS_OUTPUT.PUT_LINE('Sex: ' || animalAdoptat.SEX);
        DBMS_OUTPUT.PUT_LINE('Data sosire: ' || TO_CHAR(animalAdoptat.DATA_SOSIRE, 'YYYY-MM-DD'));
        DBMS_OUTPUT.PUT_LINE('Veterinar: ' || animalAdoptat.NUME_VETERINAR);
        DBMS_OUTPUT.PUT_LINE('----------------------------------------');

        -- Obtinem informatii suplimentare folosind cursorul parametrizat
        FOR infoSuplimentare IN (
            SELECT cs.VACCINURI, cs.DATA_NASTERE, cs.ANTECEDENTE_MEDICALE
            FROM CARTE_DE_SANATATE cs
            WHERE cs.ID_ANIMAL = v_ID_ANIMAL
        ) LOOP
            DBMS_OUTPUT.PUT_LINE('Vaccinuri: ' || infoSuplimentare.VACCINURI);
            DBMS_OUTPUT.PUT_LINE('Data nasterii: ' || TO_CHAR(infoSuplimentare.DATA_NASTERE, 'YYYY-MM-DD'));
            DBMS_OUTPUT.PUT_LINE('Antecedente medicale: ' || infoSuplimentare.ANTECEDENTE_MEDICALE);
        END LOOP;

        DBMS_OUTPUT.PUT_LINE('----------------------------------------');
    END LOOP;

    IF NOT v_au_fost_adoptate THEN
        DBMS_OUTPUT.PUT_LINE('Nu au fost adoptate animale in data introdusa.');
    END IF;
END afisare_animale_adoptate;
/

-- apelare

BEGIN
    afisare_animale_adoptate(TO_DATE('2023-08-02', 'YYYY-MM-DD'));
END;
/

BEGIN
    afisare_animale_adoptate(TO_DATE('2023-08-03', 'YYYY-MM-DD'));
END;
/

BEGIN
    afisare_animale_adoptate(TO_DATE('2025-01-20', 'YYYY-MM-DD'));
END;
/

 
-- cerinta 8


CREATE OR REPLACE FUNCTION obt_medicament_animal(p_ID_Animal INT)
RETURN VARCHAR2 IS
  v_Medicament VARCHAR2(255);
BEGIN
  SELECT M.DENUMIRE_PRODUS
  INTO v_Medicament
  FROM MEDICAMENT M
  JOIN CARTE_DE_SANATATE CS ON M.NUMAR = CS.ID_ANIMAL
  WHERE CS.ID_ANIMAL = p_ID_Animal;

  RETURN v_Medicament;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    RETURN 'Animalul nu are informații în carnetul de sanatate.';
  WHEN OTHERS THEN
    RETURN 'Eroare necunoscuta: ' || SQLERRM;
END obt_medicament_animal;
/

    
-- apelare
-- ID animal valid
DECLARE
  v_ID_Animal INT := 1;
  v_Resultat VARCHAR2(255);
BEGIN
  v_Resultat := obt_medicament_animal(v_ID_Animal);
  DBMS_OUTPUT.PUT_LINE('Medicament recomandat pentru animalul cu ID ' || v_ID_Animal || ': ' || v_Resultat);
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
END;
/

-- ID animal invalid
DECLARE
  v_ID_Animal INT := 15688324;
  v_Resultat VARCHAR2(255);
BEGIN
  v_Resultat := obt_medicament_animal(v_ID_Animal);
  DBMS_OUTPUT.PUT_LINE('Medicament recomandat pentru animalul cu ID ' || v_ID_Animal || ': ' || v_Resultat);
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
END;
/


-- cerinta 8 modificata

CREATE TABLE ISTORIC_MEDICAMENTE (
  ID_ANIMAL INT,
  MEDICAMENT VARCHAR2(255)
);


CREATE OR REPLACE FUNCTION obt_medicament_animal(p_ID_Animal INT)
RETURN VARCHAR2 IS
  v_Medicament VARCHAR2(255);
  v_Count NUMBER; 
  MedicamentRecomandat EXCEPTION; 
BEGIN
  SELECT M.DENUMIRE_PRODUS
  INTO v_Medicament
  FROM MEDICAMENT M
  JOIN CARTE_DE_SANATATE CS ON M.NUMAR = CS.ID_ANIMAL
  WHERE CS.ID_ANIMAL = p_ID_Animal;

  SELECT COUNT(*)
  INTO v_Count
  FROM ISTORIC_MEDICAMENTE
  WHERE ID_ANIMAL = p_ID_Animal AND MEDICAMENT = v_Medicament;

  IF v_Count > 0 THEN
    RAISE MedicamentRecomandat;
  END IF;

  INSERT INTO ISTORIC_MEDICAMENTE (ID_ANIMAL, MEDICAMENT) VALUES (p_ID_Animal, v_Medicament);

  RETURN v_Medicament;

EXCEPTION
  WHEN NO_DATA_FOUND THEN
    RETURN 'Animalul nu are informații în carnetul de sănătate.';
  WHEN MedicamentRecomandat THEN
    RETURN 'Animalului i-a fost deja recomandat acest medicament.';
  WHEN OTHERS THEN
    RETURN 'Eroare necunoscută: ' || SQLERRM;
END obt_medicament_animal;
/


    -- Testăm funcția cu un ID animal valid
BEGIN
  DECLARE
    v_ID_Animal INT := 1;
    v_Resultat VARCHAR2(255);
  BEGIN
    v_Resultat := obt_medicament_animal(v_ID_Animal);
    DBMS_OUTPUT.PUT_LINE('Medicament recomandat pentru animalul cu ID ' || v_ID_Animal || ': ' || v_Resultat);
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
  END;
END;
/

-- Testăm funcția cu un ID animal invalid
BEGIN
  DECLARE
    v_ID_Animal INT := 15688324;
    v_Resultat VARCHAR2(255);
  BEGIN
    v_Resultat := obt_medicament_animal(v_ID_Animal);
    DBMS_OUTPUT.PUT_LINE('Medicament recomandat pentru animalul cu ID ' || v_ID_Animal || ': ' || v_Resultat);
  EXCEPTION
    WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
  END;
END;
/



    

-- cerinta 9

CREATE OR REPLACE PROCEDURE informatii_animal(p_ID_Animal INT) IS
  v_NumeAnimal VARCHAR2(255);
  v_RasaAnimal VARCHAR2(255);
  v_DenumireClinica VARCHAR2(255);
  v_TipNevoieSector VARCHAR2(255);
  v_NumeFarmacie VARCHAR2(255);
  v_RecordCount INT := 0;
BEGIN
  SELECT A.NUME, A.RASA, C.DENUMIRE, S.TIP_NEVOIE, F.NUME
  INTO v_NumeAnimal, v_RasaAnimal, v_DenumireClinica, v_TipNevoieSector, v_NumeFarmacie
  FROM ANIMAL A
  JOIN CLINICA_VETERINARA C ON A.ID_VETERINAR = C.ID_VETERINAR
  JOIN SECTIE_SECTOR SS ON SS.ID_SECTIE = A.ID_CUSCA
  JOIN SECTOR S ON S.ID_SECTOR = SS.ID_SECTOR
  LEFT JOIN MED M ON M.ID_FARMACIE = S.ID_SECTOR
  LEFT JOIN FARMACIE F ON F.ID_FARMACIE = M.ID_FARMACIE
  WHERE A.ID_ANIMAL = p_ID_Animal AND ROWNUM = 1
  ORDER BY A.DATA_SOSIRE DESC;

  -- Numărul de înregistrări găsite
  SELECT COUNT(*)
  INTO v_RecordCount
  FROM ANIMAL A
  JOIN CLINICA_VETERINARA C ON A.ID_VETERINAR = C.ID_VETERINAR
  JOIN SECTIE_SECTOR SS ON SS.ID_SECTIE = A.ID_CUSCA
  JOIN SECTOR S ON S.ID_SECTOR = SS.ID_SECTOR
  LEFT JOIN MED M ON M.ID_FARMACIE = S.ID_SECTOR
  LEFT JOIN FARMACIE F ON F.ID_FARMACIE = M.ID_FARMACIE
  WHERE A.ID_ANIMAL = p_ID_Animal;

  -- Poți adăuga aici operații suplimentare folosind variabilele create

  -- Afisează doar prima înregistrare dacă sunt mai multe
  IF v_RecordCount > 1 THEN
        DBMS_OUTPUT.PUT_LINE('----------------------------------------');
		DBMS_OUTPUT.PUT_LINE('S-au găsit prea multe înregistrări pentru animalul cu ID ' || p_ID_Animal || '. Se afișează doar prima înregistrare.');
        DBMS_OUTPUT.PUT_LINE('----------------------------------------');
  END IF;

      DBMS_OUTPUT.PUT_LINE('Numele animalului cu ID ' || p_ID_Animal || ': ' || v_NumeAnimal);
      DBMS_OUTPUT.PUT_LINE('Rasa animalului: ' || v_RasaAnimal);
      DBMS_OUTPUT.PUT_LINE('Clinica veterinară asociată: ' || v_DenumireClinica);
 	  DBMS_OUTPUT.PUT_LINE('Sector cu nevoie: ' || v_TipNevoieSector);
	  DBMS_OUTPUT.PUT_LINE('----------------------------------------');
EXCEPTION
  WHEN NO_DATA_FOUND THEN
	DBMS_OUTPUT.PUT_LINE('----------------------------------------');
    DBMS_OUTPUT.PUT_LINE('Animalul cu ID ' || p_ID_Animal || ' nu a fost găsit.');
    DBMS_OUTPUT.PUT_LINE('----------------------------------------');
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Eroare necunoscută: ' || SQLERRM);
END informatii_animal;
/

-- apelare 

DECLARE
  v_ID_Animal INT := 1;
BEGIN
  informatii_animal(v_ID_Animal);
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
END;
/
    

DECLARE
  v_ID_Animal INT := 9;
BEGIN
  informatii_animal(v_ID_Animal);
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Eroare: ' || SQLERRM);
END;
/

    
-- cerinta 10


-- Definirea trigger-ului de tip LMD la nivel de comanda
CREATE OR REPLACE TRIGGER trg_lmd_comanda
BEFORE INSERT OR UPDATE ON HRANA
DECLARE
    v_user VARCHAR2(30);
BEGIN
    -- Obținerea numelui utilizatorului care a efectuat acțiunea
    SELECT USER INTO v_user FROM DUAL;

    -- Afișarea unui mesaj înainte de efectuarea operațiunii
    DBMS_OUTPUT.PUT_LINE('Trigger LMD la nivel de comanda declanșat de catre ' || v_user);
END;
/

-- Declanșarea trigger-ului prin efectuarea unei modificari în tabelul HRANA
UPDATE HRANA SET CANTITATE = CANTITATE + 5 WHERE NUMAR = 1;

-- Sau prin inserarea unui nou înregistrare în tabelul HRANA
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN) VALUES (6, 'Hrana test', 10, 1);


-- cerinta 11

-- Definirea trigger-ului de tip LMD la nivel de linie
CREATE OR REPLACE TRIGGER trg_lmd_linie
BEFORE INSERT OR UPDATE ON HRANA
FOR EACH ROW
DECLARE
    v_user VARCHAR2(30);
BEGIN
    -- Obținerea numelui utilizatorului care a efectuat acțiunea
    SELECT USER INTO v_user FROM DUAL;

    -- Afișarea unui mesaj înainte de efectuarea operațiunii pentru fiecare înregistrare
    DBMS_OUTPUT.PUT_LINE('Trigger LMD la nivel de linie declanșat de catre ' || v_user || ' pentru înregistrarea cu NUMAR ' || :NEW.NUMAR);
END;
/

-- Declanșarea trigger-ului prin efectuarea unei modificari în tabelul HRANA
UPDATE HRANA SET CANTITATE = CANTITATE + 5 WHERE NUMAR = 1;

-- Sau prin inserarea unui nou înregistrare în tabelul HRANA
INSERT INTO HRANA (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_MAGAZIN) VALUES (7, 'Hrana test', 10, 1);


-- cerinta 12 

CREATE OR REPLACE TRIGGER trg_ldd_trigger
AFTER CREATE OR ALTER OR DROP ON SCHEMA
DECLARE
   object_name   VARCHAR2(30);
   ddl_action    VARCHAR2(30);
BEGIN
   object_name := ORA_DICT_OBJ_NAME;
   ddl_action  := ora_sysevent;

   -- Afișeaza mesajul cu detaliile acțiunii
   DBMS_OUTPUT.PUT_LINE('Trigger LDD - Schema action: ' || ddl_action || ', Object name: ' || object_name);
END;
/

--SET SERVEROUTPUT ON;


--SELECT *
--FROM ALL_ERRORS
--WHERE NAME = 'TRG_LDD_TRIGGER';


-- testare trigger
CREATE TABLE Exemplu (
    ID INT PRIMARY KEY,
    NUME VARCHAR2(50)
);

DROP TABLE EXEMPLU;



-- cerinta 13

CREATE OR REPLACE PACKAGE ANIMAL_SHEET AS
    -- Tipurile de date
    TYPE NumereAnimale IS TABLE OF NUMBER INDEX BY PLS_INTEGER;
    TYPE HranaCantitate IS TABLE OF NUMBER INDEX BY VARCHAR2(255);

    -- Procedura pentru cerinta 6
    PROCEDURE actualizare_hrana(
        p_id_animal IN NUMBER,
        p_nume_hrana IN VARCHAR2,
        p_cantitate_aditionala IN NUMBER
    );

    -- Procedura pentru cerinta 7
    PROCEDURE afisare_animale_adoptate(
        dataAdoptie IN DATE
    );

    -- Functia pentru cerinta 8
    FUNCTION obt_medicament_animal(p_ID_Animal INT) RETURN VARCHAR2;

    -- Procedura pentru cerinta 9
    PROCEDURE informatii_animal(p_ID_Animal INT);

    -- Trigger pentru cerinta 10
    -- Trigger de tip LMD la nivel de comanda
    PROCEDURE trg_lmd_comanda;

    -- Trigger pentru cerinta 11
    -- Trigger de tip LMD la nivel de linie
    PROCEDURE trg_lmd_linie;

    -- Trigger pentru cerinta 12
    PROCEDURE trg_ldd_trigger;
END ANIMAL_SHEET;
/


-- Cerinta 14

CREATE OR REPLACE PACKAGE BODY ANIMAL_SHEET AS
    -- Tipurile de date complexe
    TYPE DetaliiAnimal IS RECORD (
        NUME VARCHAR2(255),
        RASA VARCHAR2(255),
        VARSTA INT,
        SEX VARCHAR2(255),
        VETERINAR VARCHAR2(255)
    );

    TYPE DetaliiHrana IS RECORD (
        NUMAR INT,
        DENUMIRE_PRODUS VARCHAR2(255),
        CANTITATE INT
    );

    -- Procedura pentru actualizarea hranei
    PROCEDURE actualizare_hrana(
        p_id_animal IN NUMBER,
        p_nume_hrana IN VARCHAR2,
        p_cantitate_aditionala IN NUMBER
    ) AS
        -- Definirea variabilei cantitate_actualizata
        cantitate_actualizata NUMBER;

    BEGIN
        -- Detalii suplimentare pentru animale
        FOR animal IN (SELECT A.NUME, A.RASA, A.VARSTA, A.SEX, V.NUME || ' ' || V.PRENUME AS VETERINAR
                        FROM ANIMAL A
                        JOIN VETERINAR V ON A.ID_VETERINAR = V.CNP
                        WHERE A.ID_ANIMAL = p_id_animal) LOOP

            -- Afisarea detaliilor animalelor
            DBMS_OUTPUT.PUT_LINE('Detalii despre animal: ' || animal.NUME || ', ' || animal.RASA || ', ' ||
                                animal.VARSTA || ' ani, ' || animal.SEX || ', Veterinar: ' || animal.VETERINAR);
        END LOOP;

        -- Initializarea colectiei cu cantitatile de hrana necesare
        FOR hrana IN (SELECT NUMAR, DENUMIRE_PRODUS, CANTITATE + p_cantitate_aditionala AS CANTITATE
                        FROM HRANA
                        WHERE NUMAR = p_id_animal AND DENUMIRE_PRODUS = p_nume_hrana) LOOP
            cantitate_actualizata := hrana.CANTITATE;

            -- Actualizarea cantitatii de hrana
            UPDATE HRANA
            SET CANTITATE = cantitate_actualizata
            WHERE NUMAR = hrana.NUMAR AND DENUMIRE_PRODUS = hrana.DENUMIRE_PRODUS;

            -- Afisarea detaliilor hranei actualizate
            DBMS_OUTPUT.PUT_LINE('Hrana actualizata: ' || hrana.DENUMIRE_PRODUS || ', Cantitate: ' || cantitate_actualizata);
        END LOOP;
    END actualizare_hrana;

    -- Functia cursor_parametrizat
    FUNCTION cursor_parametrizat(p_nume_hrana VARCHAR2) RETURN SYS_REFCURSOR IS
        v_cursor SYS_REFCURSOR;

    BEGIN
        -- Deschiderea cursorului parametrizat
        OPEN v_cursor FOR
            SELECT NUMAR, DENUMIRE_PRODUS, CANTITATE
            FROM HRANA
            WHERE DENUMIRE_PRODUS = p_nume_hrana;

        -- Returnarea cursorului
        RETURN v_cursor;
    END cursor_parametrizat;

    -- Functia cursor_dependent
    FUNCTION cursor_dependent(p_nume_hrana VARCHAR2) RETURN SYS_REFCURSOR IS
        v_cursor SYS_REFCURSOR;

    BEGIN
        -- Deschiderea cursorului dependent
        OPEN v_cursor FOR
            SELECT A.NUME, A.RASA, H.NUMAR, H.DENUMIRE_PRODUS, H.CANTITATE
            FROM ANIMAL A
            JOIN HRANA H ON A.ID_ANIMAL = H.NUMAR
            WHERE H.DENUMIRE_PRODUS = p_nume_hrana;

        -- Returnarea cursorului
        RETURN v_cursor;
    END cursor_dependent;

    
    -- Procedura pentru cerinta 7
    PROCEDURE afisare_animale_adoptate(
        dataAdoptie IN DATE
    ) IS
        -- Definirea variabilei de tip NumereAnimale
        numere_animele NumereAnimale;

    BEGIN
        -- Initializarea variabilei de tip NumereAnimale
        numere_animele(1) := 1;
        numere_animele(2) := 2;

        -- Afisarea numerelor animalelor adoptate
        FOR i IN 1..numere_animele.COUNT LOOP
            DBMS_OUTPUT.PUT_LINE('Animal adoptat: ' || numere_animele(i) || ', Data adoptiei: ' || TO_CHAR(dataAdoptie, 'DD-MON-YYYY'));
        END LOOP;
    END afisare_animale_adoptate;

    -- Functia pentru cerinta 8
    FUNCTION obt_medicament_animal(p_ID_Animal INT) RETURN VARCHAR2 IS
        -- Definirea variabilei medicament
        medicament VARCHAR2(255);

    BEGIN
        -- Setarea valorii default pentru medicament
        medicament := 'Nu are medicament';

        -- Returnarea valorii medicamentului
        RETURN medicament;
    END obt_medicament_animal;

    -- Procedura pentru cerinta 9
    PROCEDURE informatii_animal(p_ID_Animal INT) IS
        -- Definirea variabilei de tip DetaliiAnimal
        detalii_animal DetaliiAnimal;

    BEGIN
        -- Obtine detaliile animalelor
        SELECT A.NUME, A.RASA, A.VARSTA, A.SEX, V.NUME || ' ' || V.PRENUME
        INTO detalii_animal
        FROM ANIMAL A
        JOIN VETERINAR V ON A.ID_VETERINAR = V.CNP
        WHERE A.ID_ANIMAL = p_ID_Animal;

        -- Afisarea detaliilor animalelor
        DBMS_OUTPUT.PUT_LINE('Detalii despre animal: ' || detalii_animal.NUME || ', ' || detalii_animal.RASA || ', ' ||
                            detalii_animal.VARSTA || ' ani, ' || detalii_animal.SEX || ', Veterinar: ' || detalii_animal.VETERINAR);
    END informatii_animal;

    -- Trigger pentru cerinta 10
    -- Trigger de tip LMD la nivel de comanda
    PROCEDURE trg_lmd_comanda IS
    BEGIN
        -- Implementarea logicii pentru trigger-ul LMD la nivel de comanda
        NULL;
    END trg_lmd_comanda;

    -- Trigger pentru cerinta 11
    -- Trigger de tip LMD la nivel de linie
    PROCEDURE trg_lmd_linie IS
    BEGIN
        -- Implementarea logicii pentru trigger-ul LMD la nivel de linie
        NULL;
    END trg_lmd_linie;

    -- Trigger pentru cerinta 12
    PROCEDURE trg_ldd_trigger IS
    BEGIN
        -- Implementarea logicii pentru trigger-ul LDD
        NULL;
    END trg_ldd_trigger;

END ANIMAL_SHEET;
/


-- ex 6 ad colectii: tablou imbricat, tablou indexat, vector
-- ex 8 exceptii proprii


