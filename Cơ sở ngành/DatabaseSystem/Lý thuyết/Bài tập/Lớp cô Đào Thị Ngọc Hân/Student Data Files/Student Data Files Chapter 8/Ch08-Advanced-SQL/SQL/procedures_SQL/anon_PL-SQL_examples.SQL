--: Anonymous SQL Server blocks
--: For teaching purposes it will be better to copy and paste the script file code
--: from this script file to the SQL Query Analyzer


--: Insert a row in the VENDOR table
BEGIN
INSERT INTO VENDOR 
VALUES (25678,'Microsoft Corp.', 'Bill Gates','765','546-8484','WA','N')
END


--: Inserts a row in the vendor table with feedback message

BEGIN
INSERT INTO VENDOR 
VALUES (25772,'Clue Store','Issac Hayes','456','323-2009','VA','N')
PRINT 'New vendor added!'
END


--: SQL Server variables and WHILE LOOP example

DECLARE @W_P1 INTEGER 
DECLARE @W_P2 INTEGER 
DECLARE @W_NUM INTEGER
SET @W_P1 = 0
SET @W_P2 = 10
SET @W_NUM = 0
WHILE @W_P2 < 300 
BEGIN
   SET @W_NUM = (SELECT COUNT(P_CODE)FROM PRODUCT WHERE P_PRICE BETWEEN @W_P1 AND @W_P2)
   PRINT('There are ' + cast(@W_NUM as varchar(10)) + ' Products with price between ' + cast(@W_P1 as varchar(10)) + ' and ' + cast(@W_P2 as varchar(10)))
   SET @W_P1 = @W_P2 + 1
   SET @W_P2 = @W_P2 + 50  
END