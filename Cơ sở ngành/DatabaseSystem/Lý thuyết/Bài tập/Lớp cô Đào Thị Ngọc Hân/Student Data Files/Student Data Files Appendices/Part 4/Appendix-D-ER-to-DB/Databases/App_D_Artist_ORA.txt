/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE GALLERY (
GAL_NUM varchar2(4),
GAL_OWNER varchar2(35),
GAL_AREACODE varchar2(3),
GAL_PHONE varchar2(8),
GAL_RATE number
);
INSERT INTO GALLERY VALUES('5','L. R. Gilliam','901','123-4456','0.37');
INSERT INTO GALLERY VALUES('6','G. G. Waters','405','353-2243','0.45');

/* -- */

CREATE TABLE PAINTER (
PTR_NUM varchar2(4),
PTR_LASTNAME varchar2(15),
PTR_FIRSTNAME varchar2(15),
PTR_AREACODE varchar2(3),
PTR_PHONE varchar2(8)
);
INSERT INTO PAINTER VALUES('123','Ross','Georgette','901','885-4567');
INSERT INTO PAINTER VALUES('126','Itero','Julio','901','346-1112');
INSERT INTO PAINTER VALUES('127','Geoff','George','615','221-4456');

/* -- */

CREATE TABLE PAINTING (
PTNG_NUM varchar2(4),
PTNG_TITLE varchar2(35),
PTNG_PRICE number,
PTR_NUM varchar2(4),
GAL_NUM varchar2(4)
);
INSERT INTO PAINTING VALUES('1338','Dawn Thunder','245.5','123','5');
INSERT INTO PAINTING VALUES('1339','A Faded Rose','6723','123','');
INSERT INTO PAINTING VALUES('1340','The Founders','567.99','126','6');
INSERT INTO PAINTING VALUES('1341','Hasty Pudding Exit','145.5','123','');
INSERT INTO PAINTING VALUES('1342','Plastic Paradise','8328.99','126','6');
INSERT INTO PAINTING VALUES('1343','Roamin''','785','127','6');
INSERT INTO PAINTING VALUES('1344','Wild Waters','999','127','5');
INSERT INTO PAINTING VALUES('1345','Stuff ''n Such ''n Some','9800','123','5');

