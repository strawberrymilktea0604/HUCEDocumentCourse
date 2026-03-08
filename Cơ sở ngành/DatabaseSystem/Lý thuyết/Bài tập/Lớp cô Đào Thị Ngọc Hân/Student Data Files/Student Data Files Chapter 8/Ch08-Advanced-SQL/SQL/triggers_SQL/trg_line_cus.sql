IF EXISTS (SELECT name FROM sysobjects
      WHERE name = 'TRG_LINE_CUS' AND type = 'TR')
   DROP TRIGGER TRG_LINE_CUS
GO
CREATE TRIGGER TRG_LINE_CUS
ON LINE 
FOR INSERT
AS
DECLARE 
@W_CUS CHAR(5),
@W_TOT NUMERIC
SET @W_TOT = 0    -- to compute total cost
   -- this trigger fires up after an INSERT of a LINE
   -- it will update the CUS_BALANCE in CUSTOMER   

   -- 1) get the CUS_CODE
   SET @W_CUS = (SELECT INVOICE.CUS_CODE FROM INVOICE, INSERTED WHERE INVOICE.INV_NUMBER = INSERTED.INV_NUMBER)

   -- 2) compute the total of the current line
   SET @W_TOT = (SELECT INSERTED.LINE_PRICE*INSERTED.LINE_UNITS FROM INSERTED)
    
   -- 3) Update the CUS_BALANCE in CUSTOMER
   UPDATE CUSTOMER
    SET CUS_BALANCE = CUS_BALANCE + @W_TOT
     WHERE CUS_CODE = @W_CUS;

   PRINT(' * * * Balance updated for customer: ' + @W_CUS);  
