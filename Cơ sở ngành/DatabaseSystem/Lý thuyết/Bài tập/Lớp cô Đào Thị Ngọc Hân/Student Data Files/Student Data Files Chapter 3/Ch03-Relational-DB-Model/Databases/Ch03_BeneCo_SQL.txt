/* Database Systems, Coronel/Morris */
/* Type of SQL : SQL Server */



CREATE TABLE BENEFIT (
EMP_CODE int,
PLAN_CODE int
);
INSERT INTO BENEFIT VALUES('15','2');
INSERT INTO BENEFIT VALUES('15','3');
INSERT INTO BENEFIT VALUES('16','1');
INSERT INTO BENEFIT VALUES('17','1');
INSERT INTO BENEFIT VALUES('17','3');
INSERT INTO BENEFIT VALUES('17','4');
INSERT INTO BENEFIT VALUES('20','3');

/* -- */

CREATE TABLE EMPLOYEE (
EMP_CODE int,
EMP_LNAME varchar(12),
JOB_CODE int
);
INSERT INTO EMPLOYEE VALUES('14','Rudell','2');
INSERT INTO EMPLOYEE VALUES('15','McDade','1');
INSERT INTO EMPLOYEE VALUES('16','Ruellardo','1');
INSERT INTO EMPLOYEE VALUES('17','Smith','3');
INSERT INTO EMPLOYEE VALUES('20','Smith','2');

/* -- */


CREATE TABLE JOB (
JOB_CODE int,
JOB_DESCRIPTION varchar(20)
);
INSERT INTO JOB VALUES('1','Clerical');
INSERT INTO JOB VALUES('2','Technical');
INSERT INTO JOB VALUES('3','Managerial');


/* NOTE:                                 */
/* PLAN is a reserved word in SQL Server */
/* Therefore, please change all references */ 
/* of PLAN to PLANS in this script and text book */

CREATE TABLE PLANS (
PLAN_CODE int,
PLAN_DESCRIPTION varchar(20)
);
INSERT INTO PLANS VALUES('1','Term life');
INSERT INTO PLANS VALUES('2','Stock purchase');
INSERT INTO PLANS VALUES('3','Long-term disability');
INSERT INTO PLANS VALUES('4','Dental');

