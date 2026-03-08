-- Script Filename: UV-02.SQL
-- PURPOSE:
-- Creates the PSVUPD updatable view.
-- TO RUN:
-- At the SQL> prompt type: @D:\path\uv-02.sql
-- Where D: is the drive letter and path is the folder 
-- where the file resides.
-- Alternative you can copy and paste each command 
-- or the entire command sequence

DROP VIEW PSVUPD;

CREATE VIEW PSVUPD AS (
SELECT PRODMASTER.PROD_ID, PRODMASTER.PROD_QOH, PRODSALES.PS_QTY
FROM PRODMASTER, PRODSALES
WHERE PRODMASTER.PROD_ID = PRODSALES.PROD_ID);

SELECT * FROM PSVUPD;