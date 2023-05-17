-- Inserare înregistrări în tabele
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_angajat)
VALUES (1, '2022-01-01', 12, 'Contract de muncă', 1);

INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (1, 'Popescu', 'Ion', '1234567890123', 'Str. Libertății, Nr. 10', '0721000000', 'popescu.ion@example.com', 1);

-- Continuă cu inserarea de înregistrări în celelalte tabele folosind aceeași sintaxă.

-- Ștergere înregistrări din tabele
DELETE FROM CONTRACT WHERE NUMAR = 1;

DELETE FROM ANGAJAT WHERE ID_ANGAJAT = 1;

-- Inserare înregistrări în tabele
INSERT INTO CONTRACT (NUMAR, DATA_EMITERE, DURATA, TIP, id_angajat)
VALUES (1, '2022-01-01', 12, 'Contract de muncă', 1);

INSERT INTO ANGAJAT (ID_ANGAJAT, NUME, PRENUME, CNP, ADRESA, TELEFON, EMAIL, ID_CONTRACT)
VALUES (1, 'Popescu', 'Ion', '1234567890123', 'Str. Libertății, Nr. 10', '0721000000', 'popescu.ion@example.com', 1);

-- Continuă cu inserarea de înregistrări în celelalte tabele folosind aceeași sintaxă.

-- Ștergere înregistrări din tabele
DELETE FROM CONTRACT WHERE NUMAR = 1;

DELETE FROM ANGAJAT WHERE ID_ANGAJAT = 1;

-- Inserare înregistrări în tabele
INSERT INTO DIRECTOR (ID_DIRECTOR, ID_CONTRACT)
VALUES (1, 1);

INSERT INTO SECTIE (ID_SECTIE, NUME)
VALUES (1, 'Cardiologie');

INSERT INTO SECTOR (ID_SECTOR, TIP_NEVOIE, NUMAR_LOCURI)
VALUES (1, 'Urgențe', 10);

INSERT INTO SECTIE_SECTOR (ID_SECTIE, ID_SECTOR)
VALUES (1, 1);

INSERT INTO FARMACIE (ID_FARMACIE, NUME, TELEFON, PROGRAM)
VALUES (1, 'Farmacia XYZ', '0211111111', 'Luni-Vineri: 9:00-17:00');

INSERT INTO MEDICAMENT (NUMAR, DENUMIRE_PRODUS, CANTITATE, ID_FARMACIE)
VALUES (1, 'Paracetamol', 100, 1);

INSERT INTO VIZITATOR (CNP, NUME, PRENUME, TELEFON, EMAIL)
VALUES ('1234567890123', 'Ionescu', 'Maria', '0722000000', 'ionescu.maria@example.com');

-- Continuă cu inserarea de înregistrări în celelalte tabele folosind aceeași sintaxă.

-- Ștergere înregistrări din tabele
DELETE FROM DIRECTOR WHERE ID_DIRECTOR = 1;

DELETE FROM SECTIE WHERE ID_SECTIE = 1;

DELETE FROM SECTOR WHERE ID_SECTOR = 1;

DELETE FROM SECTIE_SECTOR WHERE ID_SECTIE = 1;

DELETE FROM FARMACIE WHERE ID_FARMACIE = 1;

DELETE FROM MEDICAMENT WHERE NUMAR = 1;

DELETE FROM VIZITATOR WHERE CNP = '1234567890123';
