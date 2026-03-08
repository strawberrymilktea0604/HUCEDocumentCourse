-- Script Filename: UV-04.SQL
-- PURPOSE:
-- Updates the PROD_QOH column using the PSVUPD view
-- TO RUN:
-- At the SQL> prompt type: @D:\path\uv-04.sql
-- Where D: is the drive letter and path is the folder 
-- where the file resides.
-- Alternative you can copy and paste each command 
-- or the entire command sequence


CLEAR SCREEN;

UPDATE PSVUPD
SET PROD_QOH = PROD_QOH - PS_QTY;

SELECT * FROM PRODMASTER;