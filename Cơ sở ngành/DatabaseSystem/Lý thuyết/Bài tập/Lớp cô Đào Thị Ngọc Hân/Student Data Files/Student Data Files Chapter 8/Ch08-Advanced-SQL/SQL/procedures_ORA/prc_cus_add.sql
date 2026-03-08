CREATE OR REPLACE PROCEDURE PRC_CUS_ADD
(W_LN IN VARCHAR, W_FN IN VARCHAR, W_INIT IN VARCHAR, W_AC IN VARCHAR, W_PH IN VARCHAR)
AS 
BEGIN
-- note that the procedure uses the CUS_CODE_SEQ sequence created earlier
-- attribute names are required when not giving values for all table attributes
   INSERT INTO CUSTOMER(CUS_CODE,CUS_LNAME, CUS_FNAME, CUS_INITIAL, CUS_AREACODE, CUS_PHONE)
          VALUES (CUS_CODE_SEQ.NEXTVAL, W_LN, W_FN, W_INIT, W_AC, W_PH);  
   DBMS_OUTPUT.PUT_LINE ('Customer ' || W_LN || ', ' || W_FN || ' added.');
END;
/