/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE PAINTER (
PAINTER_NUM integer,
PAINTER_LNAME varchar2(15),
PAINTER_FNAME varchar2(15),
PAINTER_INITIAL varchar2(1)
);
INSERT INTO PAINTER VALUES('123','Ross','Georgette','P');
INSERT INTO PAINTER VALUES('126','Itero','Julio','G');

/* -- */

CREATE TABLE PAINTING (
PAINTING_NUM integer,
PAINTING_TITLE varchar2(50),
PAINTER_NUM integer
);
INSERT INTO PAINTING VALUES('1338','Dawn Thunder','123');
INSERT INTO PAINTING VALUES('1339','Vanilla Roses To Nowhere','123');
INSERT INTO PAINTING VALUES('1340','Tired Flounders','126');
INSERT INTO PAINTING VALUES('1341','Hasty Exit','123');
INSERT INTO PAINTING VALUES('1342','Plastic Paradise','126');
