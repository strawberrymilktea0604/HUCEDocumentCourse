/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE EMPLOYEE (
EMP_CODE int,
EMP_TITLE varchar(4),
EMP_LNAME varchar(15),
EMP_FNAME varchar(15),
EMP_INITIAL varchar(1),
EMP_DOB datetime,
STORE_CODE int
);
INSERT INTO EMPLOYEE VALUES('1','Mr.','Williamson','John','W','1984-5-21','3');
INSERT INTO EMPLOYEE VALUES('2','Ms.','Ratula','Nancy','','1989-2-9','2');
INSERT INTO EMPLOYEE VALUES('3','Ms.','Greenboro','Lottie','R','1981-10-2','4');
INSERT INTO EMPLOYEE VALUES('4','Mrs.','Rumpersfro','Jennie','S','1991-6-1','5');
INSERT INTO EMPLOYEE VALUES('5','Mr.','Smith','Robert','L','1979-11-23','3');
INSERT INTO EMPLOYEE VALUES('6','Mr.','Renselaer','Cary','A','1985-12-25','1');
INSERT INTO EMPLOYEE VALUES('7','Mr.','Ogallo','Roberto','S','1982-7-31','3');
INSERT INTO EMPLOYEE VALUES('8','Ms.','Johnsson','Elizabeth','I','1988-9-10','1');
INSERT INTO EMPLOYEE VALUES('9','Mr.','Eindsmar','Jack','W','1975-4-19','2');
INSERT INTO EMPLOYEE VALUES('10','Mrs.','Jones','Rose','R','1986-3-6','4');
INSERT INTO EMPLOYEE VALUES('11','Mr.','Broderick','Tom','','1992-10-21','3');
INSERT INTO EMPLOYEE VALUES('12','Mr.','Washington','Alan','Y','1994-9-8','2');
INSERT INTO EMPLOYEE VALUES('13','Mr.','Smith','Peter','N','1984-8-25','3');
INSERT INTO EMPLOYEE VALUES('14','Ms.','Smith','Sherry','H','1986-5-25','4');
INSERT INTO EMPLOYEE VALUES('15','Mr.','Olenko','Howard','U','1984-5-24','5');
INSERT INTO EMPLOYEE VALUES('16','Mr.','Archialo','Barry','V','1980-9-3','5');
INSERT INTO EMPLOYEE VALUES('17','Ms.','Grimaldo','Jeanine','K','1990-11-12','4');
INSERT INTO EMPLOYEE VALUES('18','Mr.','Rosenberg','Andrew','D','1991-1-24','4');
INSERT INTO EMPLOYEE VALUES('19','Mr.','Rosten','Peter','F','1988-10-3','4');
INSERT INTO EMPLOYEE VALUES('20','Mr.','Mckee','Robert','S','1990-3-6','1');
INSERT INTO EMPLOYEE VALUES('21','Ms.','Baumann','Jennifer','A','1994-12-11','3');

/* -- */

CREATE TABLE REGION (
REGION_CODE int,
REGION_DESCRIPT varchar(10)
);
INSERT INTO REGION VALUES('1','East');
INSERT INTO REGION VALUES('2','West');

/* -- */

CREATE TABLE STORE (
STORE_CODE int,
STORE_NAME varchar(20),
STORE_YTD_SALES numeric,
REGION_CODE int,
EMP_CODE int
);
INSERT INTO STORE VALUES('1','Access Junction','1003455.76','2','8');
INSERT INTO STORE VALUES('2','Database Corner','1421987.39','2','12');
INSERT INTO STORE VALUES('3','Tuple Charge','986783.22','1','7');
INSERT INTO STORE VALUES('4','Attribute Alley','944568.56','2','3');
INSERT INTO STORE VALUES('5','Primary Key Point','2930098.45','1','15');