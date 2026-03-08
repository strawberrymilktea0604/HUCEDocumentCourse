/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE ASSIGNMENT (
ASSIGN_NUM int,
ASSIGN_DATE datetime,
PROJ_NUM varchar(3),
EMP_NUM varchar(3),
ASSIGN_HOURS float(8),
ASSIGN_CHG_HOUR numeric(5,2),
ASSIGN_CHARGE numeric(5,2)
);
INSERT INTO ASSIGNMENT VALUES('1001','2018-3-4','15','103','2.6','84.5','219.7');
INSERT INTO ASSIGNMENT VALUES('1002','2018-3-4','18','118','1.4','18.36','25.7');
INSERT INTO ASSIGNMENT VALUES('1003','2018-3-5','15','101','3.6','105','378');
INSERT INTO ASSIGNMENT VALUES('1004','2018-3-5','22','113','2.5','48.1','120.25');
INSERT INTO ASSIGNMENT VALUES('1005','2018-3-5','15','103','1.9','84.5','160.55');
INSERT INTO ASSIGNMENT VALUES('1006','2018-3-5','25','115','4.2','96.75','406.35');
INSERT INTO ASSIGNMENT VALUES('1007','2018-3-5','22','105','5.2','105','546');
INSERT INTO ASSIGNMENT VALUES('1008','2018-3-5','25','101','1.7','105','178.5');
INSERT INTO ASSIGNMENT VALUES('1009','2018-3-5','15','105','2','105','210');
INSERT INTO ASSIGNMENT VALUES('1010','2018-3-6','15','102','3.8','96.75','367.65');
INSERT INTO ASSIGNMENT VALUES('1011','2018-3-6','22','104','2.6','96.75','251.55');
INSERT INTO ASSIGNMENT VALUES('1012','2018-3-6','15','101','2.3','105','241.5');
INSERT INTO ASSIGNMENT VALUES('1013','2018-3-6','25','114','1.8','48.1','86.58');
INSERT INTO ASSIGNMENT VALUES('1014','2018-3-6','22','111','4','26.87','107.48');
INSERT INTO ASSIGNMENT VALUES('1015','2018-3-6','25','114','3.4','48.1','163.54');
INSERT INTO ASSIGNMENT VALUES('1016','2018-3-6','18','112','1.2','45.95','55.14');
INSERT INTO ASSIGNMENT VALUES('1017','2018-3-6','18','118','2','18.36','36.72');
INSERT INTO ASSIGNMENT VALUES('1018','2018-3-6','18','104','2.6','96.75','251.55');
INSERT INTO ASSIGNMENT VALUES('1019','2018-3-6','15','103','3','84.5','253.5');
INSERT INTO ASSIGNMENT VALUES('1020','2018-3-7','22','105','2.7','105','283.5');
INSERT INTO ASSIGNMENT VALUES('1021','2018-3-8','25','108','4.2','96.75','406.35');
INSERT INTO ASSIGNMENT VALUES('1022','2018-3-7','25','114','5.8','48.1','278.98');
INSERT INTO ASSIGNMENT VALUES('1023','2018-3-7','22','106','2.4','35.75','85.8');

/* -- */


CREATE TABLE DATA_ORG_1NF (
PROJ_NUM varchar(3),
PROJ_NAME varchar(25),
EMP_NUM varchar(3),
EMP_NAME varchar(25),
JOB_CLASS varchar(25),
CHG_HOUR numeric(5,2),
HOURS float(8)
);
INSERT INTO DATA_ORG_1NF VALUES('15','Evergreen','103','June E. Arbough','Elect. Engineer','84.5','23.8');
INSERT INTO DATA_ORG_1NF VALUES('15','Evergreen','101','John G. News','Database Designer','105','19.4');
INSERT INTO DATA_ORG_1NF VALUES('15','Evergreen','105','Alice K. Johnson *','Database Designer','105','35.7');
INSERT INTO DATA_ORG_1NF VALUES('15','Evergreen','106','William Smithfield','Programmer','35.75','12.6');
INSERT INTO DATA_ORG_1NF VALUES('15','Evergreen','102','David H. Senior','Systems Analyst','96.75','23.8');
INSERT INTO DATA_ORG_1NF VALUES('18','Amber Wave','114','Annelise Jones','Applications Designer','48.1','24.6');
INSERT INTO DATA_ORG_1NF VALUES('18','Amber Wave','118','James J. Frommer','General Support','18.36','45.3');
INSERT INTO DATA_ORG_1NF VALUES('18','Amber Wave','104','Anne K. Ramoras *','Systems Analyst','96.75','32.4');
INSERT INTO DATA_ORG_1NF VALUES('18','Amber Wave','112','Darlene M. Smithson','DSS Analyst','45.95','44');
INSERT INTO DATA_ORG_1NF VALUES('22','Rolling Tide','105','Alice K. Johnson','Database Designer','105','64.7');
INSERT INTO DATA_ORG_1NF VALUES('22','Rolling Tide','104','Anne K. Ramoras','Systems Analyst','96.75','48.4');
INSERT INTO DATA_ORG_1NF VALUES('22','Rolling Tide','113','Delbert K. Joenbrood *','Applications Designer','48.1','23.6');
INSERT INTO DATA_ORG_1NF VALUES('22','Rolling Tide','111','Geoff B. Wabash','Clerical Support','26.87','22');
INSERT INTO DATA_ORG_1NF VALUES('22','Rolling Tide','106','William Smithfield','Programmer','35.75','12.8');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','107','Maria D. Alonzo','Programmer','35.75','24.6');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','115','Travis B. Bawangi','Systems Analyst','96.75','45.8');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','101','John G. News *','Database Designer','105','56.3');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','114','Annelise Jones','Applications Designer','48.1','33.1');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','108','Ralph B. Washington','Systems Analyst','96.75','23.6');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','118','James J. Frommer','General Support','18.36','30.5');
INSERT INTO DATA_ORG_1NF VALUES('25','Starflight','112','Darlene M. Smithson','DSS Analyst','45.95','41.4');

/* -- */

CREATE TABLE EMPLOYEE (
EMP_NUM varchar(3),
EMP_LNAME varchar(15),
EMP_FNAME varchar(15),
EMP_INITIAL varchar(1),
EMP_HIREDATE datetime,
JOB_CODE varchar(3)
);
INSERT INTO EMPLOYEE VALUES('101','News','John','G','2000-11-8','502');
INSERT INTO EMPLOYEE VALUES('102','Senior','David','H','1989-7-12','501');
INSERT INTO EMPLOYEE VALUES('103','Arbough','June','E','1997-12-1','503');
INSERT INTO EMPLOYEE VALUES('104','Ramoras','Anne','K','1988-11-15','501');
INSERT INTO EMPLOYEE VALUES('105','Johnson','Alice','K','1994-2-1','502');
INSERT INTO EMPLOYEE VALUES('106','Smithfield','William','','2005-6-22','500');
INSERT INTO EMPLOYEE VALUES('107','Alonzo','Maria','D','1994-10-10','500');
INSERT INTO EMPLOYEE VALUES('108','Washington','Ralph','B','1989-8-22','501');
INSERT INTO EMPLOYEE VALUES('109','Smith','Larry','W','1999-7-18','501');
INSERT INTO EMPLOYEE VALUES('110','Olenko','Gerald','A','1996-12-11','505');
INSERT INTO EMPLOYEE VALUES('111','Wabash','Geoff','B','1989-4-4','506');
INSERT INTO EMPLOYEE VALUES('112','Smithson','Darlene','M','1995-10-23','507');
INSERT INTO EMPLOYEE VALUES('113','Joenbrood','Delbert','K','1994-11-15','508');
INSERT INTO EMPLOYEE VALUES('114','Jones','Annelise','','1991-8-20','508');
INSERT INTO EMPLOYEE VALUES('115','Bawangi','Travis','B','1990-1-25','501');
INSERT INTO EMPLOYEE VALUES('116','Pratt','Gerald','L','1995-3-5','510');
INSERT INTO EMPLOYEE VALUES('117','Williamson','Angie','H','1994-6-19','509');
INSERT INTO EMPLOYEE VALUES('118','Frommer','James','J','2006-1-4','510');


/* -- */

CREATE TABLE JOB (
JOB_CODE varchar(3),
JOB_DESCRIPTION varchar(25),
JOB_CHG_HOUR numeric(5,2)
);
INSERT INTO JOB VALUES('500','Programmer','35.75');
INSERT INTO JOB VALUES('501','Systems Analyst','96.75');
INSERT INTO JOB VALUES('502','Database Designer','105');
INSERT INTO JOB VALUES('503','Electrical Engineer','84.5');
INSERT INTO JOB VALUES('504','Mechanical Engineer','67.9');
INSERT INTO JOB VALUES('505','Civil Engineer','55.78');
INSERT INTO JOB VALUES('506','Clerical Support','26.87');
INSERT INTO JOB VALUES('507','DSS Analyst','45.95');
INSERT INTO JOB VALUES('508','Applications Designer','48.1');
INSERT INTO JOB VALUES('509','Bio Technician','34.55');
INSERT INTO JOB VALUES('510','General Support','18.36');

/* -- */


CREATE TABLE PROJECT (
PROJ_NUM varchar(3),
PROJ_NAME varchar(25),
EMP_NUM varchar(3)
);
INSERT INTO PROJECT VALUES('15','Evergreen','105');
INSERT INTO PROJECT VALUES('18','Amber Wave','104');
INSERT INTO PROJECT VALUES('22','Rolling Tide','113');
INSERT INTO PROJECT VALUES('25','Starflight','101');

/* -- */


