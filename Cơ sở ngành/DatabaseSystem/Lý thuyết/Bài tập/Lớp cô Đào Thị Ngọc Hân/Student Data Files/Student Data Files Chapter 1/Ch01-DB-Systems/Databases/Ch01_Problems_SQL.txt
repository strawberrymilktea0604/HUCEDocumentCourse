/* Database Systems, Coronel/Morris */
/* Type of SQL : SQL Server */

CREATE TABLE PROB_1_01 (
PROJECT_CODE varchar(5),
PROJECT_MANAGER varchar(15),
MANAGER_PHONE varchar(12),
MANAGER_ADDRESS varchar(38),
PROJECT_BID_PRICE numeric(8));


INSERT INTO PROB_1_01 VALUES('21-5Z','Holly B. Parker','904-338-3416','3334 Lee Rd., Gainesville, FL  37123',16833460);
INSERT INTO PROB_1_01 VALUES('25-2D','Jane D. Grant','615-898-9909','218 Clark Blvd., Nashville, TN  36362',12500000);
INSERT INTO PROB_1_01 VALUES('25-5A','George F. Dorts','615-227-1245','124 River Dr., Franklin, TN  29185',32512420);
INSERT INTO PROB_1_01 VALUES('25-9T','Holly B. Parker','904-338-3416','3334 Lee Rd., Gainesville, FL  37123',21563234);
INSERT INTO PROB_1_01 VALUES('27-4Q','George F. Dorts','615-227-1245','124 River Dr., Franklin, TN  29185',10314545);
INSERT INTO PROB_1_01 VALUES('29-2D','Holly B. Parker','904-338-3416','3334 Lee Rd., Gainesville, FL  37123',25559999);
INSERT INTO PROB_1_01 VALUES('31-7P','William K. Moor','904-445-2719','216 Morton Rd., Stetson, FL  30155',56850000);


/* -- */

CREATE TABLE PROB_1_05 (
PROJ_NUM numeric(8),
PROJ_NAME varchar(12),
EMP_NUM numeric(8),
EMP_NAME varchar(20),
JOB_CODE varchar(2),
JOB_CHG_HOUR numeric(5,2),
PROJ_HOURS numeric(5,2),
EMP_PHONE varchar(12));

INSERT INTO PROB_1_05 VALUES('1','Hurricane','101','John D. Newson','EE','85','13.3','653-234-3245');
INSERT INTO PROB_1_05 VALUES('1','Hurricane','105','David F. Schwann','CT','60','16.2','653-234-1123');
INSERT INTO PROB_1_05 VALUES('1','Hurricane','110','Anne R. Ramoras','CT','60','14.3','615-233-5568');
INSERT INTO PROB_1_05 VALUES('2','Coast','101','John D. Newson','EE','85','19.8','653-234-3254');
INSERT INTO PROB_1_05 VALUES('2','Coast','108','June H. Sattlemeir','EE','85','17.5','905-554-7812');
INSERT INTO PROB_1_05 VALUES('3','Satellite','110','Anne R. Ramoras','CT','62','11.6','615-233-5568');
INSERT INTO PROB_1_05 VALUES('3','Satellite','105','David F. Schwann','CT','26','23.4','653-234-1123');
INSERT INTO PROB_1_05 VALUES('3','Satelite','123','Mary D. Chen','EE','85','19.1','615-233-5432');
INSERT INTO PROB_1_05 VALUES('3','Satellite','112','Allecia R. Smith','BE','85','20.7','615-678-6879');

/* -- */

CREATE TABLE PROB_1_09 (
BUILDING_CODE varchar(3),
ROOM_CODE varchar(4),
TEACHER_LNAME varchar(12),
TEACHER_FNAME varchar(12),
TEACHER_INITIAL varchar(1),
DAYS_TIME varchar(15));

INSERT INTO PROB_1_09 VALUES('KOM','204E','Williston','Horace','G','MWF 8:00-8:50');
INSERT INTO PROB_1_09 VALUES('KOM','123','Cordoza','Maria','L','MWF 8:00-8:50');
INSERT INTO PROB_1_09 VALUES('LDB','504','Patroski','Donald','J','TTh 1:00-2:15');
INSERT INTO PROB_1_09 VALUES('KOM','34','Hawkins','Anne','W','MWF 10:00-10:50');
INSERT INTO PROB_1_09 VALUES('JKP','225B','Risell','James','','TTh 9:00-10:15');
INSERT INTO PROB_1_09 VALUES('LDB','301','Robertson','Jeanette','P','TTh 9:00-10:15');
INSERT INTO PROB_1_09 VALUES('KOM','204E','Cordoza','Maria','I','MWF 9:00-9:50');
INSERT INTO PROB_1_09 VALUES('LDB','504','Williston','Horace','G','TTh 1:00-2:15');
INSERT INTO PROB_1_09 VALUES('KOM','34','Cordoza','Maria','L','MWF 11:00-11:50');
INSERT INTO PROB_1_09 VALUES('LDB','504','Patroski','Donald','J','MWF 2:00-2:50');
