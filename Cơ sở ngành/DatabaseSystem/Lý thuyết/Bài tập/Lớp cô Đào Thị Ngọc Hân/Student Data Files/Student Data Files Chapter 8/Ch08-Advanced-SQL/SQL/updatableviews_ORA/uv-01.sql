-- Script Filename: UV-01.SQL
-- PURPOSE:
-- Creates and populates the tables (PRODMASTER and PRODSALES) 
-- used to demostrate the use of updable views.
-- TO RUN:
-- At the SQL> prompt type: @D:\path\uv-01.sql
-- Where D: is the drive letter and path is the folder 
-- where the file resides.
-- Alternative you can copy and paste each command 
-- or the entire command sequence


DROP TABLE PRODMASTER;
DROP TABLE PRODSALES;

CREATE TABLE PRODMASTER (
PROD_ID   VARCHAR(4) PRIMARY KEY,
PROD_DESC VARCHAR(20),
PROD_QOH  NUMBER(5,2));

CREATE TABLE PRODSALES (
PROD_ID VARCHAR(4) PRIMARY KEY,
PS_QTY  NUMBER(5,2));

INSERT INTO PRODMASTER VALUES ('A123', 'SCREWS', 67);
INSERT INTO PRODMASTER VALUES ('BX34', 'NUTS'  , 37);
INSERT INTO PRODMASTER VALUES ('C583', 'BOLTS' , 50);

INSERT INTO PRODSALES VALUES ('A123', 7);
INSERT INTO PRODSALES VALUES ('BX34', 3);

SELECT * FROM PRODMASTER;

SELECT * FROM PRODSALES;
