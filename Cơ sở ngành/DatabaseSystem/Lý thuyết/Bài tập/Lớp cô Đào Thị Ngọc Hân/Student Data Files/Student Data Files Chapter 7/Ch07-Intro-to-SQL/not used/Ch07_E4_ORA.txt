/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE PRODUCT (
P_CODE varchar2(10),
P_DESCRIPT varchar2(35),
P_INDATE date,
P_QOH integer,
P_MIN integer,
P_PRICE float(8),
P_DISCOUNT float(8),
V_CODE varchar2(5)
);
INSERT INTO PRODUCT VALUES('11QER/31','Power painter, 15 psi., 3-nozzle',   '1/5/2016','8','5','109.99','0','25595');
INSERT INTO PRODUCT VALUES('13-Q2/P2','7.25-in. pwr. saw blade',          '12/11/2015','32','15','14.99','0.05','21344');
INSERT INTO PRODUCT VALUES('14-Q1/L3','9.00-in. pwr. saw blade',          '12/11/2015','18','12','17.49','0','21344');
INSERT INTO PRODUCT VALUES('1546-QQ2','Hrd. cloth, 1/4-in., 2x50',         '9/12/2015','15','8','39.95','0','23119');
INSERT INTO PRODUCT VALUES('1558-QW1','Hrd. cloth, 1/2-in., 3x50',         '9/12/2015','23','5','43.99','0','23119');
INSERT INTO PRODUCT VALUES('2232/QTY','B&D jigsaw, 12-in. blade',         '11/27/2015','8','5','109.92','0.05','24288');
INSERT INTO PRODUCT VALUES('2232/QWE','B&D jigsaw, 8-in. blade',           '2/15/2016','6','5','99.87','0.05','24288');
INSERT INTO PRODUCT VALUES('2238/QPD','B&D cordless drill, 1/2-in.',      '11/17/2015','12','5','38.95','0.05','25595');
INSERT INTO PRODUCT VALUES('23109-HB','Claw hammer',                      '12/18/2015','23','10','5.95','0.1','21225');
INSERT INTO PRODUCT VALUES('23114-AA','Sledge hammer, 12 lb.',            '12/30/2015','8','5','14.40','0.05','');
INSERT INTO PRODUCT VALUES('54778-2T','Rat-tail file, 1/8-in. fine',      '11/28/2015','43','20','4.99','0','21344');
INSERT INTO PRODUCT VALUES('89-WRE-Q','Hicut chain saw, 16 in.',            '8/4/2015','11','5','256.99','0.05','24288');
INSERT INTO PRODUCT VALUES('PVC23DRT','PVC pipe, 3.5-in., 8-ft',           '1/17/2016','188','75','5.87','0','');
INSERT INTO PRODUCT VALUES('SM-18277','1.25-in. metal screw, 25',         '12/27/2015','172','75','6.99','0','21225');
INSERT INTO PRODUCT VALUES('SW-23116','2.5-in. wd. screw, 50',            '10/22/2015','237','100','8.45','0','21231');
INSERT INTO PRODUCT VALUES('WR3/TT3','Steel matting, 4''x8''x1/6", .5" mesh','12/15/2015','18','5','119.95','0.1','25595');

/* -- */

CREATE TABLE VENDOR (
V_CODE varchar2(5),
V_NAME varchar2(15),
V_CONTACT varchar2(50),
V_AREACODE varchar2(3),
V_PHONE varchar2(8),
V_STATE varchar2(2),
V_ORDER varchar2(1)
);
INSERT INTO VENDOR VALUES('21225','Bryson, Inc.','Smithson','615','223-3234','TN','Y');
INSERT INTO VENDOR VALUES('21226','SuperLoo, Inc.','Flushing','904','215-8995','FL','N');
INSERT INTO VENDOR VALUES('21231','D&E Supply','Singh','615','228-3245','TN','Y');
INSERT INTO VENDOR VALUES('21344','Gomez Bros.','Ortega','615','889-2546','KY','N');
INSERT INTO VENDOR VALUES('22567','Dome Supply','Smith','901','678-1419','GA','N');
INSERT INTO VENDOR VALUES('23119','Randsets Ltd.','Anderson','901','678-3998','GA','Y');
INSERT INTO VENDOR VALUES('24004','Brackman Bros.','Browning','615','228-1410','TN','N');
INSERT INTO VENDOR VALUES('24288','ORDVA, Inc.','Hakford','615','898-1234','TN','Y');
INSERT INTO VENDOR VALUES('25443','B&K, Inc.','Smith','904','227-0093','FL','N');
INSERT INTO VENDOR VALUES('25501','Damal Supplies','Smythe','615','890-3529','TN','N');
INSERT INTO VENDOR VALUES('25595','Rubicon Sis.','Orton','904','456-0092','FL','Y');
