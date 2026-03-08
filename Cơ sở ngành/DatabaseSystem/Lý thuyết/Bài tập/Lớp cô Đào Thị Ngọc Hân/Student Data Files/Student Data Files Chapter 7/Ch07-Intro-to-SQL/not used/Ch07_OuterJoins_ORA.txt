/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE PRODUCT (
PROD_CODE varchar2(20),
PROD_DESCRIPTION varchar2(60),
PROD_PRICE float(8),
PROD_QOH integer,
VEND_NUM integer
);
INSERT INTO PRODUCT VALUES('COCBLPAR6','6 ft. parallel cable, shielded metal case','14.34','63','5');
INSERT INTO PRODUCT VALUES('DRSUCR44MX','Removable cartridge, 44MB, Maxell','45.95','23','3');
INSERT INTO PRODUCT VALUES('DRSUCR88MX','Removable cartridge, 88MB, Maxell','52.99','41','');
INSERT INTO PRODUCT VALUES('DRSUDI12-3M','3.5" HD/DS Diskettes, 1.44 MB formatted, IBM, 12/box, 3M','5.99','95','5');
INSERT INTO PRODUCT VALUES('DRSUDI50-3M','3.5" HD/DS Diskettes, 1.44 MB formatted, IBM, 50/box, 3M','16.43','108','2');
INSERT INTO PRODUCT VALUES('DRSUTC3490E','Tape cartridge, 1,100ft, 36-track, AS400-3480-3490E','21.75','22','2');
INSERT INTO PRODUCT VALUES('PRCTCANBC02','Canon color cartridge, BJ-100, 2200, 210, 230','36.57','102','9');
INSERT INTO PRODUCT VALUES('PRCTHPDJ56','HP DeskJet Plus, 500C, 550C, 600','26.95','89','3');
INSERT INTO PRODUCT VALUES('PRCTLEX4072','IBM (Lexmark) 4072 ExecJet cartridge','22.95','127','5');

/* -- */

CREATE TABLE VENDOR (
VEND_NUM integer,
VEND_NAME varchar2(20),
VEND_CONTACT varchar2(20),
VEND_PHONE varchar2(14)
);
INSERT INTO VENDOR VALUES('1','CompuDark, Inc.','H. D. Cable','(123) 333-4567');
INSERT INTO VENDOR VALUES('2','MooComp, Inc.','A. A. Grassfield','(234) 543-8902');
INSERT INTO VENDOR VALUES('3','Gettum Supply','C. F. Inthere','(433) 456-7654');
INSERT INTO VENDOR VALUES('4','PC Country','I. M. Formerly','(234) 214-8790');
INSERT INTO VENDOR VALUES('5','Dill Computer, Inc.','I. B. Pickle','(901) 786-3338');
INSERT INTO VENDOR VALUES('6','Outeredge Supply','D. N. Whammy','(501) 778-9345');
INSERT INTO VENDOR VALUES('7','Compuck, Inc.','C. C. Rider','(433) 190-2229');
INSERT INTO VENDOR VALUES('8','Toshboo Supply','H. D. Eyestrain','(344) 996-3124');
