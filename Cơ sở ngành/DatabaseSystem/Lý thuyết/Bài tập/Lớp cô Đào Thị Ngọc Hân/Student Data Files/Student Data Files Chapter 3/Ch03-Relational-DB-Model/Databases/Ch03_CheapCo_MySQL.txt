/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE PRODUCT (
PROD_CODE varchar(8),
PROD_DESCRIPTION varchar(30),
PROD_STOCK_DATE datetime,
PROD_ON_HAND int,
PROD_PRICE numeric,
VEND_CODE int
)
ENGINE = INNODB;

INSERT INTO PRODUCT VALUES('12-WW/P2','7.25-in. power saw blade','2018-4-7','12','1.19','123');
INSERT INTO PRODUCT VALUES('1QQ23-55','2.5-in. wood screw, 100','2018-3-19','123','4.49','123');
INSERT INTO PRODUCT VALUES('231-78-W','PVC pipe, 3.5-in., 8 ft.','2017-12-7','45','8.87','121');
INSERT INTO PRODUCT VALUES('33564/U','Rat-tail file, 0.125-in., fine','2018-3-8','18','1.19','123');
INSERT INTO PRODUCT VALUES('AR/3/TYR','Cordless drill, 0.25-in.','2017-11-29','8','45.99','121');
INSERT INTO PRODUCT VALUES('DT-34-WW','Phillips screwdriver pack','2017-12-20','11','23.29','123');
INSERT INTO PRODUCT VALUES('EE3-67/W','Sledge hammer, 12 lb.','2018-2-25','9','17.99','121');
INSERT INTO PRODUCT VALUES('ER-56/DF','Houselite chain saw, 16-in.','2017-12-28','7','235.49','125');
INSERT INTO PRODUCT VALUES('FRE-TRY9','Jigsaw, 12-in blade','2017-8-12','67','1.45','125');
INSERT INTO PRODUCT VALUES('SE-67-89','Jigsaw, 8-in. blade','2017-10-11','34','1.35','125');
INSERT INTO PRODUCT VALUES('ZW-QR/AV','Hardware cloth, 0.25-in.','2018-4-23','14','12.99','123');
INSERT INTO PRODUCT VALUES('ZX-WR/FR','Claw hammer','2018-3-1','15','8.95','121');

/* -- */


CREATE TABLE VENDOR (
VEND_CODE int,
VEND_NAME varchar(50),
VEND_CONTACT varchar(50),
VEND_AREACODE varchar(50),
VEND_PHONE varchar(50)
)
ENGINE = INNODB;

INSERT INTO VENDOR VALUES('120','BargainSnapper, Inc.','Melanie T. Travis','615','899-1234');
INSERT INTO VENDOR VALUES('121','Cut''nGlow Co.','Henry J. Olero','615','342-9896');
INSERT INTO VENDOR VALUES('122','Rip & Rattle Supply Co.','Anne R. Morrins','901','225-1127');
INSERT INTO VENDOR VALUES('123','Tools ''R Us','Juliette G. McHenry','615','546-7894');
INSERT INTO VENDOR VALUES('124','Trowel & Dowel, Inc.','George F. Frederick','901','453-4567');
INSERT INTO VENDOR VALUES('125','Bow & Wow Tools','Bill S. Sedwick','904','324-9988');
