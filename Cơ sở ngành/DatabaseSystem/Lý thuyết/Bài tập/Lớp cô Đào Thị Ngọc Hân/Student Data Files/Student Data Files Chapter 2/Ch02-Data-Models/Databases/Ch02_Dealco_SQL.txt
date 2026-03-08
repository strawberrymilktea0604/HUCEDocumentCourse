/* Database Systems, Coronel/Morris */
/* Type of SQL : SQL Server */


CREATE TABLE JOB (
JOB_CODE varchar(5),
JOB_DESCRIPTION varchar(25),
JOB_BASE_PAY numeric(4,2)
);
INSERT INTO JOB VALUES('GEN','General support','7.5');
INSERT INTO JOB VALUES('MGR','Manager','37.4');
INSERT INTO JOB VALUES('SEC','Secretary','18.95');

CREATE TABLE REGION (
REGION_CODE int,
REGION_DESCRIPT varchar(10)
);
INSERT INTO REGION VALUES('1','East');
INSERT INTO REGION VALUES('2','West');


CREATE TABLE STORE (
STORE_CODE int,
STORE_NAME varchar(20),
STORE_YTD_SALES numeric(10,2),
REGION_CODE int
);
INSERT INTO STORE VALUES('1','Access Junction','1003455.76','2');
INSERT INTO STORE VALUES('2','Database Corner','1421987.39','2');
INSERT INTO STORE VALUES('3','Tuple Charge','986783.22','1');
INSERT INTO STORE VALUES('4','Attribute Alley','944568.56','2');
INSERT INTO STORE VALUES('5','Primary Key Point','2930098.45','1');


CREATE TABLE EMPLOYEE (
EMP_CODE int,
EMP_TITLE varchar(4),
EMP_LNAME varchar(15),
EMP_FNAME varchar(15),
EMP_INITIAL varchar(1),
EMP_DOB datetime,
JOB_CODE varchar(5),
STORE_CODE int
);
INSERT INTO EMPLOYEE VALUES('1','Mr.','Williamson','John','W','5/21/1964','SEC','3');
INSERT INTO EMPLOYEE VALUES('2','Ms.','Ratula','Nancy','','2/9/1969','MGR','2');
INSERT INTO EMPLOYEE VALUES('3','Ms.','Greenboro','Lottie','R','10/2/1961','GEN','4');
INSERT INTO EMPLOYEE VALUES('4','Mrs.','Rumpersfro','Jennie','S','6/1/1971','GEN','5');
INSERT INTO EMPLOYEE VALUES('5','Mr.','Smith','Robert','L','11/23/1959','GEN','3');
INSERT INTO EMPLOYEE VALUES('6','Mr.','Renselaer','Cary','A','12/25/1965','GEN','1');
INSERT INTO EMPLOYEE VALUES('7','Mr.','Ogallo','Roberto','S','7/31/1962','MGR','3');
INSERT INTO EMPLOYEE VALUES('8','Ms.','Johnsson','Elizabeth','I','9/10/1968','SEC','1');
INSERT INTO EMPLOYEE VALUES('9','Mr.','Eindsmar','Jack','W','4/19/1955','SEC','2');
INSERT INTO EMPLOYEE VALUES('10','Mrs.','Jones','Rose','R','3/6/1966','GEN','4');
INSERT INTO EMPLOYEE VALUES('11','Mr.','Broderick','Tom','','10/21/1972','GEN','3');
INSERT INTO EMPLOYEE VALUES('12','Mr.','Washington','Alan','Y','9/8/1974','GEN','2');
INSERT INTO EMPLOYEE VALUES('13','Mr.','Smith','Peter','N','8/25/1964','GEN','3');
INSERT INTO EMPLOYEE VALUES('14','Ms.','Smith','Sherry','H','5/25/1966','GEN','4');
INSERT INTO EMPLOYEE VALUES('15','Mr.','Olenko','Howard','U','5/24/1964','GEN','5');
INSERT INTO EMPLOYEE VALUES('16','Mr.','Archialo','Barry','V','9/3/1960','GEN','5');
INSERT INTO EMPLOYEE VALUES('17','Ms.','Grimaldo','Jeanine','K','11/12/1970','MGR','4');
INSERT INTO EMPLOYEE VALUES('18','Mr.','Rosenberg','Andrew','D','1/24/1971','GEN','4');
INSERT INTO EMPLOYEE VALUES('19','Mr.','Rosten','Peter','F','10/3/1968','GEN','4');
INSERT INTO EMPLOYEE VALUES('20','Mr.','Mckee','Robert','S','3/6/1970','MGR','1');
INSERT INTO EMPLOYEE VALUES('21','Ms.','Baumann','Jennifer','A','12/11/1974','SEC','3');