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
    ID_DIRECTOR INT PRIMARY KEY,
    ID_CONTRACT INT,
    ID_ANGAJAT INT,
    FOREIGN KEY (ID_CONTRACT) REFERENCES CONTRACT (NUMAR),
    FOREIGN KEY (ID_ANGAJAT) REFERENCES ANGAJAT (ID_ANGAJAT)
);

CREATE TABLE SECTOR (
    ID_SECTOR INT PRIMARY KEY,
    TIP_NEVOIE VARCHAR(255),
    NUMAR_LOCURI INT
);

CREATE TABLE SECTIE_SECTOR (
    ID_SECTIE INT,
    ID_SECTOR INT,
    PRIMARY KEY (ID_SECTIE, ID_SECTOR),
    FOREIGN KEY (ID_SECTIE) REFERENCES SECTIE (ID_SECTIE),
    FOREIGN KEY (ID_SECTOR) REFERENCES SECTOR (ID_SECTOR)
);

CREATE TABLE SECTIE (
    ID_SECTIE INT PRIMARY KEY,
    NUME VARCHAR(255),
    ID_CUSCA INT,
    FOREIGN KEY (ID_CUSCA) REFERENCES CUSCA (ID_CUSCA)
);

CREATE TABLE FARMACIE (
    ID_FARMACIE INT PRIMARY KEY,
    NUME VARCHAR(255),
    TELEFON VARCHAR(255),
    PROGRAM VARCHAR(255),
    NUMAR INT,
    FOREIGN KEY (NUMAR) REFERENCES MEDICAMENT (NUMAR)
);

CREATE TABLE MEDICAMENT (
    NUMAR INT PRIMARY KEY,
    DENUMIRE_PRODUS VARCHAR(255),
    CANTITATE INT
);

CREATE TABLE VIZITATOR (
    CNP VARCHAR(13) PRIMARY KEY,
    NUME VARCHAR(255),
    PRENUME VARCHAR(255),
    TELEFON VARCHAR(255),
    EMAIL VARCHAR(255)
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

CREATE TABLE CUSCA (
    ID_CUSCA INT PRIMARY KEY,
    NUMAR_LOCURI INT
);


CREATE TABLE VETERINAR (
    CNP VARCHAR(13) PRIMARY KEY,
    NUME VARCHAR(255),
    PRENUME VARCHAR(255),
    ID_ANIMAL INT,
    ID_CONSULTATIE,
    FOREIGN KEY (ID_ANIMAL) REFERENCES ANIMAL (ID_ANIMAL),
    FOREIGN KEY (ID_CONSLTATIE) REFERENCES CONSULTATIE (ID_CONSULTATIE)
);


CREATE TABLE MAGAZIN (
    ID_MAGAZIN INT PRIMARY KEY,
    ID_CONTRACT INT,
    NUME VARCHAR(255),
    TELEFON VARCHAR(255),
    PROGRAM VARCHAR(255),
    FOREIGN KEY (ID_MAGAZIN) REFERENCES MAGAZIN (ID_MAGAZIN)
);

CREATE TABLE HRANA (
    NUMAR INT PRIMARY KEY,
    DENUMIRE_PRODUS VARCHAR(255),
    CANTITATE INT,
    ID_MAGAZIN INT,
    FOREIGN KEY (ID_MAGAZIN) REFERENCES MAGAZIN (ID_MAGAZIN)
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


CREATE TABLE CLINICA_VETERINARA (
    ID_CLINICA INT PRIMARY KEY,
    DENUMIRE VARCHAR(255),
    ADRESA VARCHAR(255),
    TELEFON VARCHAR(255),
    EMAIL VARCHAR(255),
    ID_VETERINAR VARCHAR(13),
    FOREIGN KEY (ID_VETERINAR) REFERENCES VETERINAR (CNP)
);
