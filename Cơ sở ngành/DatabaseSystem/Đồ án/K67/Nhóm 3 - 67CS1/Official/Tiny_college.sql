CREATE DATABASE  IF NOT EXISTS `tinycollege` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `tinycollege`;
-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: localhost    Database: tinycollege
-- ------------------------------------------------------
-- Server version	8.0.36

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `building`
--

DROP TABLE IF EXISTS `building`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `building` (
  `BLDG_CODE` varchar(20) NOT NULL,
  `BLDG_NAME` varchar(100) DEFAULT NULL,
  `BLDG_LOCATION` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`BLDG_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `building`
--

LOCK TABLES `building` WRITE;
/*!40000 ALTER TABLE `building` DISABLE KEYS */;
INSERT INTO `building` VALUES ('Admin','Administrative Offices','144 Xuan Thuy St'),('Applied Sci','Applied Science Building','366 Nguyen Trai Rd'),('Art Sci','Art and Science Building','360 D. La Thanh St'),('Business','Business Building','207 Giai Phong St'),('Education','Education Building','136 Xuan Thuy St'),('Engineering','Engineering Building','55 Giai Phong St'),('Science','Science Building','334 Nguyen Trai Rd');
/*!40000 ALTER TABLE `building` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class`
--

DROP TABLE IF EXISTS `class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `class` (
  `CLASS_CODE` varchar(5) NOT NULL,
  `CRS_CODE` varchar(10) DEFAULT NULL,
  `CLASS_SECTION` varchar(2) DEFAULT NULL,
  `CLASS_TIME` varchar(20) DEFAULT NULL,
  `ROOM_CODE` varchar(8) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  `SEMESTER_CODE` char(10) DEFAULT NULL,
  PRIMARY KEY (`CLASS_CODE`),
  KEY `CRS_CODE` (`CRS_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  KEY `class_ibfk_3_idx` (`ROOM_CODE`),
  KEY `SEMESTER_CODE` (`SEMESTER_CODE`),
  CONSTRAINT `class_ibfk_1` FOREIGN KEY (`CRS_CODE`) REFERENCES `course` (`CRS_CODE`),
  CONSTRAINT `class_ibfk_2` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`),
  CONSTRAINT `class_ibfk_3` FOREIGN KEY (`ROOM_CODE`) REFERENCES `room` (`ROOM_CODE`),
  CONSTRAINT `class_ibfk_4` FOREIGN KEY (`SEMESTER_CODE`) REFERENCES `semester` (`SEMESTER_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class`
--

LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES ('10001','PHYS-101','4','MWF 9:00-10:15 a.m.','SCI101',105,'SUM2024'),('10002','CHEM-201','4','TTh 10:00-11:15 a.m.','SCI102',119,'SUM2024'),('10003','MATH-301','3','MWF 11:00-12:15 p.m.','MATH201',297,'SUM2024'),('10004','CIS-101','3','TTh 2:00-3:15 p.m.','CIS101',209,'SUM2024'),('10005','ENGL-102','3','MWF 1:00-2:15 p.m.','ENGL105',222,'SUM2024'),('10006','HIST-202','3','TTh 3:30-4:45 p.m.','HIST101',103,'FAL2024'),('10007','BIOL-101','4','MWF 10:30-11:45 a.m.','BIOL202',387,'SUM2024'),('10008','PSYCH-101','3','TTh 11:30-12:45 p.m.','PSYCH101',450,'SUM2024'),('10009','SOC-101','3','MWF 9:00-10:15 a.m.','SOC101',311,'SUM2024'),('10010','ENGL-101','3','TTh 1:00-2:15 p.m.','ENGL105',325,'SPR2024'),('10011','ART-201','3','MWF 2:30-3:45 p.m.','ART101',457,'SUM2024'),('10012','ACCT-211','1','MWF 8:00-8:50 a.m.','BUS311',105,'SPR2023'),('10013','ACCT-211','2','MWF 9:00-9:50 a.m.','BUS200',105,'SPR2023'),('10014','ACCT-211','3','TTh 2:30-3:45 p.m.','BUS252',342,'SUM2024'),('10015','ACCT-212','1','MWF 10:00-10:50 a.m.','BUS311',301,'FAL2023'),('10016','ACCT-212','2','Th 6:00-8:40 p.m.','BUS252',301,'SPR2024'),('10017','CIS-220','1','MWF 9:00-9:50 a.m.','KLR209',228,'SUM2023'),('10018','CIS-220','2','MWF 9:00-9:50 a.m.','KLR211',114,'FAL2023'),('10019','CIS-220','3','MWF 10:00-10:50 a.m.','KLR209',228,'SPR2024'),('10020','CIS-420','1','W 6:00-8:40 p.m.','KLR209',162,'SUM2024'),('10021','QM-261','1','MWF 8:00-8:50 a.m.','KLR200',114,'SPR2023'),('10022','QM-261','2','TTh 1:00-2:15 p.m.','KLR200',114,'SUM2023'),('10023','QM-362','1','MWF 11:00-11:50 a.m.','KLR200',162,'FAL2023'),('10024','QM-362','2','TTh 2:30-3:45 p.m.','KLR200',162,'SPR2024'),('10025','MATH-243','1','Th 6:00-8:40 p.m.','DRE155',325,'SUM2024'),('10040','MUS-101','2','TTh 4:00-5:15 p.m.','MUS101',460,'SUM2024'),('10041','ECON-101','3','MWF 8:00-9:15 a.m.','BUS200',299,'SUM2024'),('10042','ACCT-211','3','TTh 9:30-10:45 p.m.','BUS252',299,'FAL2024'),('10043','MGMT-301','3','MWF 3:00-4:15 p.m.','BUS311',191,'FAL2024'),('10044','APBIOL-201','3','TTh 9:00-10:15 a.m.','SCI111',387,'SUM2024'),('10045','ENGL-301','3','MWF 11:00-12:15 p.m.','ENGL301',325,'FAL2024'),('10046','CHEM-101','4','TTh 3:00-4:15 p.m.','SCI101',119,'SUM2024'),('10047','PHYS-201','4','MWF 2:00-3:15 p.m.','SCI202',118,'SUM2024'),('10048','BIOL-201','4','TTh 10:30-11:45 a.m.','BIOL111',110,'SUM2024'),('10050','EDU-101','2','MWF 2 - 2:50 p.m.','EDUC201',470,'SUM2024');
/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `course`
--

DROP TABLE IF EXISTS `course`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `course` (
  `CRS_CODE` varchar(10) NOT NULL,
  `DEPT_CODE` varchar(10) DEFAULT NULL,
  `CRS_TITLE` varchar(35) DEFAULT NULL,
  `CRS_CREDIT` float DEFAULT NULL,
  `CRS_DESCRIPTION` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`CRS_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course`
--

LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES ('ACCT-211','ACCT','Financial Accounting',3,'Basics of financial accounting'),('ACCT-212','ACCT','Accounting II',3,'Intermediate Accounting'),('APBIOL-201','BIOL','AP Biology',2,'Advanced placement biology'),('ART-201','ART','Art History',3,'History of visual arts'),('BIOL-101','BIOL','General Biology',4,'Basics of biological science'),('BIOL-201','BIOL','Cell Biology',4,'Study of cellular biology'),('CHEM-101','CHEM','General Chemistry',4,'Fundamentals of chemistry'),('CHEM-201','CHEM','Organic Chemistry',2,'Study of organic molecules'),('CIS-101','CIS','Intro to Computer Science',2,'Fundamentals of computing'),('CIS-220','CIS','Intro to Microcomputing',3,'Introduction to Microcomputing'),('CIS-420','CIS','Database Design and Implementation',4,'Database Design and Implementation'),('ECON-101','ECON/FIN','Principles of Economics I',3,'Introduction to economics'),('ECON-102','ECON/FIN','Principles of Economics II',2,'Introduction to economics'),('ECON-301','ECON/FIN','Macroeconomics',3,'Study of economy-wide phenomena'),('EDU-101','EDU','Foundations of Education',2,'Introduction to educational principles'),('EDU-201','EDU','Educational Psychology',3,'Study of how people learn'),('EDU-301','EDU','Curriculum Development',3,'Methods for creating effective curricula'),('ENGL-101','ENGL','English Composition',2,'Writing and composition skills'),('ENGL-102','ENGL','English Literature II',3,'Survey of English literature'),('ENGL-301','ENGL','Advanced Writing',2,'Techniques in advanced writing'),('FIN-201','ECON/FIN','Corporate Finance',3,'Basics of corporate finance'),('HIST-202','HIST','World History II',3,'History from 1500 to present'),('MATH-243','MATH','Mathematics for Managers',1,'Mathematics for Managers'),('MATH-301','MATH','Advanced Calculus',1,'Calculus of several variables'),('MGMT-301','MKT/MGT','Management Principles',3,'Fundamentals of management'),('MGT-201','MKT/MGT','Organizational Behavior',3,'Study of human behavior in organizations'),('MKT-101','MKT/MGT','Marketing Fundamentals',3,'Basics of marketing'),('MKT-302','MKT/MGT','Consumer Behavior',3,'Understanding consumer decision-making'),('MUS-101','MUS','Music Theory',3,'Basics of music theory'),('PHYS-101','PHYS','Intro to Physics',2,'Basic principles of physics'),('PHYS-201','PHYS','Modern Physics',4,'Concepts of modern physics'),('PSYCH-101','PSYCH','Intro to Psychology',3,'Fundamentals of psychology'),('QM-261','CIS','Intro to Statistics',3,'Introduction to Statistics'),('QM-362','CIS','Statistical Applications',4,'Statistical Applications'),('SOC-101','SOC','Intro to Sociology',3,'Principles of sociology');
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `department` (
  `DEPT_CODE` varchar(10) NOT NULL,
  `DEPT_NAME` varchar(30) DEFAULT NULL,
  `SCHOOL_CODE` varchar(8) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  PRIMARY KEY (`DEPT_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  KEY `SCHOOL_CODE` (`SCHOOL_CODE`),
  CONSTRAINT `department_ibfk_1` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`),
  CONSTRAINT `department_ibfk_2` FOREIGN KEY (`SCHOOL_CODE`) REFERENCES `school` (`SCHOOL_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('ACCT','Accounting','BUS',114),('ART','Fine Arts','A&SCI',435),('BIOL','Biology','SCI',387),('CHEM','Chemistry','SCI',205),('CIS','Computer Info. Systems','BUS',209),('ECON/FIN','Economics/Finance','BUS',299),('EDU','Education','EDU',114),('ENGL','English','A&SCI',160),('HIST','History','A&SCI',103),('MATH','Mathematics','SCI',297),('MKT/MGT','Marketing/Management','BUS',106),('MUS','Music','A&SCI',460),('PHYS','Physics','SCI',105),('PSYCH','Psychology','A&SCI',195),('SOC','Sociology','A&SCI',342);
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enroll`
--

DROP TABLE IF EXISTS `enroll`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enroll` (
  `CLASS_CODE` varchar(5) NOT NULL,
  `STU_NUM` int NOT NULL,
  `ENROLL_GRADE` varchar(50) DEFAULT NULL,
  `ENROLL_DATE` date DEFAULT NULL,
  PRIMARY KEY (`CLASS_CODE`,`STU_NUM`),
  KEY `STU_NUM` (`STU_NUM`),
  CONSTRAINT `enroll_ibfk_1` FOREIGN KEY (`CLASS_CODE`) REFERENCES `class` (`CLASS_CODE`),
  CONSTRAINT `enroll_ibfk_2` FOREIGN KEY (`STU_NUM`) REFERENCES `student` (`STU_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enroll`
--

LOCK TABLES `enroll` WRITE;
/*!40000 ALTER TABLE `enroll` DISABLE KEYS */;
INSERT INTO `enroll` VALUES ('10004',325778,'C','2024-03-14'),('10006',321521,'B','2024-07-01'),('10007',321475,'D','2024-03-15'),('10007',321667,'A','2024-03-14'),('10008',321560,'A','2024-03-11'),('10009',321668,'D','2024-03-15'),('10010',321556,'A','2023-12-21'),('10010',321563,'A','2023-12-20'),('10014',321452,'C','2023-01-10'),('10014',324257,'B','2023-02-10'),('10014',324258,'B','2024-03-12'),('10014',324274,'C','2024-03-12'),('10017',321561,'C','2023-03-13'),('10018',321452,'A','2024-05-06'),('10018',324257,'B','2024-07-06'),('10019',321480,'B','2023-12-20'),('10021',321452,'C','2024-08-01'),('10021',324257,'C','2024-08-02'),('10025',321978,'A','2024-03-12'),('10041',321476,'A','2024-03-13'),('10041',326785,'A','2024-03-12'),('10042',324274,'C','2024-07-03'),('10042',324299,'B','2024-07-04'),('10042',325667,'B','2024-07-02'),('10046',321474,'D','2024-03-10'),('10046',321589,'B','2024-03-15'),('10047',321373,'D','2024-03-13'),('10050',321476,'D','2024-03-11');
/*!40000 ALTER TABLE `enroll` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `professor`
--

DROP TABLE IF EXISTS `professor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `professor` (
  `PROF_NUM` int NOT NULL,
  `DEPT_CODE` varchar(10) DEFAULT NULL,
  `PROF_LNAME` varchar(20) DEFAULT NULL,
  `PROF_FNAME` varchar(20) DEFAULT NULL,
  `PROF_INITIAL` char(1) DEFAULT NULL,
  `PROF_EMAIL` varchar(50) DEFAULT NULL,
  `PROF_SPECIALTY` varchar(50) DEFAULT NULL,
  `PROF_RANK` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`PROF_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `professor`
--

LOCK TABLES `professor` WRITE;
/*!40000 ALTER TABLE `professor` DISABLE KEYS */;
INSERT INTO `professor` VALUES (103,'HIST','News','John','G','john.news@tinycollege.edu','Assistant Professor','Ph.D'),(104,'ENGL','Senior','David','H','david.senior@tinycollege.edu','Associate Professor','Ph.D'),(105,'PHYS','Arbough','June','E','june.arbough@tinycollege.edu','Professor','Ph.D'),(106,'MKT/MGT','Ramoras','Anne','K','anne.ramoras@tinycollege.edu','Lecturer','Ph.D'),(107,'PHYS','Hawking','Stephen','W','stephen.hawking@tinycollege.edu','Professor','Ph.D'),(108,'PHYS','Feynman','Richard','P','richard.feynman@tinycollege.edu','Professor','Ph.D'),(110,'BIOL','Johnson','Alice','K','alice.johnson@tinycollege.edu','Senior Lecturer','Ph.D'),(112,'CHEM','Ramsay','William','B','william.ramsay@tinycollege.edu','Associate Professor','Ph.D'),(113,'CHEM','Sabatier','Paul','E','paul.sabatier@tinycollege.edu','Assistant Professor','Ph.D'),(114,'ACCT','Smithfield','William',NULL,'william.smithfield@tinycollege.edu','Assistant Professor','DBA'),(116,'PHYS','Einstein','Albert','A','albert.einstein@tinycollege.edu','Professor','Ph.D'),(117,'PHYS','Curie','Marie','S','marie.curie@tinycollege.edu','Assistant Professor','Ph.D'),(118,'PHYS','Sagan','Carl','E','carl.sagan@tinycollege.edu','Associate Professor','Ph.D'),(119,'CHEM','Pauling','Linus','C','linus.pauling@tinycollege.edu','Professor','Ph.D'),(120,'CHEM','Levi','Primo','M','primo.levi@tinycollege.edu','Assistant Professor','Ph.D'),(121,'CHEM','Hoffmann','Roald','F','roald.hoffmann@tinycollege.edu','Professor','Ph.D'),(155,'MATH','Alonzo','Maria','D','maria.alonzo@tinycollege.edu','Associate Professor','Ph.D'),(160,'ENGL','Washington','Ralph','B','ralph.washington@tinycollege.edu','Professor','Ph.D'),(162,'CIS','Smith','Larry','W','larry.smith@tinycollege.edu','Lecturer','Ph.D'),(191,'MKT/MGT','Olenko','Gerald','A','gerald.olenko@tinycollege.edu','Senior Lecturer','Ph.D'),(195,'PSYCH','Wabash','Geoff','B','geoff.wabash@tinycollege.edu','Assistant Professor','Ph.D'),(199,'EDU','Smithson','Darlene','M','darlene.smithson@tinycollege.edu','Associate Professor','Ph.D'),(205,'CHEM','Joenbrood','Delbert','K','delbert.joenbrood@tinycollege.edu','Professor','Ph.D'),(209,'CIS','Jones','Annelise',NULL,'annelise.jones@tinycollege.edu','Lecturer','Ph.D'),(222,'ENGL','Bawangi','Travis','B','travis.bawangi@tinycollege.edu','Senior Lecturer','Ph.D'),(228,'CIS','Pratt','Gerald','L','gerald.pratt@tinycollege.edu','Assistant Professor','Ph.D'),(230,'ACCT','Williamson','Angie','H','angie.williamson@tinycollege.edu','Associate Professor','Ph.D'),(297,'MATH','Frommer','James','J','james.frommer@tinycollege.edu','Professor','Ph.D'),(299,'ECON/FIN','Yoisaki','Kanade',NULL,'yoisaki.kanade@tinycollege.edu','Lecturer','DBA'),(301,'ACCT','Smith','Olette','K','smith.olette@tinycollege.edu','Senior Lecturer','DBA'),(311,'SOC','Brown','James','G','nancy.hamilton@tinycollege.edu','Assistant Professor','Ph.D'),(325,'ENGL','Brian','Amy','B','steve.roberts@tinycollege.edu','Associate Professor','Ph.D'),(342,'SOC','Orlando','Myron',NULL,'linda.kim@tinycollege.edu','Professor','Ph.D'),(387,'BIOL','Olowski','Paul','F','mark.clark@tinycollege.edu','Lecturer','Ph.D'),(401,'HIST','Smith','Kathy','W','smith.kathy@tinycollege.edu','Senior Lecturer','Ph.D'),(425,'ECON/FIN','Dunne','Leona','K','dunne.leona@tinycollege.edu','Assistant Professor','Ph.D'),(435,'ART','Ramas','Alfred','A','ramas.alfred@tinycollege.edu','Associate Professor','Ph.D'),(450,'PSYCH','Harris','Amy','A','amy.harris@tinycollege.edu','Professor','Ph.D'),(451,'PSYCH','Adams','Brian','B','brian.adams@tinycollege.edu','Associate Professor','Ph.D'),(452,'PSYCH','Bennett','Catherine','C','catherine.bennett@tinycollege.edu','Assistant Professor','Ph.D'),(453,'PSYCH','Murphy','David','D','david.murphy@tinycollege.edu','Lecturer','Ph.D'),(454,'PSYCH','Foster','Emily','E','emily.foster@tinycollege.edu','Senior Lecturer','Ph.D'),(455,'ART','Lopez','Grace','F','grace.lopez@tinycollege.edu','Professor','MFA'),(456,'ART','Mitchell','Henry','G','henry.mitchell@tinycollege.edu','Associate Professor','MFA'),(457,'ART','Wright','Isabella','H','isabella.wright@tinycollege.edu','Assistant Professor','MFA'),(458,'ART','King','James','I','james.king@tinycollege.edu','Lecturer','MFA'),(459,'ART','Scott','Karen','J','karen.scott@tinycollege.edu','Senior Lecturer','MFA'),(460,'MUS','Hill','Laura','K','laura.hill@tinycollege.edu','Professor','DMA'),(461,'MUS','Green','Michael','L','michael.green@tinycollege.edu','Associate Professor','DMA'),(462,'MUS','Edwards','Natalie','M','natalie.edwards@tinycollege.edu','Assistant Professor','DMA'),(463,'MUS','Clark','Oliver','N','oliver.clark@tinycollege.edu','Lecturer','DMA'),(464,'MUS','Lewis','Paula','O','paula.lewis@tinycollege.edu','Senior Lecturer','DMA'),(465,'MATH','Nelson','Ethan','P','ethan.nelson@tinycollege.edu','Professor','Ph.D'),(466,'MATH','Carter','Fiona','Q','fiona.carter@tinycollege.edu','Associate Professor','Ph.D'),(467,'MATH','Roberts','George','R','george.roberts@tinycollege.edu','Assistant Professor','Ph.D'),(468,'MATH','Phillips','Hannah','S','hannah.phillips@tinycollege.edu','Lecturer','Ph.D'),(469,'MATH','Campbell','Ian','T','ian.campbell@tinycollege.edu','Senior Lecturer','Ph.D'),(470,'EDU','Stewart','Jack','U','jack.stewart@tinycollege.edu','Professor','Ed.D'),(471,'EDU','Murphy','Kate','V','kate.murphy@tinycollege.edu','Associate Professor','Ed.D'),(472,'EDU','Collins','Liam','W','liam.collins@tinycollege.edu','Assistant Professor','Ed.D'),(473,'EDU','Richardson','Mia','X','mia.richardson@tinycollege.edu','Lecturer','Ed.D'),(474,'EDU','Cox','Noah','Y','noah.cox@tinycollege.edu','Senior Lecturer','Ed.D'),(475,'MKT/MGT','Morgan','Olivia','Z','olivia.morgan@tinycollege.edu','Professor','MBA'),(476,'MKT/MGT','Bell','Patrick','A','patrick.bell@tinycollege.edu','Associate Professor','MBA'),(477,'MKT/MGT','Bailey','Quinn','B','quinn.bailey@tinycollege.edu','Assistant Professor','MBA'),(478,'MKT/MGT','Cooper','Rachel','C','rachel.cooper@tinycollege.edu','Lecturer','MBA'),(479,'MKT/MGT','Reed','Samuel','D','samuel.reed@tinycollege.edu','Senior Lecturer','MBA');
/*!40000 ALTER TABLE `professor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `room`
--

DROP TABLE IF EXISTS `room`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `room` (
  `ROOM_CODE` varchar(8) NOT NULL,
  `ROOM_TYPE` varchar(20) DEFAULT NULL,
  `BLDG_CODE` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ROOM_CODE`),
  KEY `room_ibfk_2` (`BLDG_CODE`),
  CONSTRAINT `room_ibfk_1` FOREIGN KEY (`BLDG_CODE`) REFERENCES `building` (`BLDG_CODE`),
  CONSTRAINT `room_ibfk_2` FOREIGN KEY (`BLDG_CODE`) REFERENCES `building` (`BLDG_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `room`
--

LOCK TABLES `room` WRITE;
/*!40000 ALTER TABLE `room` DISABLE KEYS */;
INSERT INTO `room` VALUES ('ART101','Art studio','Art Sci'),('BIOL111','Classroom','Applied Sci'),('BIOL202','Biology lab','Science'),('BUS200','Classroom','Business'),('BUS252','Classroom','Business'),('BUS311','Classroom','Business'),('CHEM101 ','Chemistry lab','Science'),('CHEM102','Chemistry lab','Science'),('CIS101','Classroom','Engineering'),('CIS102','Classroom','Engineering'),('DRE155','Lecture hall','Science'),('EDUC201','Classroom','Education'),('EDUC212','Lecture hall','Education'),('EDUC222','Classroom','Education'),('ENGL101','Classroom','Art Sci'),('ENGL105','Classroom','Art Sci'),('ENGL201','Lecture hall','Art Sci'),('ENGL301','Classroom','Art Sci'),('HIST101','Classroom','Art Sci'),('KLR200','Computer lab','Engineering'),('KLR209','Computer lab','Engineering'),('KLR211','Computer lab','Applied Sci'),('LAW101','Classroom','Art Sci'),('MATH201','Classroom','Science'),('MUS101','Music hall','Art Sci'),('PHYS101','Physics lab','Science'),('PHYS102','Physics lab','Science'),('PSYCH101','Classroom','Art Sci'),('SCI101','Classroom','Science'),('SCI102','Classroom','Science'),('SCI111','Lecture hall','Applied Sci'),('SCI202','Lecture hall','Science'),('SOC101','Classroom','Art Sci'),('SOC202','Lecture hall','Art Sci'),('SOC203','Lecture hall','Art Sci');
/*!40000 ALTER TABLE `room` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `school`
--

DROP TABLE IF EXISTS `school`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `school` (
  `SCHOOL_CODE` varchar(8) NOT NULL,
  `SCHOOL_NAME` varchar(50) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  PRIMARY KEY (`SCHOOL_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  CONSTRAINT `school_ibfk_1` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`),
  CONSTRAINT `school_ibfk_2` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `school`
--

LOCK TABLES `school` WRITE;
/*!40000 ALTER TABLE `school` DISABLE KEYS */;
INSERT INTO `school` VALUES ('A&SCI','Art & Science school',435),('APSCI','Applied Science school',195),('BUS','Business school',106),('EDU','Education school',199),('ENGINEER','Engineer School',162),('SCI','Science School',297);
/*!40000 ALTER TABLE `school` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `semester`
--

DROP TABLE IF EXISTS `semester`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `semester` (
  `SEMESTER_CODE` char(10) NOT NULL,
  `SEMESTER_YEAR` year DEFAULT NULL,
  `SEMESTER_TERM` varchar(20) DEFAULT NULL,
  `SEMESTER_START_DATE` date DEFAULT NULL,
  `SEMESTER_END_DATE` date DEFAULT NULL,
  PRIMARY KEY (`SEMESTER_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `semester`
--

LOCK TABLES `semester` WRITE;
/*!40000 ALTER TABLE `semester` DISABLE KEYS */;
INSERT INTO `semester` VALUES ('FAL2023',2023,'Fall','2023-09-01','2023-12-15'),('FAL2024',2024,'Fall','2024-09-01','2024-12-15'),('FAL2025',2025,'Fall','2025-09-01','2025-12-15'),('SPR2023',2023,'Spring','2023-01-15','2023-05-15'),('SPR2024',2024,'Spring','2024-01-15','2024-05-15'),('SPR2025',2025,'Spring','2025-01-15','2025-05-15'),('SUM2023',2023,'Summer','2023-06-01','2023-08-15'),('SUM2024',2024,'Summer','2024-06-01','2024-08-15'),('SUM2025',2025,'Summer','2025-06-01','2025-08-15');
/*!40000 ALTER TABLE `semester` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `STU_NUM` int NOT NULL,
  `STU_LNAME` varchar(15) DEFAULT NULL,
  `STU_FNAME` varchar(15) DEFAULT NULL,
  `STU_INITIAL` varchar(1) DEFAULT NULL,
  `DEPT_CODE` varchar(10) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  `STU_EMAIL` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`STU_NUM`),
  KEY `student_ibfk_2` (`DEPT_CODE`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`),
  CONSTRAINT `student_ibfk_2` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (321373,'Thompson','Ethan','U','PHYS',107,'ethan.thompson@tinycollege.edu'),(321400,'Jones','David','E','PHYS',NULL,'david.jones@tinycollege.edu'),(321452,'Bowser','William','C','BIOL',205,'william.bowser@tinycollege.edu'),(321474,'White','Isabella','V','CHEM',NULL,'isabella.white@tinycollege.edu'),(321475,'Harris','Alexander','W','BIOL',387,'alexander.harris@tinycollege.edu'),(321476,'Sanchez','Mia','X','EDU',NULL,'mia.sanchez@tinycollege.edu'),(321480,'Smith','John','A','CIS',NULL,'john.smith@tinycollege.edu'),(321497,'Johnson','Emily','B','MATH',469,'emily.johnson@tinycollege.edu'),(321521,'Brown','Jessica','D','HIST',NULL,'jessica.brown@tinycollege.edu'),(321556,'Williams','Michael','C','ENGL',NULL,'michael.williams@tinycollege.edu'),(321559,'Martinez','James','G','BIOL',NULL,'james.martinez@tinycollege.edu'),(321560,'Rodriguez','Laura','H','PSYCH',450,'laura.rodriguez@tinycollege.edu'),(321561,'Davis','Daniel','I','CIS',NULL,'daniel.davis@tinycollege.edu'),(321562,'Lopez','Ashley','J','MATH',465,'ashley.lopez@tinycollege.edu'),(321563,'Gonzalez','Christopher','K','ENGL',NULL,'christopher.gonzalez@tinycollege.edu'),(321564,'Wilson','Amanda','L','HIST',NULL,'amanda.wilson@tinycollege.edu'),(321565,'Anderson','Matthew','M','PHYS',NULL,'matthew.anderson@tinycollege.edu'),(321570,'Martin','Olivia','R','MATH',NULL,'olivia.martin@tinycollege.edu'),(321589,'Garcia','Sarah','F','CHEM',119,'sarah.garcia@tinycollege.edu'),(321666,'Thomas','Megan','N','CHEM',NULL,'megan.thomas@tinycollege.edu'),(321667,'Taylor','Joshua','O','BIOL',NULL,'joshua.taylor@tinycollege.edu'),(321668,'Moore','Hannah','P','SOC',NULL,'hannah.moore@tinycollege.edu'),(321669,'Jackson','Jacob','Q','CIS',NULL,'jacob.jackson@tinycollege.edu'),(321671,'Lee','Andrew','S','ENGL',NULL,'andrew.lee@tinycollege.edu'),(321679,'Lewis','Benjamin','A','ENGL',NULL,'benjamin.lewis@tinycollege.edu'),(321772,'Perez','Sophia','T','HIST',NULL,'sophia.perez@tinycollege.edu'),(321781,'Walker','Elijah','C','PHYS',NULL,'elijah.walker@tinycollege.edu'),(321782,'Young','Abigail','D','ACCT',NULL,'abigail.young@tinycollege.edu'),(321877,'Clark','Logan','Y','CIS',NULL,'logan.clark@tinycollege.edu'),(321880,'Robinson','Ava','B','HIST',NULL,'ava.robinson@tinycollege.edu'),(321978,'Ramirez','Emma','Z','MATH',NULL,'emma.ramirez@tinycollege.edu'),(324257,'Smithson','Anne','K','CIS',222,'anne.smithson@tinycollege.edu'),(324258,'Brewer','Juliette','','ACCT',228,'juliette.brewer@tinycollege.edu'),(324269,'Oblonski','Walter','H','CIS',222,'walter.oblonski@tinycollege.edu'),(324273,'Smith','John','D','ENGL',199,'john.d.smith@tinycollege.edu'),(324274,'Katinga','Raphael','P','ACCT',228,'raphael.katinga@tinycollege.edu'),(324291,'Robertson','Gerald','T','EDU',311,'gerald.robertson@tinycollege.edu'),(324299,'Smith','John','B','ACCT',230,'john.smith@tinycollege.edu'),(324339,'James','Moby',NULL,'EDU',NULL,'james.moby@tinycollege.edu'),(325667,'Tiara','Nelson','A','ACCT',NULL,'tiara.nelson@tinycollege.edu'),(325778,'Noel','Maria','L','CIS',228,'noel.maria@tinycollege.edu'),(326783,'Smith','John','A','ECON/FIN',NULL,'john.smith@tinycollege.edu'),(326784,'Johnson','Emma','B','ECON/FIN',425,'emma.johnson@tinycollege.edu'),(326785,'Brown','Michael','C','ECON/FIN',NULL,'michael.brown@tinycollege.edu'),(326786,'Taylor','Olivia','D','ECON/FIN',NULL,'olivia.taylor@tinycollege.edu'),(326787,'Anderson','David','E','ECON/FIN',NULL,'david.anderson@tinycollege.edu'),(326788,'Martinez','Sophia','F','MKT/MGT',479,'sophia.martinez@tinycollege.edu'),(326789,'Hernandez','James','G','MKT/MGT',477,'james.hernandez@tinycollege.edu'),(326790,'Moore','Isabella','H','MKT/MGT',NULL,'isabella.moore@tinycollege.edu'),(326791,'Wilson','Benjamin','I','MKT/MGT',NULL,'benjamin.wilson@tinycollege.edu'),(326792,'Garcia','Amelia','J','MKT/MGT',NULL,'amelia.garcia@tinycollege.edu');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'tinycollege'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-05-23 18:38:22
