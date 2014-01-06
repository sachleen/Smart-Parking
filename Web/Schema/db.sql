-- phpMyAdmin SQL Dump
-- version 4.1.3
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 06, 2014 at 02:16 AM
-- Server version: 5.6.15-log
-- PHP Version: 5.4.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `parking`
--

-- --------------------------------------------------------

--
-- Table structure for table `nodes`
--

DROP TABLE IF EXISTS `nodes`;
CREATE TABLE IF NOT EXISTS `nodes` (
  `id` varchar(5) NOT NULL,
  `lat` decimal(10,8) NOT NULL,
  `lng` decimal(11,8) NOT NULL,
  `total` tinyint(4) NOT NULL,
  `available` tinyint(4) DEFAULT '0',
  `error` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `nodes`
--

INSERT INTO `nodes` (`id`, `lat`, `lng`, `total`, `available`, `error`) VALUES
('CCCCC', '38.56050207', '-121.42113179', 5, 1, 0),
('DDDDD', '38.56050836', '-121.42089441', 7, 0, 0),
('EEEEE', '38.56070342', '-121.42106876', 2, 0, 1),
('FFFFF', '38.56031331', '-121.42096952', 15, 12, 3),
('test1', '38.56051465', '-121.42138526', 2, 2, 0);
