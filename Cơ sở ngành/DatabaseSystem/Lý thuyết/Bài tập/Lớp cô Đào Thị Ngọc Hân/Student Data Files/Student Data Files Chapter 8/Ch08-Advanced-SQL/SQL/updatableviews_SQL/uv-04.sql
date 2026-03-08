-- Script Filename: UV-04.SQL
-- PURPOSE:
-- Updates the PROD_QOH column using the PSVUPD view
-- TO RUN:
-- copy and paste each command 
-- or the entire command sequence


UPDATE PSVUPD
SET PROD_QOH = PROD_QOH - PS_QTY;

SELECT * FROM PRODMASTER;