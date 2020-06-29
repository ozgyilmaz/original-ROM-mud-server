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
-- Table structure for table `area`
--

DROP TABLE IF EXISTS `area`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `area` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `filename` varchar(100) COLLATE latin1_general_ci DEFAULT NULL,
  `name` varchar(100) COLLATE latin1_general_ci DEFAULT NULL,
  `writer` varchar(100) COLLATE latin1_general_ci DEFAULT NULL,
  `credits` varchar(100) COLLATE latin1_general_ci DEFAULT NULL,
  `low_range` int(11) DEFAULT NULL,
  `high_range` int(11) DEFAULT NULL,
  `min_vnum` int(11) DEFAULT NULL,
  `max_vnum` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `filename_UNIQUE` (`filename`)
) ENGINE=InnoDB AUTO_INCREMENT=49 DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `area`
--

LOCK TABLES `area` WRITE;
/*!40000 ALTER TABLE `area` DISABLE KEYS */;
INSERT INTO `area` VALUES (1,'immort.are','Valhalla','ROM','Immortal Zone',51,60,1200,1299),(2,'ofcol2.are','New Ofcol','Hatchet','New Ofcol',5,35,600,699),(3,'shire.are','Shire','Poohb','The Shire',5,35,1100,1199),(4,'midgaard.are','Midgaard','Diku','Midgaard',1,51,3000,3399),(5,'plains.are','Plains','Copper','Plains of the North',1,20,300,399),(6,'haon.are','Haon Dor','Diku','Haon Dor',5,10,6000,6199),(7,'air.are','In the Air','Copper','In the Air',5,10,1000,1099),(8,'arachnos.are','Arachnos','Mahatma','Arachnos',5,20,6200,6399),(9,'astral.are','Astral Plane','Andersen','Astral/Githyanki',10,35,7700,7799),(10,'canyon.are','Elemental Canyon','Raff','Elemental Canyon',5,30,9200,9299),(11,'catacomb.are','Catacombs','Raff','Dwarven Catacombs',10,20,2000,2099),(12,'chapel.are','Chapel','Copper','Chapel Catacombs',15,25,3400,3499),(13,'daycare.are','Day Care','Sandman','Dwarven Day Care',1,5,6600,6699),(14,'draconia.are','Dragon Tower','Wench','Dragon Tower',5,30,2200,2299),(15,'dream.are','Machine Dreams','Furey','Machine Dreams',1,5,8600,8699),(16,'drow.are','Drow City','Drkside','Drow City',15,25,5100,5199),(17,'thalos.are','Thalos','Drkside','Thalos',10,25,5200,5299),(18,'dwarven.are','Dwarven Kingdom','Anon','Dwarven Kingdom',10,25,6500,6599),(19,'dylan.are','Dylan\'s Area','Dylan','Dylan\'s Area',15,25,9100,9199),(20,'eastern.are','Sands of Sorrow','Anon','Sands of Sorrow',10,20,5000,5099),(21,'galaxy.are','Galaxy','Doctor','Galaxy',20,30,9300,9399),(22,'gnome.are','Gnome Village','Vougon','Gnome Village',5,15,1500,1599),(23,'grave.are','Graveyard','Alfa','Graveyard',5,10,3600,3699),(24,'grove.are','Holy Grove','Alfa','Holy Grove',5,20,8900,8999),(25,'hitower.are','High Tower','Skylar','High Tower of Sorcery',10,30,1300,1499),(26,'hood.are','Gangland','Raff','Dangerous Neighborhood',5,15,2100,2199),(27,'limbo.are','Limbo','Diku','Limbo',59,60,0,99),(28,'mahntor.are','Mahn-Tor','Chris','The Keep of Mahn-Tor',5,35,2300,2399),(29,'marsh.are','Marsh','Generic','Old Marsh',15,25,8300,8399),(30,'mega1.are','Mega City One','Glop','Mega-City One ',5,35,8000,8099),(31,'midennir.are','Miden\'nir','Copper','Miden\'nir',5,15,3500,3599),(32,'mirror.are','Old Thalos','Kahn','Old Thalos',1,30,5300,5399),(33,'mobfact.are','Mob Factory','PinkF','Mob Factory',5,15,9400,9499),(34,'moria.are','Moria','Alfa','Moria',5,15,3900,4199),(35,'newthalos.are','New Thalos','Conner','New Thalos',10,35,9500,9799),(36,'nirvana.are','Nirvana','Fstall','Nirvana',30,35,9000,9099),(37,'ofcol.are','Ofcol','Alfa','Ofcol',1,51,5500,5599),(38,'olympus.are','Olympus','Generic','Olympus',5,50,900,999),(39,'pyramid.are','Pyramid','Andersen','The Great Pyramid',5,-50,8700,8799),(40,'quifael.are','Quifael\'s','Quifael','Quifael\'s Area',31,35,6900,6999),(41,'sewer.are','Sewers','Diku','Sewer',5,30,7000,7499),(42,'redferne.are','Redferne\'s','Diku','Redferne\'s Residence',20,30,7900,7999),(43,'school.are','mud school','Hatchet','Mud School',1,5,3700,3799),(44,'smurf.are','Smurfville','Generic','Smurf Village',1,10,100,199),(45,'tohell.are','Hell','Strahd','Descent to Hell',32,51,10400,10599),(46,'trollden.are','Troll Den','Merc','Troll Den',10,15,2800,2899),(47,'valley.are','Valley of the Elves','Hatchet','Valley of the Elves',5,20,7800,7899),(48,'wyvern.are','Wyvern\'s Tower','Tyrst','Wyvern\'s Tower',5,30,1600,1799);
/*!40000 ALTER TABLE `area` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-06-29 23:16:14
