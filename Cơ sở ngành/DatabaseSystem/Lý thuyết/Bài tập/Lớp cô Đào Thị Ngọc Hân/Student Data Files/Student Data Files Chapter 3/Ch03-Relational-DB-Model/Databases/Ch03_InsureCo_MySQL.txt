/* Database Systems, Coronel/Morris */
/* Type of SQL : MySQL */


CREATE TABLE AGENT (
AGENT_CODE int,
AGENT_LNAME varchar(15),
AGENT_FNAME varchar(15),
AGENT_INITIAL varchar(1),
AGENT_AREACODE varchar(3),
AGENT_PHONE varchar(8),
AGENT_ADDRESS varchar(30),
AGENT_CITY varchar(15),
AGENT_STATE varchar(2),
AGENT_ZIP varchar(5),
AGENT_DATE_HIRED datetime,
AGENT_YTD_PAY numeric,
AGENT_YTD_FIT numeric,
AGENT_YTD_FICA numeric,
AGENT_YTD_SLS numeric,
AGENT_DEP int
)
ENGINE = INNODB;

INSERT INTO AGENT VALUES('501','Alby','Alex','B','713','228-1249','123 Pleasant View Dr.','Nashville','TN','37119','2000-11-1','26566.24','6641.56','2125.3','132735.75','3');
INSERT INTO AGENT VALUES('502','Hahn','Leah','F','615','882-1244','334 East Main Street','Louisville','KY','25246','1986-5-23','32213.76','8053.44','2577.1','138967.35','0');
INSERT INTO AGENT VALUES('503',' Okon','John','T','615','123-5589','452 Technology Circle','Oak Ridge','TN','36155','2005-6-15','23198.29','5799.57','1855.86','127093.45','2');


/* -- */

CREATE TABLE CUSTOMER (
CUS_CODE int,
CUS_LNAME varchar(15),
CUS_FNAME varchar(15),
CUS_INITIAL varchar(1),
CUS_AREACODE varchar(3),
CUS_PHONE varchar(8),
CUS_RENEW_DATE datetime,
AGENT_CODE int
)
ENGINE = INNODB;

INSERT INTO CUSTOMER VALUES('10010','Ramas','Alfred','A','615','844-2573','2018-4-5','502');
INSERT INTO CUSTOMER VALUES('10011','Dunne','Leona','K','713','894-1238','2018-6-16','501');
INSERT INTO CUSTOMER VALUES('10012','Smith','Kathy','W','615','894-2285','2019-1-29','502');
INSERT INTO CUSTOMER VALUES('10013','Olowski','Paul','F','615','894-2180','2018-10-14',NULL);
INSERT INTO CUSTOMER VALUES('10014','Orlando','Myron','','615','222-1672','2018-12-28','501');
INSERT INTO CUSTOMER VALUES('10015','O''Brian','Amy','B','713','442-3381','2018-9-22','503');
INSERT INTO CUSTOMER VALUES('10016','Brown','James','G','615','297-1228','2019-3-25','502');
INSERT INTO CUSTOMER VALUES('10017','Williams','George','','615','290-2556','2018-7-17','503');
INSERT INTO CUSTOMER VALUES('10018','Farriss','Anne','G','713','382-7185','2018-12-3','501');
INSERT INTO CUSTOMER VALUES('10019','Smith','Olette','K','615','297-3809','2019-3-14','503');