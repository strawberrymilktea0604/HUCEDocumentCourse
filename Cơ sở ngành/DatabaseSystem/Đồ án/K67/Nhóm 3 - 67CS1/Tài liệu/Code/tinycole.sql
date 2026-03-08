-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: chapter5
-- ------------------------------------------------------
-- Server version	8.0.34

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
  `BLDG_CODE` int NOT NULL,
  `BLDG_NAME` char(45) DEFAULT NULL,
  `BLDG_LOCATION` char(45) DEFAULT NULL,
  PRIMARY KEY (`BLDG_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `building`
--

LOCK TABLES `building` WRITE;
/*!40000 ALTER TABLE `building` DISABLE KEYS */;
INSERT INTO `building` VALUES (1234,'A1','FIRST'),(1235,'A2','SECOND'),(1236,'H1','THIRD'),(1237,'H2','FORTH');
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
  `ROOM_CODE` char(45) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  `SEMESTER_CODE` int DEFAULT NULL,
  PRIMARY KEY (`CLASS_CODE`),
  KEY `CRS_CODE` (`CRS_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  KEY `ROOM_CODE` (`ROOM_CODE`),
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
INSERT INTO `class` VALUES ('10012','ACCT-211','1','MWF 8:00-8:50 a.m.','BUS311',105,123456),('10013','ACCT-211','2','MWF 9:00-9:50 a.m.','BUS200',105,123457),('10014','ACCT-211','3','TTh 2:30-3:45 p.m.','BUS252',342,123456),('10015','ACCT-212','1','MWF 10:00-10:50 a.m.','BUS311',301,123457),('10016','ACCT-212','2','Th 6:00-8:40 p.m.','BUS252',301,123458),('10017','CIS-220','1','MWF 9:00-9:50 a.m.','KLR209',228,123456),('10018','CIS-220','2','MWF 9:00-9:50 a.m.','KLR211',114,123457),('10019','CIS-220','3','MWF 10:00-10:50 a.m.','KLR209',228,123456),('10020','CIS-420','1','W 6:00-8:40 p.m.','KLR209',162,123458),('10021','QM-261','1','MWF 8:00-8:50 a.m.','KLR200',114,123458),('10022','QM-261','2','TTh 1:00-2:15 p.m.','KLR200',114,123456),('10023','QM-362','1','MWF 11:00-11:50 a.m.','KLR200',162,123459),('10024','QM-362','2','TTh 2:30-3:45 p.m.','KLR200',162,123459),('10025','ART-123','3','M 6:00-8:40 p.m.','LOL111',301,123456),('10026','ART-113','3','F 1:00-8:40 p.m.','KKK100',335,123457),('10027','ENG-001','1','W 6:00-9:40 p.m.','KKO523',401,123458),('10028','ENG-002','1','S 7:00-8:40 p.m.','ADF101',425,123459),('10029','MATH-243','3','SA 6:00-8:40 a.m.','LOL111',297,123456);
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
  `CRS_DESCRIPTION` varchar(35) DEFAULT NULL,
  `CRS_CREDIT` decimal(8,0) DEFAULT NULL,
  `CRS_TITLE` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CRS_CODE`),
  KEY `DEPT_CODE` (`DEPT_CODE`),
  CONSTRAINT `course_ibfk_1` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course`
--

LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES ('ACCT-211','ACCT','Accounting I',3,'ACCOUNTING'),('ACCT-212','ACCT','Accounting II',3,'ACCOUNTING'),('ART-113','ART','Lost to the Allies',5,'Art'),('ART-123','ART','Conquer Europe',3,'Art'),('BIOL-113','BIOL','Weeds And Flowers',2,'Biology'),('CIS-220','CIS','Intro. to Microcomputing',3,'IT'),('CIS-420','CIS','Database Design and Implementation',4,'IT'),('ENG-001','ENG','English I',1,'English'),('ENG-002','ART','English II',2,'English'),('MATH-243','MATH','Mathematics for Managers',3,'Math'),('PSYCH-153','PSYCH','Minds of human',3,'Psychology'),('QM-261','CIS','Intro. to Statistics',3,'Statistics'),('QM-362','CIS','Statistical Applications',4,'Statistics'),('SOC-123','ENG','Social Skills',4,'Sociology');
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
  KEY `SCHOOL_CODE` (`SCHOOL_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  CONSTRAINT `department_ibfk_1` FOREIGN KEY (`SCHOOL_CODE`) REFERENCES `school` (`SCHOOL_CODE`),
  CONSTRAINT `department_ibfk_2` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`),
  CONSTRAINT `department_ibfk_3` FOREIGN KEY (`SCHOOL_CODE`) REFERENCES `school` (`SCHOOL_CODE`),
  CONSTRAINT `department_ibfk_4` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('ACCT','Accounting','BUS',114),('ART','Fine Arts','A&SCI',435),('BIOL','Biology','A&SCI',387),('CIS','Computer Info. Systems','BUS',209),('ECON/FIN','Economics/Finance','BUS',299),('ENG','English','A&SCI',160),('HIST','History','A&SCI',103),('MATH','Mathematics','A&SCI',297),('MKT/MGT','Marketing/Management','BUS',106),('PSYCH','Psychology','A&SCI',195),('SOC','Sociology','A&SCI',342);
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enroll`
--

DROP TABLE IF EXISTS `enroll`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enroll` (
  `CLASS_CODE` varchar(5) DEFAULT NULL,
  `STU_NUM` int DEFAULT NULL,
  `ENROLL_GRADE` varchar(50) DEFAULT NULL,
  `ENROLL_DATE` char(45) DEFAULT NULL,
  KEY `CLASS_CODE` (`CLASS_CODE`),
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
INSERT INTO `enroll` VALUES ('10021',324257,'C','8-DECEMBER-25'),('10014',324257,'B','6-SEPTEMBER-24'),('10018',321452,'A','20-FEBRUARY-23'),('10018',324257,'B','6-DECEMBER-24'),('10021',321452,'C','8-DECEMBER-25'),('10021',324257,'C','4-JULY-23');
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
  `PROF_SPECIALTY` char(45) DEFAULT NULL,
  `PROF_RANK` char(45) DEFAULT NULL,
  `PROF_LNAME` char(45) DEFAULT NULL,
  `PROF_FNAME` char(45) DEFAULT NULL,
  `PROF_INITIAL` char(45) DEFAULT NULL,
  `PROF_EMAIL` char(45) DEFAULT NULL,
  PRIMARY KEY (`PROF_NUM`),
  KEY `DEPT_CODE` (`DEPT_CODE`),
  CONSTRAINT `professor_ibfk_1` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `professor`
--

LOCK TABLES `professor` WRITE;
/*!40000 ALTER TABLE `professor` DISABLE KEYS */;
INSERT INTO `professor` VALUES (103,'HIST','HISTORY','DOCTOR','ALAN','WALKER','A','ALW@GMAIL.COM'),(104,'ENG','ENGLISH','MASTER','TAYLOR','SWITCH','T','TSW@GMAIL.COM'),(105,'ACCT','ACCOUTING','DOCTOR','LULIAN','ASA','J','LAS@GMAIL.COM'),(106,'MKT/MGT','MARKETING','DOCTOR','EMMA','LUTAS','E','EML@GMAIL.COM'),(110,'BIOL','BIOLOGY','MASTER','JOHN','CENA','J','JCN@GMAIL.COM'),(114,'ACCT','ACCOUTING','DOCTOR','SELENA','GOMEZ','S','SLM@GMAIL.COM'),(155,'MATH','CALCULATE','MASTER','ROCK','LESNAR','J','JLR@GMAIL.COM'),(160,'ENG','ENGLISH','MASTER','ALPHA','SALAND','A','ASD@GMAIL.COM'),(162,'CIS','WEB PROGRAM','MASTER','SIMON','ALAN','S','SAN@GMAIL.COM'),(191,'MKT/MGT','MARKETING','DOCTOR','JACK','WHILSEAR','J','JKS@GMAIL.COM'),(195,'PSYCH','PSYCHO','DOCTOR','SMITH','ROSE','S','SRE@GMAIL.COM'),(209,'CIS','IT','DOCTOR','JOHN','OSEA','J','JOA@GMAIL.COM'),(228,'CIS','WEB PROGRAM','DOCTOR','JAVAN','CATHERIA','J','JVA#GMAIL.COM'),(297,'MATH','MEASURE','DOCTOR','PAUL','SCHOLES','P','PSS@GMAIL.COM'),(299,'ECON/FIN','ECONOMY','MASTER','HAN','KAWA','H','HKA@GMAIL.COM'),(301,'ACCT','ACCOUTING','DOCTOR','AN','VU','A','AVU@GMAIL.COM'),(335,'ENG','ENGLISH','DOCTOR','TRUNG','NGUYEN','T','TNN@GMAIL.COM'),(342,'SOC','SOCIETY','MASTER','LONG','TA','L','LTA@GMAIL.COM'),(387,'BIOL','BIOLOGY','DOCTOR','AN','NGUYEN','A','ANN@GMAIL.COM'),(401,'HIST','HISTORY','MASTER','THUY','TRAN','T','TTN@GMAIL.COM'),(425,'ECON/FIN','ECONOMY','DOCTOR','DUONG','NGUYEN','D','DNN@GMAIL.COM'),(435,'ART','DRAW','MASTER','TRIEU','DANG','T','TDG@GMAIL.COM');
/*!40000 ALTER TABLE `professor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `room`
--

DROP TABLE IF EXISTS `room`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `room` (
  `ROOM_CODE` char(45) NOT NULL,
  `ROOM_TYPE` char(45) DEFAULT NULL,
  `BLDG_CODE` int DEFAULT NULL,
  PRIMARY KEY (`ROOM_CODE`),
  KEY `BLDG_CODE` (`BLDG_CODE`),
  CONSTRAINT `room_ibfk_1` FOREIGN KEY (`BLDG_CODE`) REFERENCES `building` (`BLDG_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `room`
--

LOCK TABLES `room` WRITE;
/*!40000 ALTER TABLE `room` DISABLE KEYS */;
INSERT INTO `room` VALUES ('ADF101','STORAGE',1237),('BUS200','CLASS',1234),('BUS252','LAB',1236),('BUS311','CLASS',1234),('DRE155','LAB',1235),('GGQ150','CLASS',1235),('KKK100','CLASS',1234),('KKO523','CLASS',1234),('KLR200','LIBRARY',1237),('KLR209','CLASS',1234),('KLR211','LAB',1237),('LOL111','LAB',1236);
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
  `SCHOOL_NAME` char(45) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  PRIMARY KEY (`SCHOOL_CODE`),
  KEY `PROF_NUM` (`PROF_NUM`),
  CONSTRAINT `school_ibfk_1` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `school`
--

LOCK TABLES `school` WRITE;
/*!40000 ALTER TABLE `school` DISABLE KEYS */;
INSERT INTO `school` VALUES ('A&SCI','Art & Science',110),('BUS','Business',104),('NAEH','Economic',114),('NASS','Computer Science',106);
/*!40000 ALTER TABLE `school` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `semester`
--

DROP TABLE IF EXISTS `semester`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `semester` (
  `SEMESTER_CODE` int NOT NULL,
  `SEMESTER_YEAR` int DEFAULT NULL,
  `SEMESTER_TERM` char(255) DEFAULT NULL,
  `SEMESTER_START_DATE` char(255) DEFAULT NULL,
  `SEMESTER_END_DATE` char(255) DEFAULT NULL,
  PRIMARY KEY (`SEMESTER_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `semester`
--

LOCK TABLES `semester` WRITE;
/*!40000 ALTER TABLE `semester` DISABLE KEYS */;
INSERT INTO `semester` VALUES (123456,2023,'2023_2024','8-SEPTEMBER-2023','10-MAY-2024'),(123457,2025,'2024_2025','15-SEPTEMBER-2024','10-MAY-2025'),(123458,2024,'2023_2024','20-FEBRUARY-2023','6-DECEMBER-2024'),(123459,2022,'2022_2023','8-JULY-2022','10-OCTOBER-2023');
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
  `DEPT_CODE` varchar(45) DEFAULT NULL,
  `STU_LNAME` varchar(45) DEFAULT NULL,
  `STU_FNAME` varchar(45) DEFAULT NULL,
  `STU_INITIAL` varchar(10) DEFAULT NULL,
  `STU_EMAIL` varchar(45) DEFAULT NULL,
  `PROF_NUM` int DEFAULT NULL,
  PRIMARY KEY (`STU_NUM`),
  KEY `PROF_NUM` (`PROF_NUM`),
  KEY `DEPT_CODE` (`DEPT_CODE`),
  CONSTRAINT `student_ibfk_2` FOREIGN KEY (`DEPT_CODE`) REFERENCES `department` (`DEPT_CODE`),
  CONSTRAINT `student_ibfk_3` FOREIGN KEY (`PROF_NUM`) REFERENCES `professor` (`PROF_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (124235,'MKT/MGT','LIONEL','MESSI','L','GOAT@GMAIL.COM',191),(124522,'SOC','LEBRON','JAMES','H','BALL@GMAIL.COM',342),(213211,'BIOL','ANDRE','ONANA','A','ADG@GMAIL.COM',110),(213212,'CIS','DAVID','DEGEA','D','DG1@GMAIL.COM',162),(213213,'CIS','VAN','HAWAN','V','VGD@GMAIL.COM',162),(213214,'ACCT','THY','GUNVNO','T','GVT@GMAIL.COM',105),(213215,'MATH','KAY','JORDAN','K','JDK@GMAIL.COM',155),(252631,'PSYCH','BARRACK','OBAMA','A','NIG@GMAIL.COM',195),(321452,'ENG','HARRY','MAGUIRE','H','HG5@GMAIL.COM',104),(324257,'HIST','CRISTIANO','RONALDO','C','CR7@GMAIL.COM',103);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-12-07 13:05:31
