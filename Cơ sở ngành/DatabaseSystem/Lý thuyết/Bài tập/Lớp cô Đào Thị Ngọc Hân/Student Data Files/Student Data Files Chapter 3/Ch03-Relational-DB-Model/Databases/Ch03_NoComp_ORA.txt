/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE EMPLOYEE (
EMP_NUM integer,
EMP_LNAME varchar2(20),
EMP_INITIAL varchar2(1),
EMP_FNAME varchar2(20),
DEPT_CODE varchar2(4),
JOB_CODE varchar2(2)
);
INSERT INTO EMPLOYEE VALUES('11234','Friedman','K','Robert','MKTG','12');
INSERT INTO EMPLOYEE VALUES('11238','Olanski','D','Delbert','MKTG','12');
INSERT INTO EMPLOYEE VALUES('11241','Fontein','','Juliette','INFS','5');
INSERT INTO EMPLOYEE VALUES('11242','Cruazona','J','Maria','ENG','9');
INSERT INTO EMPLOYEE VALUES('11245','Smithson','B','Bernard','INFS','6');
INSERT INTO EMPLOYEE VALUES('11248','Washington','G','Oleta','ENGR','8');
INSERT INTO EMPLOYEE VALUES('11256','McBride','','Randall','ENGR','8');
INSERT INTO EMPLOYEE VALUES('11257','Kachinn','D','Melanie','MKTG','14');
INSERT INTO EMPLOYEE VALUES('11258','Smith','W','William','MKTG','14');
INSERT INTO EMPLOYEE VALUES('11260','Ratula','A','Katrina','INFS','5');
