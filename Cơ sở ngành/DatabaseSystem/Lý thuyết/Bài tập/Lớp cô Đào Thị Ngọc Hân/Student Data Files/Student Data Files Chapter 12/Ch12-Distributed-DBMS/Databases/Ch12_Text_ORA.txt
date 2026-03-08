/* Database Systems, Coronel/Morris */
/* Type of SQL : Oracle */

ALTER SESSION SET NLS_DATE_FORMAT = 'MM/DD/YYYY';

CREATE TABLE CUST_H1 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2),
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_H1 VALUES('10','Sinex, Inc.','12 Main St.','TN','3500','2700','3','1245');
INSERT INTO CUST_H1 VALUES('12','Mynux Corp.','910 Eagle St.','TN','4000','3500','3','3400');

/* -- */

CREATE TABLE CUST_H2 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2),
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_H2 VALUES('15','NBCC Corp.','909 High Ave.','GA','2000','350','2','50');

/* -- */

CREATE TABLE CUST_H3 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2),
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_H3 VALUES('11','Martin Corp.','321 Sunset Blvd.','FL','6000','1200','1','0');
INSERT INTO CUST_H3 VALUES('13','BTBC, Inc.','Rue du Monde','FL','6000','5890','3','1090');
INSERT INTO CUST_H3 VALUES('14','Victory, Inc.','123 Maple St.','FL','1200','550','1','0');

/* -- */

CREATE TABLE CUST_M1 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2)
);
INSERT INTO CUST_M1 VALUES('10','Sinex, Inc.','12 Main St.','TN');
INSERT INTO CUST_M1 VALUES('12','Mynux Corp.','910 Eagle St.','TN');

/* -- */

CREATE TABLE CUST_M2 (
CUS_NUM integer,
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_M2 VALUES('10','3500','2700','3','1245');
INSERT INTO CUST_M2 VALUES('12','4000','3500','3','3400');

/* -- */

CREATE TABLE CUST_M3 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2)
);
INSERT INTO CUST_M3 VALUES('15','NBCC Corp.','909 High Ave.','GA');

/* -- */

CREATE TABLE CUST_M4 (
CUS_NUM integer,
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_M4 VALUES('15','2000','350','2','50');

/* -- */


CREATE TABLE CUST_M5 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2)
);
INSERT INTO CUST_M5 VALUES('11','Martin Corp.','321 Sunset Blvd.','FL');
INSERT INTO CUST_M5 VALUES('13','BTBC, Inc.','Rue du Monde','FL');
INSERT INTO CUST_M5 VALUES('14','Victory, Inc.','123 Maple St.','FL');

/* -- */


CREATE TABLE CUST_M6 (
CUS_NUM integer,
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_M6 VALUES('11','6000','1200','1','0');
INSERT INTO CUST_M6 VALUES('13','6000','5890','3','1090');
INSERT INTO CUST_M6 VALUES('14','1200','550','1','0');

/* -- */


CREATE TABLE CUST_V1 (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2)
);
INSERT INTO CUST_V1 VALUES('10','Sinex, Inc.','12 Main St.','TN');
INSERT INTO CUST_V1 VALUES('11','Martin Corp.','321 Sunset Blvd.','FL');
INSERT INTO CUST_V1 VALUES('12','Mynux Corp.','910 Eagle St.','TN');
INSERT INTO CUST_V1 VALUES('13','BTBC, Inc.','Rue du Monde','FL');
INSERT INTO CUST_V1 VALUES('14','Victory, Inc.','123 Maple St.','FL');
INSERT INTO CUST_V1 VALUES('15','NBCC Corp.','909 High Ave.','GA');

/* -- */

CREATE TABLE CUST_V2 (
CUS_NUM integer,
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUST_V2 VALUES('10','3500','2700','3','1245');
INSERT INTO CUST_V2 VALUES('11','6000','1200','1','0');
INSERT INTO CUST_V2 VALUES('12','4000','3500','3','3400');
INSERT INTO CUST_V2 VALUES('13','6000','5890','3','1090');
INSERT INTO CUST_V2 VALUES('14','1200','550','1','0');
INSERT INTO CUST_V2 VALUES('15','2000','350','2','50');

/* -- */


CREATE TABLE CUSTOMER (
CUS_NUM integer,
CUS_NAME varchar2(15),
CUS_ADDRESS varchar2(20),
CUS_STATE varchar2(2),
CUS_LIMIT float(8),
CUS_BAL float(8),
CUS_RATING varchar2(1),
CUS_DUE float(8)
);
INSERT INTO CUSTOMER VALUES('10','Sinex, Inc.','12 Main St.','TN','3500','2700','3','1245');
INSERT INTO CUSTOMER VALUES('11','Martin Corp.','321 Sunset Blvd.','FL','6000','1200','1','0');
INSERT INTO CUSTOMER VALUES('12','Mynux Corp.','910 Eagle St.','TN','4000','3500','3','3400');
INSERT INTO CUSTOMER VALUES('13','BTBC, Inc.','Rue du Monde','FL','6000','5890','3','1090');
INSERT INTO CUSTOMER VALUES('14','Victory, Inc.','123 Maple St.','FL','1200','550','1','0');
INSERT INTO CUSTOMER VALUES('15','NBCC Corp.','909 High Ave.','GA','2000','350','2','50');





