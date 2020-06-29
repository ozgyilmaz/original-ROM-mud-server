CREATE DATABASE  IF NOT EXISTS `mud` /*!40100 DEFAULT CHARACTER SET latin1 COLLATE latin1_general_ci */;
USE `mud`;
-- MySQL dump 10.13  Distrib 8.0.18, for macos10.14 (x86_64)
--
-- Host: 37.48.122.122    Database: mud
-- ------------------------------------------------------
-- Server version	5.5.65-MariaDB

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
-- Table structure for table `shop`
--

DROP TABLE IF EXISTS `shop`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shop` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `keeper` int(11) DEFAULT NULL,
  `buy_type0` int(11) DEFAULT NULL,
  `buy_type1` int(11) DEFAULT NULL,
  `buy_type2` int(11) DEFAULT NULL,
  `buy_type3` int(11) DEFAULT NULL,
  `buy_type4` int(11) DEFAULT NULL,
  `profit_buy` int(11) DEFAULT NULL,
  `profit_sell` int(11) DEFAULT NULL,
  `open_hour` int(11) DEFAULT NULL,
  `close_hour` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `keeper_UNIQUE` (`keeper`)
) ENGINE=InnoDB AUTO_INCREMENT=63 DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shop`
--

LOCK TABLES `shop` WRITE;
/*!40000 ALTER TABLE `shop` DISABLE KEYS */;
INSERT INTO `shop` VALUES (1,604,5,9,15,0,0,120,80,0,23),(2,605,9,0,0,0,0,120,80,0,23),(3,606,8,12,13,0,0,120,80,0,23),(4,607,0,19,0,0,0,120,10,0,23),(5,608,0,17,19,0,0,120,10,0,23),(6,622,0,17,0,0,0,120,10,0,23),(7,1113,17,0,0,0,0,150,50,0,23),(8,1118,13,5,15,1,17,150,50,0,23),(9,1119,13,5,15,1,17,150,50,0,23),(10,1120,9,5,0,0,0,150,50,0,23),(11,1130,17,0,0,0,0,150,50,0,23),(12,3000,2,3,4,10,0,105,15,0,23),(13,3001,0,0,0,0,0,110,100,0,23),(14,3002,1,8,13,15,19,150,40,0,23),(15,3003,5,6,7,0,0,120,40,0,23),(16,3004,9,0,0,0,0,100,50,0,23),(17,3006,22,0,0,0,0,120,90,6,22),(18,3008,0,0,0,0,0,100,100,0,23),(19,3009,8,30,32,33,0,110,100,0,23),(20,3010,9,0,0,0,0,110,50,0,23),(21,3040,0,0,0,0,0,110,100,0,23),(22,3042,0,0,0,0,0,100,100,0,23),(23,3043,0,0,0,0,0,110,100,0,23),(24,3044,0,0,0,0,0,170,100,0,23),(25,3045,0,0,0,0,0,150,100,0,23),(26,3046,0,0,0,0,0,100,90,0,23),(27,3070,10,0,0,0,0,1000,100,0,23),(28,3100,0,0,0,0,0,110,90,6,23),(29,3150,0,0,0,0,0,100,100,0,23),(30,3160,0,0,0,0,0,100,100,0,23),(31,306,1,10,11,19,0,120,60,0,23),(32,308,0,0,0,0,0,110,100,0,23),(33,9238,0,0,0,0,0,105,15,0,23),(34,6503,0,0,0,0,0,150,50,0,23),(35,6504,0,0,0,0,0,150,50,0,23),(36,1305,17,19,0,0,0,210,50,0,23),(37,1306,2,3,4,10,21,250,30,0,23),(38,5310,0,0,0,0,0,120,90,0,23),(39,5311,5,17,19,0,0,110,90,6,20),(40,5312,19,0,0,0,0,110,90,7,19),(41,5313,5,9,0,0,0,130,70,5,21),(42,5314,1,8,12,13,22,135,65,8,18),(43,5317,2,3,4,10,0,120,50,9,17),(44,9505,0,0,0,0,0,110,90,0,23),(45,9510,0,0,0,0,0,110,90,0,23),(46,9511,1,8,12,13,15,200,100,0,23),(47,9513,8,11,9,16,21,200,40,0,23),(48,9514,0,0,0,0,0,150,40,0,23),(49,9515,0,0,0,0,0,100,50,0,23),(50,9516,9,11,0,0,0,150,10,0,23),(51,9517,5,6,7,0,0,130,10,0,23),(52,9518,0,0,0,0,0,150,40,0,23),(53,9565,22,0,0,0,0,131,86,0,23),(54,9566,0,0,0,0,0,250,50,0,23),(55,9579,10,0,0,0,0,187,25,0,23),(56,9580,2,3,4,0,0,170,30,0,23),(57,9583,0,0,0,0,0,110,90,0,23),(58,9584,9,11,0,0,0,105,15,0,23),(59,915,1,8,13,15,19,120,80,0,23),(60,3717,1,15,17,19,0,100,100,0,23),(61,10451,0,0,0,0,0,110,75,0,23),(62,10454,2,3,4,10,0,225,15,0,23);
/*!40000 ALTER TABLE `shop` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-06-29 23:16:09
