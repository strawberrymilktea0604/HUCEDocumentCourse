/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE JOB (
JOB_CODE varchar(5),
JOB_DESCRIPTION varchar(25),
JOB_BASE_PAY numeric(4,2)
)
ENGINE = InnoDB;
INSERT INTO JOB VALUES('GEN','General support','7.5');
INSERT INTO JOB VALUES('MGR','Manager','37.4');
INSERT INTO JOB VALUES('SEC','Secretary','18.95');


CREATE TABLE REGION (
REGION_CODE int,
REGION_DESCRIPT varchar(10)
)
ENGINE = InnoDB;
INSERT INTO REGION VALUES('1','East');
INSERT INTO REGION VALUES('2','West');


CREATE TABLE STORE (
STORE_CODE int,
STORE_NAME varchar(20),
STORE_YTD_SALES numeric(10,2),
REGION_CODE int
)
ENGINE = InnoDB;
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
)
ENGINE = InnoDB;

INSERT INTO EMPLOYEE VALUES('1','Mr.','Williamson','John','W','1964-5-21','SEC','3');
INSERT INTO EMPLOYEE VALUES('2','Ms.','Ratula','Nancy','','1969-2-9','MGR','2');
INSERT INTO EMPLOYEE VALUES('3','Ms.','Greenboro','Lottie','R','1961-10-2','GEN','4');
INSERT INTO EMPLOYEE VALUES('4','Mrs.','Rumpersfro','Jennie','S','1971-6-1','GEN','5');
INSERT INTO EMPLOYEE VALUES('5','Mr.','Smith','Robert','L','1959-11-23','GEN','3');
INSERT INTO EMPLOYEE VALUES('6','Mr.','Renselaer','Cary','A','1965-12-25','GEN','1');
INSERT INTO EMPLOYEE VALUES('7','Mr.','Ogallo','Roberto','S','1962-7-31','MGR','3');
INSERT INTO EMPLOYEE VALUES('8','Ms.','Johnsson','Elizabeth','I','1968-9-10','SEC','1');
INSERT INTO EMPLOYEE VALUES('9','Mr.','Eindsmar','Jack','W','1955-4-19','SEC','2');
INSERT INTO EMPLOYEE VALUES('10','Mrs.','Jones','Rose','R','1966-3-6','GEN','4');
INSERT INTO EMPLOYEE VALUES('11','Mr.','Broderick','Tom','','1972-10-21','GEN','3');
INSERT INTO EMPLOYEE VALUES('12','Mr.','Washington','Alan','Y','1974-9-8','GEN','2');
INSERT INTO EMPLOYEE VALUES('13','Mr.','Smith','Peter','N','1964-8-25','GEN','3');
INSERT INTO EMPLOYEE VALUES('14','Ms.','Smith','Sherry','H','1966-5-25','GEN','4');
INSERT INTO EMPLOYEE VALUES('15','Mr.','Olenko','Howard','U','1964-5-24','GEN','5');
INSERT INTO EMPLOYEE VALUES('16','Mr.','Archialo','Barry','V','1960-9-3','GEN','5');
INSERT INTO EMPLOYEE VALUES('17','Ms.','Grimaldo','Jeanine','K','1970-11-12','MGR','4');
INSERT INTO EMPLOYEE VALUES('18','Mr.','Rosenberg','Andrew','D','1971-1-24','GEN','4');
INSERT INTO EMPLOYEE VALUES('19','Mr.','Rosten','Peter','F','1968-10-3','GEN','4');
INSERT INTO EMPLOYEE VALUES('20','Mr.','Mckee','Robert','S','1970-3-6','MGR','1');
INSERT INTO EMPLOYEE VALUES('21','Ms.','Baumann','Jennifer','A','1974-12-11','SEC','3');
