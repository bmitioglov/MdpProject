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
INSERT INTO `countries` VALUES ('Австралия'),('Америка'),('Англия'),('Беларусь'),('Болгария'),('Германия'),('Греция'),('Испания'),('Казахстан'),('Норвегия'),('Россия');
/*!40000 ALTER TABLE `countries` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `country_properties`
--

DROP TABLE IF EXISTS `country_properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `country_properties` (
  `Country_Name` varchar(45) DEFAULT NULL,
  `Property_ID` int(11) NOT NULL,
  KEY `fk_Country_properties_Countries1` (`Country_Name`),
  KEY `fk_country_properties_Properties1_idx` (`Property_ID`),
  CONSTRAINT `fk_Country_properties_Countries1` FOREIGN KEY (`Country_Name`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_country_properties_Properties1` FOREIGN KEY (`Property_ID`) REFERENCES `properties` (`Property_ID`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `country_properties`
--

LOCK TABLES `country_properties` WRITE;
/*!40000 ALTER TABLE `country_properties` DISABLE KEYS */;
INSERT INTO `country_properties` VALUES ('Россия',1),('Америка',2),('Греция',3),('Норвегия',4),('Англия',5),('Англия',3),('Испания',7),('Австралия',8),('Австралия',9),('Испания',10),('Германия',11),('Америка',7),('Болгария',6),('Америка',10),('Австралия',1);
/*!40000 ALTER TABLE `country_properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `flights`
--

DROP TABLE IF EXISTS `flights`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `flights` (
  `Flight_ID` int(11) NOT NULL AUTO_INCREMENT,
  `Country_To` varchar(45) NOT NULL,
  `Country_From` varchar(45) NOT NULL,
  `Time_hour` int(11) NOT NULL,
  PRIMARY KEY (`Flight_ID`),
  KEY `fk_Flights_Countries1_idx` (`Country_To`),
  KEY `fk_Flights_Countries2_idx` (`Country_From`),
  CONSTRAINT `fk_Flights_Countries1` FOREIGN KEY (`Country_To`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Flights_Countries2` FOREIGN KEY (`Country_From`) REFERENCES `countries` (`Country_Name`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `flights`
--

LOCK TABLES `flights` WRITE;
/*!40000 ALTER TABLE `flights` DISABLE KEYS */;
INSERT INTO `flights` VALUES (1,'Англия','Россия',6),(2,'Норвегия','Россия',4),(3,'Америка','Россия',13),(4,'Австралия','Россия',12),(5,'Беларусь','Россия',2),(6,'Германия','Россия',4),(7,'Болгария','Россия',3),(8,'Греция','Россия',4),(9,'Испания','Россия',6),(10,'Казахстан','Россия',2),(11,'Англия','Казахстан',6),(12,'Англия','Испания',3),(13,'Англия','Австралия',12),(14,'Беларусь','Англия',5),(15,'Англия','Америка',9),(16,'Англия','Норвегия',4),(17,'Англия','Греция',5),(18,'Болгария','Испания',5),(19,'Беларусь','Казахстан',4),(20,'Англия','Болгария',5),(21,'Греция','Испания',3),(22,'Австралия','Беларусь',10);
/*!40000 ALTER TABLE `flights` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `properties`
--

DROP TABLE IF EXISTS `properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `properties` (
  `Property_ID` int(11) NOT NULL AUTO_INCREMENT,
  `Property_Name` varchar(45) NOT NULL,
  PRIMARY KEY (`Property_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `properties`
--

LOCK TABLES `properties` WRITE;
/*!40000 ALTER TABLE `properties` DISABLE KEYS */;
INSERT INTO `properties` VALUES (1,'Покорять дикую природу'),(2,'Валяться на пляже'),(3,'Осматривать достопримечательности'),(4,'Кататься на лыжах и сноуборде'),(5,'Заниматься шопингом'),(6,'Дышать романтикой'),(7,'Расслабляться в спа'),(8,'Заниматься дайвингом'),(9,'Кататься на сёрфе'),(10,'Ловить ветер на кайте и виндсёрфе'),(11,'Отдыхать всей семьёй');
/*!40000 ALTER TABLE `properties` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-03-26 23:53:10
