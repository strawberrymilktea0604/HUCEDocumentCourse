: Anonymous PL/SQL blocks
: For teaching purposes it will be better to copy and paste the script file code
: from this script file to the SQL> prompt.


: Insert a row in the VENDOR table
BEGIN
INSERT INTO VENDOR 
VALUES (25678,'Microsoft Corp.', 'Bill Gates','765','546-8484','WA','N');
END;
/

: Inserts a row in the vendor table with feedback message

SET SERVEROUTPUT ON

BEGIN
INSERT INTO VENDOR 
VALUES (25772,'Clue Store','Issac Hayes','456','323-2009','VA','N');
DBMS_OUTPUT.PUT_LINE('New Vendor Added!');
END;
/

: PL/SQL variables and WHILE LOOP example

DECLARE
W_P1  NUMBER(3) := 0;
W_P2  NUMBER(3) := 10;
W_NUM NUMBER(2) := 0;
BEGIN
WHILE W_P2 < 300 LOOP
   SELECT COUNT(P_CODE) INTO W_NUM FROM PRODUCT 
   WHERE P_PRICE BETWEEN W_P1 AND W_P2;
   DBMS_OUTPUT.PUT_LINE('There are ' || W_NUM || ' Products with price between ' || W_P1 || ' and ' || W_P2);
   W_P1 := W_P2 + 1;
   W_P2 := W_P2 + 50;
END LOOP;
END;
/



