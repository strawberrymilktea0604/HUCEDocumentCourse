-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: transco
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
-- Table structure for table `assignment`
--

DROP TABLE IF EXISTS `assignment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `assignment` (
  `ASGM_CODE` int NOT NULL,
  `CUS_ID` int DEFAULT NULL,
  `BASE_CODE` int DEFAULT NULL,
  `DRIVER_ID` int DEFAULT NULL,
  `ASGM_ORDER_DATE` date DEFAULT NULL,
  `RATE_APPLY` float DEFAULT NULL,
  `ASGM_WEIGHT` float DEFAULT NULL,
  `ASGM_DESTINATION` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ASGM_CODE`),
  KEY `CUS_ID` (`CUS_ID`),
  KEY `BASE_CODE` (`BASE_CODE`),
  KEY `DRIVER_ID` (`DRIVER_ID`),
  KEY `RATE_APPLY` (`RATE_APPLY`),
  CONSTRAINT `assignment_ibfk_1` FOREIGN KEY (`CUS_ID`) REFERENCES `customer` (`CUS_ID`),
  CONSTRAINT `assignment_ibfk_2` FOREIGN KEY (`BASE_CODE`) REFERENCES `base` (`BASE_CODE`),
  CONSTRAINT `assignment_ibfk_3` FOREIGN KEY (`DRIVER_ID`) REFERENCES `driver` (`DRIVER_ID`),
  CONSTRAINT `assignment_ibfk_4` FOREIGN KEY (`RATE_APPLY`) REFERENCES `rate` (`RATE_APPLY`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `assignment`
--

LOCK TABLES `assignment` WRITE;
/*!40000 ALTER TABLE `assignment` DISABLE KEYS */;
INSERT INTO `assignment` VALUES (1,3,502,4,'2023-11-20',4.5,51.6,'KOR'),(2,1,501,1,'2023-09-21',5.7,43.7,'VIE'),(3,5,504,2,'2023-04-20',4.5,10,'CAM'),(4,4,503,5,'2023-03-23',8.5,46.3,'LAO'),(5,6,501,4,'2023-03-23',5.7,75.3,'POR'),(6,2,504,3,'2023-05-19',8.5,21.4,'USA'),(7,8,506,6,'2023-10-20',4.5,24.6,'FRA');
/*!40000 ALTER TABLE `assignment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `base`
--

DROP TABLE IF EXISTS `base`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `base` (
  `BASE_CODE` int NOT NULL,
  `BASE_CITY` varchar(20) DEFAULT NULL,
  `BASE_STATE` varchar(2) DEFAULT NULL,
  `BASE_AREA_CODE` varchar(3) DEFAULT NULL,
  `BASE_PHONE` varchar(8) DEFAULT NULL,
  `BASE_MANAGER` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`BASE_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `base`
--

LOCK TABLES `base` WRITE;
/*!40000 ALTER TABLE `base` DISABLE KEYS */;
INSERT INTO `base` VALUES (501,'Murfreesboro','TN','615','123-4567','Andrea D. Gallager'),(502,'Lexington','KY','568','234-5678','George H. Delarosa'),(503,'Cape Girardeau','MO','456','345-6789','Maria J. Talindo'),(504,'Dalton','GA','901','456-7890','Peter F. McAvee'),(505,'Noi Bai','HN','717','342-2524','Nguyen Thanh Trung'),(506,'Faker','SE','444','155-3463','Lee Sang Hyeok'),(507,'Valve','CA','446','345-5235','Ngol'),(508,'Riot','DN','925','456-2423','Lu ngu');
/*!40000 ALTER TABLE `base` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `CUS_ID` int NOT NULL,
  `CUS_FNAME` varchar(15) DEFAULT NULL,
  `CUS_LNAME` varchar(15) DEFAULT NULL,
  `CUS_PHONE` varchar(8) DEFAULT NULL,
  PRIMARY KEY (`CUS_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Julius','Ceaser','452-2352'),(2,'Adolf','Hitler','124-2115'),(3,'Napoleon','Bonaparte','524-1212'),(4,'Hannibal','Byzantine','453-7867'),(5,'Blood','Crips','977-3266'),(6,'Alexander','The Great','522-5226'),(7,'No','Order','124-5678'),(8,'Odell','Rashford','152-5223');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `driver`
--

DROP TABLE IF EXISTS `driver`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `driver` (
  `DRIVER_ID` int NOT NULL,
  `DRIVER_FNAME` varchar(15) DEFAULT NULL,
  `DRIVER_LNAME` varchar(15) DEFAULT NULL,
  `TRUCK_NUM` varchar(10) DEFAULT NULL,
  `DRIVER_PHONE` varchar(8) DEFAULT NULL,
  `SPVRS_ID` int DEFAULT NULL,
  PRIMARY KEY (`DRIVER_ID`),
  UNIQUE KEY `TRUCK_NUM` (`TRUCK_NUM`),
  CONSTRAINT `driver_ibfk_1` FOREIGN KEY (`TRUCK_NUM`) REFERENCES `truck` (`TRUCK_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `driver`
--

LOCK TABLES `driver` WRITE;
/*!40000 ALTER TABLE `driver` DISABLE KEYS */;
INSERT INTO `driver` VALUES (1,'Dominica','Kirabo','1001','252-3252',NULL),(2,'Olly','Winifred','1011','436-3261',1),(3,'Teofila','Maite','1004','262-2552',1),(4,'Basilius','Seydou','1007','976-4623',1),(5,'Parthalán','Landen','1009','768-4367',NULL),(6,'Františka','Siothrún','1014','346-8754',5),(7,'Berach','Umida','1006','252-7343',5),(8,'Inga','Yulia','1018','675-4584',5),(9,'Sunil','Trishna','1005','124-6964',10),(10,'Theo','Dimitrije','1015','346-5685',NULL);
/*!40000 ALTER TABLE `driver` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `maintenance`
--

DROP TABLE IF EXISTS `maintenance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `maintenance` (
  `MTNCE_CODE` int NOT NULL,
  `MTNCE_DATE` date DEFAULT NULL,
  `MTNCE_DESC` varchar(50) DEFAULT NULL,
  `MTNCE_COST` float DEFAULT NULL,
  PRIMARY KEY (`MTNCE_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `maintenance`
--

LOCK TABLES `maintenance` WRITE;
/*!40000 ALTER TABLE `maintenance` DISABLE KEYS */;
INSERT INTO `maintenance` VALUES (100,'2024-02-23','Bao duong quy 1',5000),(101,'2024-05-23','Bao duong quy 2',4750),(102,'2024-08-23','Bao duong quy 3',6235),(103,'2024-12-23','Bao duong quy 4',2361);
/*!40000 ALTER TABLE `maintenance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rate`
--

DROP TABLE IF EXISTS `rate`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `rate` (
  `RATE_APPLY` float NOT NULL,
  `RATE_DESC` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`RATE_APPLY`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rate`
--

LOCK TABLES `rate` WRITE;
/*!40000 ALTER TABLE `rate` DISABLE KEYS */;
INSERT INTO `rate` VALUES (4.5,'duong ngan'),(5.7,'duong dai'),(8.5,'duong kho van chuyen');
/*!40000 ALTER TABLE `rate` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `truck`
--

DROP TABLE IF EXISTS `truck`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `truck` (
  `TRUCK_NUM` varchar(10) NOT NULL,
  `BASE_CODE` int DEFAULT NULL,
  `TYPE_CODE` int NOT NULL,
  `TRUCK_MILES` float DEFAULT NULL,
  `TRUCK_SERIAL_NUM` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`TRUCK_NUM`),
  KEY `BASE_CODE` (`BASE_CODE`),
  KEY `TYPE_CODE` (`TYPE_CODE`),
  CONSTRAINT `truck_ibfk_1` FOREIGN KEY (`BASE_CODE`) REFERENCES `base` (`BASE_CODE`),
  CONSTRAINT `truck_ibfk_2` FOREIGN KEY (`TYPE_CODE`) REFERENCES `type` (`TYPE_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `truck`
--

LOCK TABLES `truck` WRITE;
/*!40000 ALTER TABLE `truck` DISABLE KEYS */;
INSERT INTO `truck` VALUES ('1001',501,1,32123.5,'AA-322-12212-W11'),('1002',502,1,76984.3,'AC-342-22134-Q23'),('1003',501,2,12346.6,'AC-445-78656-Z99'),('1004',NULL,1,2894.3,'WQ-112-23144-T34'),('1005',503,2,45673.1,'FR-998-32245-W12'),('1006',501,2,193246,'AD-456-00845-R45'),('1007',502,3,32012.3,'AA-341-96573-Z84'),('1008',502,3,44213.6,'DR-559-22189-D33'),('1009',503,2,10932.9,'DE-887-98456-E94'),('1010',504,1,13463.6,'BS-322-12512-W51'),('1011',508,1,76252.1,'AC-363-24252-C23'),('1012',508,2,12353.2,'AE-242-78656-Z91'),('1013',NULL,1,281,'GO-246-12144-T34'),('1014',507,2,4551,'LD-254-21435-B52'),('1015',NULL,2,125356,'AK-456-04225-R45'),('1016',506,3,39852.3,'US-341-24252-Z54'),('1017',504,3,77263.6,'OQ-559-22189-D33'),('1018',505,2,56632.9,'LE-254-64673-E94');
/*!40000 ALTER TABLE `truck` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `truck_mtnce`
--

DROP TABLE IF EXISTS `truck_mtnce`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `truck_mtnce` (
  `TRUCK_NUM` varchar(10) NOT NULL,
  `MTNCE_CODE` int NOT NULL,
  PRIMARY KEY (`TRUCK_NUM`,`MTNCE_CODE`),
  KEY `MTNCE_CODE` (`MTNCE_CODE`),
  CONSTRAINT `truck_mtnce_ibfk_1` FOREIGN KEY (`TRUCK_NUM`) REFERENCES `truck` (`TRUCK_NUM`),
  CONSTRAINT `truck_mtnce_ibfk_2` FOREIGN KEY (`MTNCE_CODE`) REFERENCES `maintenance` (`MTNCE_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `truck_mtnce`
--

LOCK TABLES `truck_mtnce` WRITE;
/*!40000 ALTER TABLE `truck_mtnce` DISABLE KEYS */;
INSERT INTO `truck_mtnce` VALUES ('1001',100),('1002',100),('1003',100),('1013',100),('1014',100),('1018',100),('1004',101),('1009',101),('1010',101),('1014',101),('1018',101),('1005',102),('1008',102),('1010',102),('1016',102),('1018',102),('1004',103),('1006',103),('1015',103),('1016',103);
/*!40000 ALTER TABLE `truck_mtnce` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type`
--

DROP TABLE IF EXISTS `type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `type` (
  `TYPE_CODE` int NOT NULL,
  `TYPE_DESCRIPTION` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`TYPE_CODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type`
--

LOCK TABLES `type` WRITE;
/*!40000 ALTER TABLE `type` DISABLE KEYS */;
INSERT INTO `type` VALUES (1,'Single box, double-axle'),(2,'Single box, single-axle'),(3,'Tandem trailer, single-axle');
/*!40000 ALTER TABLE `type` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-12-07 12:54:30
