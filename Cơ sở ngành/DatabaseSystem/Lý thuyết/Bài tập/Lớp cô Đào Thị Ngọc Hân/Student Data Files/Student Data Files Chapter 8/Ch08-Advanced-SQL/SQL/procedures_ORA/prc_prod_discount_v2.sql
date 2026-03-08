CREATE OR REPLACE PROCEDURE PRC_PROD_DISCOUNT(WPI IN NUMBER) AS
BEGIN
   IF ((WPI <= 0) OR (WPI >= 1)) THEN	-- validate WPI parameter 
      	DBMS_OUTPUT.PUT_LINE('Error: Value must be greater than 0 and less than 1');
   ELSE   				-- if value is greater than 0 and less than 1
	UPDATE PRODUCT
	 SET P_DISCOUNT = P_DISCOUNT + WPI
	     WHERE P_QOH >= P_MIN*2;
	DBMS_OUTPUT.PUT_LINE ('* * Update finished * *');
   END IF;
END;


