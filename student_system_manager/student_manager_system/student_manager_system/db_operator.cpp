#include "db_operator.h"

#include <QtSql>
#include <QMessageBox>

db_operator::db_operator()
{
    sql_pwd = "123456";
    sql_databasename = "learn_db";
    sql_username = "root";
}


bool db_operator::create_connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("learn_db");
    db.setPort(3306);

    db.setUserName("root");

    db.setPassword("123456");

    bool ok = db.open();

    return ok;
}

QVector<cclass>* db_operator::get_all_class() const
{
    QSqlQuery all_class("SELECT * from class");
    QVector<cclass> * classes = new QVector<cclass>();
    while (all_class.next())
    {
        QString m_classid = all_class.value(0).toString();
        QString m_classname = all_class.value(1).toString();
        QString m_leadername = all_class.value(2).toString();

        classes->push_back(cclass(m_classid, m_classname, m_leadername));
    }

    return classes;
}

QVector<CStudent> *db_operator::get_class_student(QString classid) const
{
    QString sql = QString("SELECT * FROM student WHERE m_classid = '%1'").arg(classid);
    QSqlQuery all_student(sql);
    QVector<CStudent> * students = new QVector<CStudent>();
    while (all_student.next())
    {
        QString m_stuid = all_student.value(0).toString();
        QString m_stuname = all_student.value(1).toString();
        int m_age = all_student.value(2).toInt();
        QString m_grade = all_student.value(3).toString();
        QString m_classid = all_student.value(4).toString();

        students->push_back(CStudent(m_stuid, m_stuname, m_age, m_grade, m_classid));
    }

    return students;

}

QVector<ccourse> * db_operator::get_class_course(QString classid) const
{
    QString sql = QString("SELECT * FROM course WHERE m_classid = '%1'").arg(classid);
    QSqlQuery all_class_course(sql);
    QVector<ccourse> * courses = new QVector<ccourse>();
    while (all_class_course.next())
    {

        QString m_stuid = all_class_course.value(0).toString();
        QString m_stuname = all_class_course.value(1).toString();
        QString m_teacher = all_class_course.value(2).toString();
        QString m_classid = all_class_course.value(3).toString();

        courses->push_back(ccourse(m_stuid, m_stuname, m_teacher, m_classid));
    }

    return courses;
}
//update the new student infomation
bool db_operator::save_student_info(const CStudent &student)
{
    QString sql = "UPDATE student "
                  "SET m_stuid=?, m_stuname=?, m_age=?, m_grade=?, m_classid=? "
                  "WHERE m_stuid=?";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(0, student.stuid());
    query.bindValue(1, student.stuname());
    query.bindValue(2, student.age());
    query.bindValue(3, student.grade());
    query.bindValue(4, student.classid());
    query.bindValue(5, student.stuid());

    bool success = query.exec();
    return success;

}

bool db_operator::add_class_info(const cclass &class_info) const
{
    QString insert_sql = "INSERT INTO class"
                         "VALUES(?, ?, ?)";
    QSqlQuery query;
    query.prepare(insert_sql);
    query.bindValue(0, class_info.classid());
    query.bindValue(1, class_info.classname());
    query.bindValue(2, class_info.leaderteacher());

    bool success = query.exec();
    return success;
}









