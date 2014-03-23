CREATE DATABASE  IF NOT EXISTS `mdpschema` /*!40100 DEFAULT CHARACTER SET cp1251 */;
USE `mdpschema`;
-- MySQL dump 10.13  Distrib 5.6.13, for Win32 (x86)
--
-- Host: localhost    Database: mdpschema
-- ------------------------------------------------------
-- Server version	5.6.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `countries`
--

DROP TABLE IF EXISTS `countries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `countries` (
  `Country_Name` varchar(45) NOT NULL DEFAULT '',
  PRIMARY KEY (`Country_Name`)
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `countries`
--

LOCK TABLES `countries` WRITE;
/*!40000 ALTER TABLE `countries` DISABLE KEYS */;
INSERT INTO `countries` VALUES ('Australia');
/*!40000 ALTER TABLE `countries` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `country_properties`
--

DROP TABLE IF EXISTS `country_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `country_properties` (
  `Property` varchar(45) DEFAULT NULL,
  `Country_Name` varchar(45) DEFAULT NULL,
  KEY `fk_Country_properties_Countries1` (`Country_Name`),
  CONSTRAINT `fk_Country_properties_Countries1` FOREIGN KEY (`Country_Name`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `country_properties`
--

LOCK TABLES `country_properties` WRITE;
/*!40000 ALTER TABLE `country_properties` DISABLE KEYS */;
INSERT INTO `country_properties` VALUES ('Валяться на пляже','Australia'),('Покорять дикую природу','Australia');
/*!40000 ALTER TABLE `country_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `flights`
--

DROP TABLE IF EXISTS `flights`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `flights` (
  `Flight_ID` int(11) NOT NULL,
  `Country_To` varchar(45) NOT NULL,
  `Countries_From` varchar(45) NOT NULL,
  PRIMARY KEY (`Flight_ID`),
  KEY `fk_Flights_Countries1_idx` (`Country_To`),
  KEY `fk_Flights_Countries2_idx` (`Countries_From`),
  CONSTRAINT `fk_Flights_Countries1` FOREIGN KEY (`Country_To`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Flights_Countries2` FOREIGN KEY (`Countries_From`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `flights`
--

LOCK TABLES `flights` WRITE;
/*!40000 ALTER TABLE `flights` DISABLE KEYS */;
/*!40000 ALTER TABLE `flights` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-03-23 19:00:23
