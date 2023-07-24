
-- Tabela CONTRACT
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_magazin, id_farmacie, id_clinica)
VALUES (1, TO_DATE('2023-01-01', 'YYYY-MM-DD'), 12, 'Standard', 1, 1, 1),
VALUES (2, TO_DATE('2023-02-01', 'YYYY-MM-DD'), 6, 'Premium', 2, 2, 2),
VALUES (3, TO_DATE('2023-01-01', 'YYYY-MM-DD'), 3, 'Standard', 3, 3, 3),
VALUES (4, TO_DATE('2023-01-01', 'YYYY-MM-DD'), 10, 'Premium', 4, 4, 4),
VALUES (5, TO_DATE('2023-01-01', 'YYYY-MM-DD'), 12, 'Standard', 5, 5, 5);

-- Tabela ANGAJAT
INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (1, 'Popescu', 'Ion', '1234567890123', 'Str. Muncii, Nr. 1', '123456789', 'popescu.ion@example.com', 1),
       (2, 'Ionescu', 'Maria', '9876543210987', 'Str. Victoriei, Nr. 2', '987654321', 'ionescu.maria@example.com', 2),
       (3, 'Dumitrescu', 'Ana', '4567890123456', 'Str. Libert??ii, Nr. 3', '456789012', 'dumitrescu.ana@example.com', 3),
       (4, 'Constantinescu', 'Mihai', '7890123456789', 'Str. Independen?ei, Nr. 4', '789012345', 'constantinescu.mihai@example.com', 4),
       (5, 'Georgescu', 'Elena', '2345678901234', 'Str. Revolu?iei, Nr. 5', '234567890', 'georgescu.elena@example.com', 5);


-- Tabela DIRECTOR
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT, ID_ANGAJAT)
VALUES (1, 1, 1),
VALUES (2, 2, 2),
VALUES (3, 3, 3),
VALUES (4, 4, 4),
VALUES (5, 5, 5);


-- Tabela SECTOR --
INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (1, 'Tip 1', 10),
VALUES (2, 'Tip 2', 5),
VALUES (3, 'Tip 3', 8),
VALUES (4, 'Tip 4', 11),
VALUES (5, 'Tip 5', 15);


-- Tabela SECTIE_SECTOR --
INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (1, 1),
VALUES (2, 2),
VALUES (3, 3),
VALUES (4, 4),
VALUES (5, 5);

-- Tabela SECTIE --
INSERT INTO SECTIE (ID_SECTIE, NUME, ID_CUSCA)
VALUES (1, 'Sectie 1', 1),
VALUES (2, 'Sectie 2', 2),
VALUES (3, 'Sectie 3', 3),
VALUES (4, 'Sectie 4', 4),
VALUES (5, 'Sectie 5', 5);

-- Tabela FARMACIE --

INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (1, 'Pharmacy 1', '123-456-7890', '9 AM - 6 PM', 1);

INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (2, 'Pharmacy 2', '123-456-7899', '9 AM - 6 PM', 1);

INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM, NUMAR)
VALUES (3, 'Pharmacy 3', '123-456-3451', '9 AM - 10 PM', 1),
VALUES (4, 'Pharmacy 4', '123-456-2469', '7 AM - 3 PM', 1),
VALUES (5, 'Pharmacy 5', '123-456-9452', '9 AM - 6 PM', 1);


-- Tabela MEDICAMENT  -- 
INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE)
VALUES (1, 'Medicament 1', 50),
VALUES (2, 'Medicament 2', 100),
VALUES (3, 'Medicament 3', 20),
VALUES (4, 'Medicament 4', 80),
VALUES (5, 'Medicament 5', 150);

-- Tabela VIZITATOR -- 

INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1234567890123', 'Jane', 'Doe', '987-654-3210', 'jane@example.com');

INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1234678390124', 'Jany', 'Denice', '947-967-3215', 'jany@gmail.com'),
VALUES ('5434564573465', 'Dan', 'Brice', '987-654-4662', 'brice@gmail.com'),
VALUES ('1234903767384', 'Jacob', 'Marian', '246-654-3215', 'marian@gmail.com'),
VALUES ('6542952096781', 'Ghica', 'Suditu', '375-654-0697', 'suditu@gmail.com');

--Tabela CUSCA --

INSERT INTO CUSCA (ID_CUSCA, NUMAR_LOCURI)
VALUES (1, 5),
VALUES (2, 1),
VALUES (3, 4),
VALUES (4, 10),
VALUES (5, 2);


-- Tabela CERERE_ADOPTIE --

INSERT INTO CERERE_ADOPTIE (SERIE, ID_ANIMAL, ID_VIZITATOR, DATA)
VALUES ('ABC123', 1, '1', TO_DATE('2023-01-01', 'YYYY-MM-DD')),
VALUES ('C354', 2, '2', TO_DATE('2023-01-01', 'YYYY-MM-DD')),
VALUES ('Z782', 3, '3', TO_DATE('2023-01-01', 'YYYY-MM-DD')),
VALUES ('A32', 4, '4', TO_DATE('2023-01-01', 'YYYY-MM-DD')),
VALUES ('Q70', 5, '5', TO_DATE('2023-01-01', 'YYYY-MM-DD'));

-- Tabela ANIMAL 

INSERT INTO ANIMAL (ID_ANIMAL, NUME, RASA, VARSTA, SEX, DATA_SOSIRE, ID_CUSCA, ID_VETERINAR)
VALUES (1, 'Caine', 'bulldog', 3, 'Male', TO_DATE('2023-01-01', 'YYYY-MM-DD'), 1, 1),
VALUES (2, 'Caine', 'pechinez', 13, 'Male', TO_DATE('2023-01-01', 'YYYY-MM-DD'), 2, 2),
VALUES (3, 'Caine', 'shit-zu', 4, 'Male', TO_DATE('2023-01-01', 'YYYY-MM-DD'), 3, 3),
VALUES (4, 'Caine', 'bichon', 9, 'Female', TO_DATE('2023-01-01', 'YYYY-MM-DD'), 4, 4),
VALUES (5, 'Caine', 'labrador', 1, 'Female', TO_DATE('2023-01-01', 'YYYY-MM-DD'), 5, 5);
