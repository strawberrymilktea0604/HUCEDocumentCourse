CREATE DATABASE  IF NOT EXISTS `cafedb` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `cafedb`;
-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: cafedb
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
-- Table structure for table `attendance`
--

DROP TABLE IF EXISTS `attendance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `attendance` (
  `dateRecord` date DEFAULT NULL,
  `empid` int DEFAULT NULL,
  `nameshift` varchar(40) DEFAULT NULL,
  `timeRecord` time DEFAULT NULL,
  KEY `empid` (`empid`),
  KEY `nameshift` (`nameshift`),
  CONSTRAINT `attendance_ibfk_1` FOREIGN KEY (`empid`) REFERENCES `employee` (`empid`),
  CONSTRAINT `attendance_ibfk_2` FOREIGN KEY (`nameshift`) REFERENCES `shift` (`nameshift`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `attendance` (`dateRecord`, `empid`, `nameshift`, `timeRecord`) VALUES ('2024-12-01', 101, 'Morning Shift', '08:00:00');
INSERT INTO `attendance` (`dateRecord`, `empid`, `nameshift`, `timeRecord`) VALUES ('2024-12-01', 102, 'Afternoon Shift', '14:00:00');
INSERT INTO `attendance` (`dateRecord`, `empid`, `nameshift`, `timeRecord`) VALUES ('2024-12-02', 103, 'Night Shift', '22:00:00');
INSERT INTO `attendance` (`dateRecord`, `empid`, `nameshift`, `timeRecord`) VALUES ('2024-12-02', 101, 'Morning Shift', '08:15:00');
INSERT INTO `attendance` (`dateRecord`, `empid`, `nameshift`, `timeRecord`) VALUES ('2024-12-02', 102, 'Afternoon Shift', '14:05:00');

--
-- Dumping data for table `attendance`
--

LOCK TABLES `attendance` WRITE;
/*!40000 ALTER TABLE `attendance` DISABLE KEYS */;
/*!40000 ALTER TABLE `attendance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bill`
--

DROP TABLE IF EXISTS `bill`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bill` (
  `billid` int NOT NULL,
  `drinkid` int DEFAULT NULL,
  `voucherid` int DEFAULT NULL,
  `billdate` date DEFAULT NULL,
  `totalamount` int DEFAULT NULL,
  `accountid` int DEFAULT NULL,
  `payment_status` enum('SUCCESS','FAILED') NOT NULL DEFAULT 'FAILED',
  PRIMARY KEY (`billid`),
  KEY `drinkid` (`drinkid`),
  KEY `voucherid` (`voucherid`),
  KEY `fk_account` (`accountid`),
  CONSTRAINT `bill_ibfk_1` FOREIGN KEY (`drinkid`) REFERENCES `drink` (`drinkid`),
  CONSTRAINT `bill_ibfk_2` FOREIGN KEY (`voucherid`) REFERENCES `voucher` (`voucherid`),
  CONSTRAINT `fk_account` FOREIGN KEY (`accountid`) REFERENCES `cafeaccount` (`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
-- Insert 70 random records into the 'bill' table
INSERT INTO `bill` (`billid`, `drinkid`, `voucherid`, `billdate`, `totalamount`, `accountid`, `payment_status`) 
VALUES (1, 201, 301, '2024-12-01', 500, 101, 'SUCCESS');

INSERT INTO `bill` (`billid`, `drinkid`, `voucherid`, `billdate`, `totalamount`, `accountid`, `payment_status`) 
VALUES (2, 202, NULL, '2024-12-01', 300, 102, 'FAILED');

INSERT INTO `bill` (`billid`, `drinkid`, `voucherid`, `billdate`, `totalamount`, `accountid`, `payment_status`) 
VALUES (3, 203, 302, '2024-12-02', 450, 103, 'SUCCESS');

INSERT INTO `bill` (`billid`, `drinkid`, `voucherid`, `billdate`, `totalamount`, `accountid`, `payment_status`) 
VALUES (4, 201, 303, '2024-12-02', 700, 104, 'SUCCESS');

INSERT INTO `bill` (`billid`, `drinkid`, `voucherid`, `billdate`, `totalamount`, `accountid`, `payment_status`) 
VALUES (5, 204, NULL, '2024-12-03', 250, 105, 'FAILED');


--
-- Dumping data for table `bill`
--

LOCK TABLES `bill` WRITE;
/*!40000 ALTER TABLE `bill` DISABLE KEYS */;
/*!40000 ALTER TABLE `bill` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bill_item`
--

DROP TABLE IF EXISTS `bill_item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bill_item` (
  `billid` int NOT NULL,
  `drinkid` int NOT NULL,
  `drink_qty` int NOT NULL DEFAULT '1',
  PRIMARY KEY (`billid`,`drinkid`),
  KEY `drinkid` (`drinkid`),
  CONSTRAINT `bill_item_ibfk_1` FOREIGN KEY (`billid`) REFERENCES `bill` (`billid`),
  CONSTRAINT `bill_item_ibfk_2` FOREIGN KEY (`drinkid`) REFERENCES `drink` (`drinkid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (1, 201, 2);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (1, 202, 1);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (2, 202, 3);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (3, 203, 1);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (4, 201, 4);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (4, 204, 2);
INSERT INTO `bill_item` (`billid`, `drinkid`, `drink_qty`) VALUES (5, 204, 1);

--
-- Dumping data for table `bill_item`
--

LOCK TABLES `bill_item` WRITE;
/*!40000 ALTER TABLE `bill_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `bill_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cafeaccount`
--

DROP TABLE IF EXISTS `cafeaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cafeaccount` (
  `accountid` int NOT NULL,
  `userName` varchar(20) DEFAULT NULL,
  `userPassWord` varchar(9) NOT NULL,
  PRIMARY KEY (`accountid`),
  UNIQUE KEY `unique_accountid` (`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `cafeaccount` (`accountid`, `userName`, `userPassWord`) VALUES (101, 'JohnDoe', 'pass1234');
INSERT INTO `cafeaccount` (`accountid`, `userName`, `userPassWord`) VALUES (102, 'JaneSmith', 'abc98765');
INSERT INTO `cafeaccount` (`accountid`, `userName`, `userPassWord`) VALUES (103, 'TomBrown', 'qwerty12');
INSERT INTO `cafeaccount` (`accountid`, `userName`, `userPassWord`) VALUES (104, 'AliceWhite', 'zxcvb678');
INSERT INTO `cafeaccount` (`accountid`, `userName`, `userPassWord`) VALUES (105, 'BobBlack', 'hello987');

-- Dumping data for table `cafeaccount`
--

LOCK TABLES `cafeaccount` WRITE;
/*!40000 ALTER TABLE `cafeaccount` DISABLE KEYS */;
/*!40000 ALTER TABLE `cafeaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `drink`
--

DROP TABLE IF EXISTS `drink`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `drink` (
  `drinkid` int NOT NULL,
  `drinkname` varchar(30) DEFAULT NULL,
  `drinkprice` float DEFAULT NULL,
  `drinksize` varchar(3) DEFAULT NULL,
  `drinktype` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`drinkid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `drink` (`drinkid`, `drinkname`, `drinkprice`, `drinksize`, `drinktype`) VALUES (201, 'Espresso', 2.5, 'S', 'Coffee');
INSERT INTO `drink` (`drinkid`, `drinkname`, `drinkprice`, `drinksize`, `drinktype`) VALUES (202, 'Latte', 3.5, 'M', 'Coffee');
INSERT INTO `drink` (`drinkid`, `drinkname`, `drinkprice`, `drinksize`, `drinktype`) VALUES (203, 'Cappuccino', 3.0, 'M', 'Coffee');
INSERT INTO `drink` (`drinkid`, `drinkname`, `drinkprice`, `drinksize`, `drinktype`) VALUES (204, 'Green Tea', 2.0, 'L', 'Tea');
INSERT INTO `drink` (`drinkid`, `drinkname`, `drinkprice`, `drinksize`, `drinktype`) VALUES (205, 'Orange Juice', 2.8, 'M', 'Juice');

--
-- Dumping data for table `drink`
--

LOCK TABLES `drink` WRITE;
/*!40000 ALTER TABLE `drink` DISABLE KEYS */;
/*!40000 ALTER TABLE `drink` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `empid` int NOT NULL,
  `empname` varchar(30) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `empphoneNum` varchar(11) DEFAULT NULL,
  `dateOfBirth` date DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `accountid` int NOT NULL,
  `managerid` int DEFAULT NULL,
  PRIMARY KEY (`empid`),
  UNIQUE KEY `accountid` (`accountid`),
  UNIQUE KEY `unique_account_employee` (`accountid`),
  KEY `managerid` (`managerid`),
  CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`managerid`) REFERENCES `manager` (`managerid`),
  CONSTRAINT `employee_ibfk_2` FOREIGN KEY (`accountid`) REFERENCES `cafeaccount` (`accountid`),
  CONSTRAINT `fk_employee_account` FOREIGN KEY (`accountid`) REFERENCES `cafeaccount` (`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `employee` (`empid`, `empname`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`, `managerid`) 
VALUES (1, 'John Smith', '123 Elm St', '1234567890', '1990-05-10', 'M', 101, NULL);

INSERT INTO `employee` (`empid`, `empname`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`, `managerid`) 
VALUES (2, 'Jane Doe', '456 Oak St', '0987654321', '1985-08-20', 'F', 102, NULL);

INSERT INTO `employee` (`empid`, `empname`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`, `managerid`) 
VALUES (3, 'Alice Brown', '789 Pine St', '1122334455', '1995-11-15', 'F', 103, NULL);

INSERT INTO `employee` (`empid`, `empname`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`, `managerid`) 
VALUES (4, 'Bob White', '321 Cedar St', '2233445566', '1988-03-25', 'M', 104, NULL);

INSERT INTO `employee` (`empid`, `empname`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`, `managerid`) 
VALUES (5, 'Tom Black', '654 Maple St', '3344556677', '1992-07-30', 'M', 105, NULL);


--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `invoice`
--

DROP TABLE IF EXISTS `invoice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `invoice` (
  `invoiceid` int NOT NULL,
  `billid` int NOT NULL,
  `paymentdate` datetime DEFAULT NULL,
  `totalamount` decimal(10,2) NOT NULL,
  PRIMARY KEY (`invoiceid`),
  KEY `billid` (`billid`),
  CONSTRAINT `invoice_ibfk_1` FOREIGN KEY (`billid`) REFERENCES `bill` (`billid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `invoice` (`invoiceid`, `billid`, `paymentdate`, `totalamount`) 
VALUES (1, 1, '2024-12-01 10:30:00', 25.50);

INSERT INTO `invoice` (`invoiceid`, `billid`, `paymentdate`, `totalamount`) 
VALUES (2, 2, '2024-12-02 14:45:00', 18.75);

INSERT INTO `invoice` (`invoiceid`, `billid`, `paymentdate`, `totalamount`) 
VALUES (3, 3, '2024-12-03 16:00:00', 10.00);

INSERT INTO `invoice` (`invoiceid`, `billid`, `paymentdate`, `totalamount`) 
VALUES (4, 4, '2024-12-04 09:15:00', 35.00);

INSERT INTO `invoice` (`invoiceid`, `billid`, `paymentdate`, `totalamount`) 
VALUES (5, 5, '2024-12-05 19:30:00', 12.00);

--
-- Dumping data for table `invoice`
--

LOCK TABLES `invoice` WRITE;
/*!40000 ALTER TABLE `invoice` DISABLE KEYS */;
/*!40000 ALTER TABLE `invoice` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `manager`
--

DROP TABLE IF EXISTS `manager`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `manager` (
  `managerid` int NOT NULL,
  `managername` varchar(30) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `empphoneNum` varchar(11) DEFAULT NULL,
  `dateOfBirth` date DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `accountid` int NOT NULL,
  PRIMARY KEY (`managerid`),
  UNIQUE KEY `accountid` (`accountid`),
  UNIQUE KEY `unique_account_manager` (`accountid`),
  CONSTRAINT `fk_manager_account` FOREIGN KEY (`accountid`) REFERENCES `cafeaccount` (`accountid`),
  CONSTRAINT `manager_ibfk_1` FOREIGN KEY (`accountid`) REFERENCES `cafeaccount` (`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `manager` (`managerid`, `managername`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`) 
VALUES (1, 'Anna Brown', '123 Manager Lane', '9876543210', '1980-02-15', 'F', 201);

INSERT INTO `manager` (`managerid`, `managername`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`) 
VALUES (2, 'Mark Johnson', '456 Director Ave', '8765432109', '1975-11-30', 'M', 202);

INSERT INTO `manager` (`managerid`, `managername`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`) 
VALUES (3, 'Emily Davis', '789 Executive Blvd', '7654321098', '1988-05-22', 'F', 203);

INSERT INTO `manager` (`managerid`, `managername`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`) 
VALUES (4, 'Michael Lee', '101 Admin Rd', '6543210987', '1983-09-14', 'M', 204);

INSERT INTO `manager` (`managerid`, `managername`, `address`, `empphoneNum`, `dateOfBirth`, `gender`, `accountid`) 
VALUES (5, 'Sophia White', '202 Supervisor St', '5432109876', '1990-12-18', 'F', 205);

--
-- Dumping data for table `manager`
--

LOCK TABLES `manager` WRITE;
/*!40000 ALTER TABLE `manager` DISABLE KEYS */;
/*!40000 ALTER TABLE `manager` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shift`
--

DROP TABLE IF EXISTS `shift`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shift` (
  `nameshift` varchar(40) NOT NULL,
  `timeStart` time DEFAULT NULL,
  `timeEnd` time DEFAULT NULL,
  PRIMARY KEY (`nameshift`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `shift` (`nameshift`, `timeStart`, `timeEnd`) 
VALUES 
  ('Morning Shift', '08:00:00', '12:00:00'),
  ('Afternoon Shift', '13:00:00', '17:00:00'),
  ('Evening Shift', '18:00:00', '22:00:00'),
  ('Night Shift', '23:00:00', '03:00:00'),
  ('Full Day Shift', '08:00:00', '20:00:00');


--
-- Dumping data for table `shift`
--

LOCK TABLES `shift` WRITE;
/*!40000 ALTER TABLE `shift` DISABLE KEYS */;
/*!40000 ALTER TABLE `shift` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `voucher`
--

DROP TABLE IF EXISTS `voucher`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `voucher` (
  `voucherid` int NOT NULL,
  `vouchername` varchar(30) DEFAULT NULL,
  `dateStart` date DEFAULT NULL,
  `dateEnd` date DEFAULT NULL,
  `voucherDesc` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`voucherid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
INSERT INTO `voucher` (`voucherid`, `code`, `discount`) 
VALUES
(1, 'DISCOUNT10', 10.00),
(2, 'DISCOUNT20', 20.00),
(3, 'DISCOUNT30', 30.00),
(4, 'FREEDRINK', 100.00),
(5, 'SUMMERSALE', 15.00),
(6, 'WINTERSALE', 25.00),
-- Thêm đủ dữ liệu để khớp với voucherid trong bảng bill
(19, 'SPRINGSALE', 20.00),
(20, 'AUTUMN20', 20.00);
--
-- Dumping data for table `voucher`
--

LOCK TABLES `voucher` WRITE;
/*!40000 ALTER TABLE `voucher` DISABLE KEYS */;
/*!40000 ALTER TABLE `voucher` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-18 19:49:35
