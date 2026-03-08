IF EXISTS (SELECT name FROM sysobjects 
   WHERE name = 'PRC_PROD_DISCOUNT' AND type = 'P')
   DROP PROCEDURE PRC_PROD_DISCOUNT
GO
CREATE PROCEDURE PRC_PROD_DISCOUNT
@WPI NUMERIC(3,2)
AS
BEGIN
   IF (@WPI <= 0) OR (@WPI >= 1) -- validate WPI parameter 
   BEGIN
      PRINT('Error: Value must be greater than 0 and less than 1')
   END
   ELSE 
   -- if value is greater than 0 and less than 1
   UPDATE PRODUCT
   SET P_DISCOUNT = P_DISCOUNT + @WPI
   WHERE P_QOH >= P_MIN*2;
   PRINT ('* * Update finished * *')
END
