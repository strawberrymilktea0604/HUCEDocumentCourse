CREATE OR REPLACE TRIGGER TRG_LINE_CUS
AFTER INSERT ON LINE 
FOR EACH ROW
DECLARE 
W_CUS CHAR(5);
W_TOT NUMBER:= 0;    -- to compute total cost
BEGIN
   -- this trigger fires up after an INSERT of a LINE
   -- it will update the CUS_BALANCE in CUSTOMER   

   -- 1) get the CUS_CODE
   SELECT CUS_CODE INTO W_CUS 
     FROM INVOICE
      WHERE INVOICE.INV_NUMBER = :NEW.INV_NUMBER;
       
   -- 2) compute the total of the current line
   W_TOT := :NEW.LINE_PRICE * :NEW.LINE_UNITS;
    
   -- 3) Update the CUS_BALANCE in CUSTOMER
   UPDATE CUSTOMER
    SET CUS_BALANCE = CUS_BALANCE + W_TOT
     WHERE CUS_CODE = W_CUS;

   DBMS_OUTPUT.PUT_LINE(' * * * Balance updated for customer: ' || W_CUS);  

END;

