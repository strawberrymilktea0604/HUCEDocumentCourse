/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE DIRECTOR (
DIR_NUM int,
DIR_LNAME varchar(50),
DIR_DOB datetime
);
INSERT INTO DIRECTOR VALUES('100','Broadway','1965-1-12');
INSERT INTO DIRECTOR VALUES('101','Hollywoody','1953-11-18');
INSERT INTO DIRECTOR VALUES('102','Goofy','1962-6-21');

/* -- */

CREATE TABLE PLAY (
PLAY_CODE int,
PLAY_NAME varchar(50),
DIR_NUM int
);
INSERT INTO PLAY VALUES('1001','Cat On a Cold, Bare Roof','102');
INSERT INTO PLAY VALUES('1002','Hold the Mayo, Pass the Bread','101');
INSERT INTO PLAY VALUES('1003','I Never Promised You Coffee','102');
INSERT INTO PLAY VALUES('1004','Silly Putty Goes To Washington','100');
INSERT INTO PLAY VALUES('1005','See No Sound, Hear No Sight','101');
INSERT INTO PLAY VALUES('1006','Starstruck in Biloxi','102');
INSERT INTO PLAY VALUES('1007','Stranger In Parrot Ice','101');
