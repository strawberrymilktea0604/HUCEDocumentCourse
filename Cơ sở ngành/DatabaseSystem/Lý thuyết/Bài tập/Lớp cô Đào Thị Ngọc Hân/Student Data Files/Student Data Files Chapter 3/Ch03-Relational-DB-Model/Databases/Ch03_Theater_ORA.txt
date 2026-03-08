/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';


CREATE TABLE DIRECTOR (
DIR_NUM integer,
DIR_LNAME varchar2(50),
DIR_DOB date
);
INSERT INTO DIRECTOR VALUES('100','Broadway','1/12/1965');
INSERT INTO DIRECTOR VALUES('101','Hollywoody','11/18/1953');
INSERT INTO DIRECTOR VALUES('102','Goofy','6/21/1962');

/* -- */


CREATE TABLE PLAY (
PLAY_CODE integer,
PLAY_NAME varchar2(50),
DIR_NUM integer
);
INSERT INTO PLAY VALUES('1001','Cat On a Cold, Bare Roof','102');
INSERT INTO PLAY VALUES('1002','Hold the Mayo, Pass the Bread','101');
INSERT INTO PLAY VALUES('1003','I Never Promised You Coffee','102');
INSERT INTO PLAY VALUES('1004','Silly Putty Goes To Washington','100');
INSERT INTO PLAY VALUES('1005','See No Sound, Hear No Sight','101');
INSERT INTO PLAY VALUES('1006','Starstruck in Biloxi','102');
INSERT INTO PLAY VALUES('1007','Stranger In Parrot Ice','101');
