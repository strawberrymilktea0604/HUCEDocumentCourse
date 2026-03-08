/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL  */


/* -- */
CREATE TABLE VENDOR (
  V_CODE      VARCHAR(5),
  V_NAME      VARCHAR(15),
  V_CONTACT   VARCHAR(50),
  V_AREACODE  VARCHAR(3),
  V_PHONE     VARCHAR(8),
  V_STATE     VARCHAR(2),
  V_ORDER     VARCHAR(1),
  PRIMARY KEY(V_CODE)
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

/* -- */
CREATE TABLE PRODUCT (
  P_CODE      VARCHAR(10),
  P_DESCRIPT  VARCHAR(35),
  P_INDATE    DATETIME,
  P_QOH       INT(3),
  P_MIN       INT(3),
  P_PRICE     FLOAT(8),
  P_DISCOUNT  FLOAT(8),
  V_CODE      VARCHAR(5),
  PRIMARY KEY(P_CODE),
  FOREIGN KEY(V_CODE) REFERENCES VENDOR(V_CODE)
);
INSERT INTO PRODUCT VALUES('11QER/31','Power painter, 15 psi., 3-nozzle','2016-1-5','8','5','109.99','0','25595');
INSERT INTO PRODUCT VALUES('13-Q2/P2','7.25-in. pwr. saw blade',         '2015-12-11','32','15','14.99','0.05','21344');
INSERT INTO PRODUCT VALUES('14-Q1/L3','9.00-in. pwr. saw blade',         '2015-12-11','18','12','17.49','0','21344');
INSERT INTO PRODUCT VALUES('1546-QQ2','Hrd. cloth, 1/4-in., 2x50',       '2015-9-12','15','8','39.95','0','23119');
INSERT INTO PRODUCT VALUES('1558-QW1','Hrd. cloth, 1/2-in., 3x50',       '2015-9-12','23','5','43.99','0','23119');
INSERT INTO PRODUCT VALUES('2232/QTY','B&D jigsaw, 12-in. blade',        '2015-11-27','8','5','109.92','0.05','24288');
INSERT INTO PRODUCT VALUES('2232/QWE','B&D jigsaw, 8-in. blade',         '2016-2-15','6','5','99.87','0.05','24288');
INSERT INTO PRODUCT VALUES('2238/QPD','B&D cordless drill, 1/2-in.',     '2015-11-17','12','5','38.95','0.05','25595');
INSERT INTO PRODUCT VALUES('23109-HB','Claw hammer',                     '2015-12-18','23','10','5.95','0.1','21225');
INSERT INTO PRODUCT VALUES('23114-AA','Sledge hammer, 12 lb.',           '2015-12-30','8','5','14.40','0.05',NULL);
INSERT INTO PRODUCT VALUES('54778-2T','Rat-tail file, 1/8-in. fine',     '2015-11-28','43','20','4.99','0','21344');
INSERT INTO PRODUCT VALUES('89-WRE-Q','Hicut chain saw, 16 in.',         '2015-8-4','11','5','256.99','0.05','24288');
INSERT INTO PRODUCT VALUES('PVC23DRT','PVC pipe, 3.5-in., 8-ft',         '2016-1-17','188','75','5.87','0',NULL);
INSERT INTO PRODUCT VALUES('SM-18277','1.25-in. metal screw, 25',        '2015-12-27','172','75','6.99','0','21225');
INSERT INTO PRODUCT VALUES('SW-23116','2.5-in. wd. screw, 50',           '2015-10-22','237','100','8.45','0','21231');
INSERT INTO PRODUCT VALUES('WR3/TT3','Steel matting, 4''x8''x1/6", .5" mesh','2015-12-15','18','5','119.95','0.1','25595');

