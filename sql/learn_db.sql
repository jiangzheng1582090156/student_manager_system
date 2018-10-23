/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50721
Source Host           : localhost:3306
Source Database       : learn_db

Target Server Type    : MYSQL
Target Server Version : 50721
File Encoding         : 65001

Date: 2018-10-21 18:02:19
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for class
-- ----------------------------
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class` (
  `m_classid` char(10) NOT NULL,
  `m_classname` varchar(20) NOT NULL,
  `m_leadername` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`m_classid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO `class` VALUES ('20161161', '软件161', '李元金');
INSERT INTO `class` VALUES ('20161162', '软件162', '李元金');

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `m_courseid` varchar(10) NOT NULL,
  `m_coursename` varchar(25) NOT NULL,
  `m_teacher` varchar(20) NOT NULL,
  `m_classid` char(10) NOT NULL,
  PRIMARY KEY (`m_courseid`,`m_classid`),
  KEY `m_classid` (`m_classid`),
  CONSTRAINT `course_ibfk_1` FOREIGN KEY (`m_classid`) REFERENCES `class` (`m_classid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('001', 'C++', '李元金', '20161161');
INSERT INTO `course` VALUES ('001', 'C++', '李元金', '20161162');
INSERT INTO `course` VALUES ('002', '软件工程', '刘东良', '20161161');
INSERT INTO `course` VALUES ('002', '软件工程', '刘东良', '20161162');
INSERT INTO `course` VALUES ('003', '安卓', '刘国秀', '20161161');
INSERT INTO `course` VALUES ('003', '安卓', '刘国秀', '20161162');

-- ----------------------------
-- Table structure for score
-- ----------------------------
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score` (
  `m_studentid` char(10) NOT NULL,
  `m_courseid` char(10) NOT NULL,
  `m_score` double NOT NULL,
  PRIMARY KEY (`m_studentid`,`m_courseid`),
  KEY `m_courseid` (`m_courseid`),
  CONSTRAINT `score_ibfk_1` FOREIGN KEY (`m_studentid`) REFERENCES `student` (`m_stuid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `score_ibfk_2` FOREIGN KEY (`m_courseid`) REFERENCES `course` (`m_courseid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of score
-- ----------------------------

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `m_stuid` char(10) NOT NULL,
  `m_stuname` varchar(20) NOT NULL,
  `m_age` int(11) NOT NULL,
  `m_grade` char(8) NOT NULL,
  `m_classid` char(10) DEFAULT NULL,
  PRIMARY KEY (`m_stuid`),
  KEY `m_classid` (`m_classid`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`m_classid`) REFERENCES `class` (`m_classid`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('2016211796', '姜政', '22', '2016', '20161161');
INSERT INTO `student` VALUES ('2016211797', '程序', '21', '162', '20161162');
INSERT INTO `student` VALUES ('2016211798', '姚胜', '23', '161', '20161161');
INSERT INTO `student` VALUES ('2016211799', '方涛', '22', '162', '20161162');
