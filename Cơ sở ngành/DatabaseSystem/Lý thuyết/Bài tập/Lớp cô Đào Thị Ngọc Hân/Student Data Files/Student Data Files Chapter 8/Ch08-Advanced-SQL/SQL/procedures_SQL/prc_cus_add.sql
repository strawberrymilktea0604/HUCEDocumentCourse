IF EXISTS (SELECT name FROM sysobjects 
   WHERE name = 'PRC_CUS_ADD' AND type = 'P')
   DROP PROCEDURE PRC_CUS_ADD
GO
CREATE PROCEDURE PRC_CUS_ADD
@W_CODE INTEGER,
@W_LN VARCHAR(15),
@W_FN VARCHAR(15),
@W_INIT CHAR(1),
@W_AC CHAR(3),
@W_PH CHAR(8)
AS
BEGIN
-- attribute names are required when not giving values for all table attributes
   INSERT INTO CUSTOMER(CUS_CODE,CUS_LNAME, CUS_FNAME, CUS_INITIAL, CUS_AREACODE, CUS_PHONE)
          VALUES (@W_CODE, @W_LN, @W_FN, @W_INIT, @W_AC, @W_PH);  
   PRINT ('Customer ' + @W_LN + ', ' + @W_FN + ' added.');
END;
