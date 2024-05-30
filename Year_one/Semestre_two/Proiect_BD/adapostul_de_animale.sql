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



---------------------------------------------------------------------------------------------------------------------------------------------------------------



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
--INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
--VALUES (1, 'ANIMAX VET SRL', '33522396', '9 AM - 6 PM', 2);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (2, 'PET BOUTIQUE', '38440980', '10 AM - 8 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (3, 'ANIMAL AREA', '39898404', '12 AM - 6 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (4, ' GROOM VET C&A SRL', '41654738', '8 AM - 8 PM', 1);
INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (5, 'PETMART ONLINE SRL', '32167601', '24/7', 1);

-- Tabela MED --
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (1, 1);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (1, 2);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (1, 3);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (2, 2);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (2, 4);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (3, 3);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (3, 5);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (4, 4);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (4, 1);
INSERT INTO MED (ID_FARMACIE, NUMAR) VALUES (5, 5);



-- Tabela MAGAZIN --
INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
VALUES (1, 1, 'Animax – Pet Store', '987-654-3456', '10 AM - 8 PM');
--INSERT INTO MAGAZIN (ID_MAGAZIN, ID_CONTRACT, NUME, TELEFON, PROGRAM)
--VALUES (1, 2, 'PetMart', '987-654-3210', '10 AM - 8 PM');
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
VALUES (5, 'Mihai', 'Stefănescu', '4567890123456', 'Strada Angajatului, nr. 5', '555-444-5555', 'mihai@example.com', 105);

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



---------------------------------------------------------------------------------------------------------------------------------------------------------------



-- 12. 
-- a) Subcereri sincronizate în care intervin cel puțin 3 tabele
SELECT A.ID_ANIMAL, A.NUME, V.NUME AS NUME_VETERINAR, C.VACCINURI
FROM ANIMAL A
JOIN VETERINAR V ON A.ID_VETERINAR = V.CNP
JOIN CARTE_DE_SANATATE C ON A.ID_ANIMAL = C.ID_ANIMAL
WHERE EXISTS (
    SELECT 1
    FROM CARTE_DE_SANATATE C2
    WHERE C2.ID_ANIMAL = A.ID_ANIMAL AND C2.VACCINURI LIKE '%Rabie%'
);

-- b) Subcereri nesincronizate în clauza FROM
SELECT X."DENUMIRE FARMACIE", X."DENUMIRE MEDICAMENT", X."CANTITATE DISPONIBILA"
FROM (
    SELECT F.NUME AS "DENUMIRE FARMACIE", M.DENUMIRE_PRODUS AS "DENUMIRE MEDICAMENT", M.CANTITATE AS "CANTITATE DISPONIBILA"
    FROM FARMACIE F
    JOIN MEDICAMENT M ON F.NUMAR = M.NUMAR
) X;

-- c) Grupări de date, funcții grup, filtrare la nivel de grupuri cu subcereri 
SELECT S.TIP_NEVOIE, COUNT(A.ID_ANIMAL) AS NUMAR_ANIMALE
FROM SECTOR S
JOIN SECTIE_SECTOR SS ON S.ID_SECTOR = SS.ID_SECTOR
JOIN SECTIE SE ON SS.ID_SECTIE = SE.ID_SECTIE
JOIN ANIMAL A ON SE.ID_CUSCA = A.ID_CUSCA
GROUP BY S.TIP_NEVOIE
HAVING COUNT(A.ID_ANIMAL) > (
    SELECT AVG(COUNT(A2.ID_ANIMAL))
    FROM SECTOR S2
    JOIN SECTIE_SECTOR SS2 ON S2.ID_SECTOR = SS2.ID_SECTOR
    JOIN SECTIE SE2 ON SS2.ID_SECTIE = SE2.ID_SECTIE
    JOIN ANIMAL A2 ON SE2.ID_CUSCA = A2.ID_CUSCA
    GROUP BY S2.TIP_NEVOIE
);

-- d) Ordonări și utilizarea funcțiilor NVL și DECODE
ALTER TABLE CERERE_ADOPTIE ADD TIP_CERERE VARCHAR(255);

-- Interogarea:
SELECT V.NUME, V.PRENUME, NVL(CA.NUMAR_CERERI, 0) AS NUMAR_CERERI,
    DECODE(CA.TIP_CERERE, 'Urgent', CA.NUMAR_CERERI * 1.2, CA.NUMAR_CERERI) AS AJUSTARE_CERERI
FROM VIZITATOR V
LEFT JOIN (
    SELECT ID_VIZITATOR, COUNT(*) AS NUMAR_CERERI, MAX(TIP_CERERE) AS TIP_CERERE
    FROM CERERE_ADOPTIE
    GROUP BY ID_VIZITATOR
) CA ON V.CNP = CA.ID_VIZITATOR
ORDER BY V.NUME, V.PRENUME;


-- e) Utilizarea funcțiilor pe șiruri de caractere, funcții pe date calendaristice și expresii CASE
ALTER TABLE VETERINAR ADD SPECIALITATE VARCHAR(255);

-- Interogarea:
SELECT A.NUME,
    TRUNC(MONTHS_BETWEEN(SYSDATE, A.DATA_SOSIRE) / 12) AS ANI,
    MOD(TRUNC(MONTHS_BETWEEN(SYSDATE, A.DATA_SOSIRE)), 12) AS LUNI,
    INITCAP(A.NUME) AS NUME_COMPLET,
    REPLACE(C.VACCINURI, 'Rabie', 'Antirabic') AS TIP_VACCIN,
    CASE 
        WHEN V.SPECIALITATE = 'Chirurgie' THEN 'Chirurg'
        ELSE 'Generalist'
    END AS TIP_VETERINAR
FROM ANIMAL A
JOIN CARTE_DE_SANATATE C ON A.ID_ANIMAL = C.ID_ANIMAL
JOIN VETERINAR V ON A.ID_VETERINAR = V.CNP;

-- Funcții pe șiruri de caractere:

-- INITCAP(A.NUME) AS NUME_COMPLET - Transformă primul caracter al fiecărui cuvânt în majusculă și restul în minuscule.
-- REPLACE(C.VACCINURI, 'Rabie', 'Antirabic') AS TIP_VACCIN - Înlocuiește toate aparițiile șirului 'Rabie' cu 'Antirabic'.
-- Funcții pe date calendaristice:

-- TRUNC(MONTHS_BETWEEN(SYSDATE, A.DATA_SOSIRE) / 12) AS ANI - Calculează numărul de ani între data curentă și DATA_SOSIRE a animalului.
-- MOD(TRUNC(MONTHS_BETWEEN(SYSDATE, A.DATA_SOSIRE)), 12) AS LUNI - Calculează numărul de luni (restul) din numărul total de luni dintre data curentă și DATA_SOSIRE.
-- Expresii CASE:

-- CASE WHEN V.SPECIALITATE = 'Chirurgie' THEN 'Chirurg' ELSE 'Generalist' END AS TIP_VETERINAR - Returnează 'Chirurg' dacă SPECIALITATE este 'Chirurgie', altfel returnează 'Generalist'.




-- f) Utilizarea clauzei WITH
--ALTER TABLE SECTIE ADD NUME_SECTIE VARCHAR(255);

-- Interogarea:
WITH ANIMALE_PE_SECTIE AS (
    SELECT SE.ID_SECTIE, COUNT(A.ID_ANIMAL) AS NUMAR_ANIMALE
    FROM SECTIE SE
    JOIN ANIMAL A ON SE.ID_CUSCA = A.ID_CUSCA
    GROUP BY SE.ID_SECTIE
)
SELECT SE.NUME AS NUME_SECTIE, AP.NUMAR_ANIMALE
FROM SECTIE SE
JOIN ANIMALE_PE_SECTIE AP ON SE.ID_SECTIE = AP.ID_SECTIE;


---------------------------------------------------------------------------------------------------------------------------------------------------------------


-- 13 a) Operații de actualizare (UPDATE) utilizând subcereri

-- 13.1 Actualizarea numărului de locuri din cuști în funcție de numărul de animale alocate:
UPDATE CUSCA
SET NUMAR_LOCURI = NUMAR_LOCURI - (
    SELECT COUNT(*)
    FROM ANIMAL A
    WHERE A.ID_CUSCA = CUSCA.ID_CUSCA
)
WHERE ID_CUSCA IN (
    SELECT ID_CUSCA
    FROM ANIMAL
);

-- 13.2 Actualizarea denumirii produselor în magazin bazată pe contractul asociat:
UPDATE MAGAZIN
SET NUME = (
    SELECT TIP
    FROM CONTRACT C
    WHERE C.ID_MAGAZIN = MAGAZIN.ID_MAGAZIN
)
WHERE ID_MAGAZIN IN (
    SELECT ID_MAGAZIN
    FROM CONTRACT
);

-- 13.3 Actualizarea numărului de medicamente disponibile în farmacie în funcție de stocul curent:
UPDATE FARMACIE F
SET NUMAR = (
    SELECT COUNT(*)
    FROM MED M
    WHERE M.ID_FARMACIE = F.ID_FARMACIE
)
WHERE F.ID_FARMACIE IN (
    SELECT DISTINCT ID_FARMACIE
    FROM MED
);


-- 13 b) Operații de suprimare (DELETE) utilizând subcereri
-- 13.4 Ștergerea animalelor care nu au fost vizitate în ultimele 6 luni:
DELETE FROM CONSULTATIE C
WHERE C.ID_ANIMAL IN (
    SELECT A.ID_ANIMAL
    FROM ANIMAL A
    LEFT JOIN CONSULTATIE C2 ON A.ID_ANIMAL = C2.ID_ANIMAL
    WHERE C2.ID_ANIMAL IS NULL OR C2.DATA < ADD_MONTHS(SYSDATE, -6)
);


-- 13.5 Ștergerea vizitatorilor care nu au cereri de adopție asociate:
DELETE FROM VIZITATOR
WHERE CNP NOT IN (
    SELECT DISTINCT ID_VIZITATOR
    FROM CERERE_ADOPTIE
);

-- 13.6 Ștergerea magazinelor fără produse asociate:
DELETE FROM MAGAZIN
WHERE ID_MAGAZIN NOT IN (
    SELECT DISTINCT ID_MAGAZIN
    FROM HRANA
);




---------------------------------------------------------------------------------------------------------------------------------------------------------------



-- 14) 
-- cele 3 tabele: ANIMAL, VETERINAR, si SECTIE.
CREATE VIEW VIZUALIZARE_ANIMALE AS
SELECT A.ID_ANIMAL, A.NUME, A.RASA, A.VARSTA, V.NUME AS NUME_VETERINAR, S.NUME AS NUME_SECTIE
FROM ANIMAL A
JOIN VETERINAR V ON A.ID_VETERINAR = V.CNP
JOIN SECTIE S ON A.ID_CUSCA = S.ID_CUSCA;

-- Operație LMD permisă
SELECT * FROM VIZUALIZARE_ANIMALE;

-- Operație LMD nepermisă
INSERT INTO VIZUALIZARE_ANIMALE (ID_ANIMAL, NUME, RASA, VARSTA, NUME_VETERINAR, NUME_SECTIE)
VALUES (6, 'Bella', 'Poodle', 2, 'Elena Popa', 'Sectia 1');
-- Operația de inserare (INSERT) nu este permisă deoarece vizualizarea combină date din mai multe tabele,
-- iar inserarea directă ar necesita actualizări coerente în toate tabelele implicate,
-- ceea ce nu poate fi realizat printr-o singură operație de inserare în vizualizare.



---------------------------------------------------------------------------------------------------------------------------------------------------------------



--15. 
-- Operația outerjoin pe minimum 4 tabele
SELECT *
FROM ANIMAL A
LEFT JOIN CUSCA C ON A.ID_CUSCA = C.ID_CUSCA
LEFT JOIN SECTIE S ON A.ID_CUSCA = S.ID_CUSCA
LEFT JOIN SECTIE_SECTOR SS ON S.ID_SECTIE = SS.ID_SECTIE
LEFT JOIN SECTOR SE ON SS.ID_SECTOR = SE.ID_SECTOR;

-- 15. Operația outerjoin pe minimum 4 tabele
SELECT A.ID_ANIMAL, A.NUME, S.NUME AS NUME_SECTIE, SECTOR.TIP_NEVOIE, C.VACCINURI
FROM ANIMAL A
LEFT JOIN SECTIE S ON A.ID_CUSCA = S.ID_CUSCA
LEFT JOIN SECTIE_SECTOR SS ON S.ID_SECTIE = SS.ID_SECTIE
LEFT JOIN SECTOR SECTOR ON SS.ID_SECTOR = SECTOR.ID_SECTOR
LEFT JOIN CARTE_DE_SANATATE C ON A.ID_ANIMAL = C.ID_ANIMAL;


-- Vrem să identificăm acele animale care se află în fiecare secție existentă.
-- Cerere ce utilizează operația division
SELECT A.NUME
FROM ANIMAL A
WHERE NOT EXISTS (
    SELECT S.ID_SECTOR
    FROM SECTOR S
    WHERE NOT EXISTS (
        SELECT 1
        FROM SECTIE_SECTOR SS
        JOIN SECTIE SE ON SS.ID_SECTIE = SE.ID_SECTIE
        WHERE SE.ID_CUSCA = A.ID_CUSCA
          AND SS.ID_SECTOR = S.ID_SECTOR
    )
);



-- Cerere care implementează analiza top-n
SELECT *
FROM (
    SELECT A.NUME, A.RASA, A.VARSTA, RANK() OVER (ORDER BY A.VARSTA DESC) AS RANG
    FROM ANIMAL A
)
WHERE RANG <= 3;



---------------------------------------------------------------------------------------------------------------------------------------------------------------



-- 16. optimizare

-- sql initial
SELECT A.NUME, M.NUME 
FROM ANGAJAT A
JOIN CONTRACT C ON A.ID_CONTRACT = C.NUMAR
JOIN MAGAZIN M ON C.id_magazin = M.ID_MAGAZIN
WHERE A.NUME LIKE 'A%';

-- Arbore initial
-- π A.NUME, M.NUME
--    |
-- σ A.NUME LIKE 'A%' AND M.NUMAR_LOCURI > 10
--    |
-- ⋈ C.id_magazin = M.ID_MAGAZIN
--    |
-- ⋈ A.ID_CONTRACT = C.NUMAR
--    |
-- ANGAJAT      CONTRACT      MAGAZIN


-- Regulile de optimizare:
-- Regula 1: Realizarea selecțiilor cât mai jos posibil.
-- Regula 3: Combinarea selecțiilor.
-- Regula 5: Comutativitatea selecțiilor cu proiectiile.
-- Regula 6: Folosirea indecsilor pentru îmbunătățirea performanței.


-- Arbore optimizat
-- π A.NUME, M.NUME
--    |
-- ⋈ C.id_magazin = M.ID_MAGAZIN
--    |
-- σ M.NUMAR_LOCURI > 10
--    |
-- π C.id_magazin
--    |
-- ⋈ A.ID_CONTRACT = C.NUMAR
--    |
-- σ A.NUME LIKE 'A%'
--    |
-- π A.ID_CONTRACT, A.NUME
--    |
-- ANGAJAT      CONTRACT      MAGAZIN


-- Crearea de indecși pe coloanele relevante
CREATE INDEX idx_angajat_nume ON ANGAJAT (NUME);
CREATE INDEX idx_contract_numar ON CONTRACT (NUMAR);
CREATE INDEX idx_contract_id_magazin ON CONTRACT (id_magazin);
CREATE INDEX idx_magazin_id_magazin ON MAGAZIN (ID_MAGAZIN);

SELECT A.NUME, M.NUME 
FROM 
  -- Subinterogare pentru a aplica filtrul pe numele angajaților cât mai jos în arborele de execuție
  (SELECT ID_CONTRACT, NUME 
   FROM ANGAJAT 
   WHERE NUME LIKE 'A%') A
JOIN 
  -- Subinterogare pentru tabelul CONTRACT pentru a limita coloanele returnate
  (SELECT NUMAR, id_magazin 
   FROM CONTRACT) C ON A.ID_CONTRACT = C.NUMAR
JOIN 
  -- Subinterogare pentru tabelul MAGAZIN pentru a limita coloanele returnate
  (SELECT ID_MAGAZIN, NUME 
   FROM MAGAZIN) M ON C.id_magazin = M.ID_MAGAZIN;







-- 17. 
-- BCNF
-- Toate tabelele sunt în forma normală Boyce-Codd deoarece fiecare atribut non-cheie depinde în mod funcțional doar de cheile candidat.

-- FN4
-- Verificarea FN4 necesită ca tabelele să nu aibă multivalori independente. Fiecare tabel trebuie să aibă atribute care nu se repetă în contexte diferite.

-- FN5
--  Tabelele nu au dependențe join redundante. FN5 necesită că fiecare dependență este specificată prin intermediul cheilor primare și cheilor externe. Toate relațiile în tabelele date respectă FN5.

