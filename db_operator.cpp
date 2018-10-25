#include "db_operator.h"

#include <QMessageBox>

db_operator::db_operator()
{
    sql_pwd = "123456";
    sql_databasename = "learn_db";
    sql_username = "root";
}


bool db_operator::create_connect()
{
    bool ok = true;
    try
    {
        db = QSqlDatabase::addDatabase("QMYSQL");

        db.setDatabaseName("learn_db");
        db.setPort(3306);

        db.setUserName("root");

        db.setPassword("123456");

        ok = db.open();

    }
    catch(QString exception)
    {

    }

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

QVector<CStudent> *db_operator::get_all_student() const
{
    QSqlQuery all_student("SELECT * from student");
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
bool db_operator::update_student_info(const CStudent &student)
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
    QString insert_sql = "INSERT INTO class VALUES(?,?,?)";
    QSqlQuery query;
    query.prepare(insert_sql);
    query.bindValue(0, class_info.classid());
    query.bindValue(1, class_info.classname());
    query.bindValue(2, class_info.leaderteacher());

    bool success = query.exec();
    return success;
}


//get student
CStudent * db_operator::get_student_by_id(QString id) const
{
    QString sql = QString("SELECT * FROM student WHERE m_stuid = '%1'").arg(id);
    QSqlQuery find_student(sql);

    if (find_student.next())
    {
        QString m_stuid = find_student.value(0).toString();
        QString m_stuname = find_student.value(1).toString();
        int m_age = find_student.value(2).toInt();
        QString m_grade = find_student.value(3).toString();
        QString m_classid = find_student.value(4).toString();
        return new CStudent(m_stuid, m_stuname, m_age, m_grade, m_classid);
    }


    return NULL;
}

bool db_operator::insert_student_info(const CStudent &student) const
{
    QString insert_sql = "INSERT INTO student VALUE(?, ?, ?, ?, ?)";
    QSqlQuery insert_stu;
    insert_stu.prepare (insert_sql);
    insert_stu.bindValue (0, student.stuid ());
    insert_stu.bindValue (1, student.stuname ());
    insert_stu.bindValue (2, student.age ());
    insert_stu.bindValue (3, student.grade ());
    insert_stu.bindValue (4, student.classid ());

    bool success = insert_stu.exec ();

    return success;
}

cclass * db_operator::get_class_by_id(QString id) const
{
    QString sql = QString("SELECT * FROM class WHERE m_classid = '%1'").arg(id);
    QSqlQuery find_class(sql);

    if (find_class.next())
    {
        QString m_classid = find_class.value(0).toString();
        QString m_classname = find_class.value(1).toString();
        QString m_leadername = find_class.value(2).toString();

        return new cclass(m_classid, m_classname, m_leadername);
    }
    return NULL;
}

bool db_operator::insert_class_info(const cclass &classes) const
{
    QString insert_sql = "INSERT INTO class VALUE(?, ?, ?)";
    QSqlQuery insert_class;
    insert_class.prepare (insert_sql);
    insert_class.bindValue (0, classes.classid ());
    insert_class.bindValue (1, classes.classname ());
    insert_class.bindValue (2, classes.leaderteacher ());

    bool success = insert_class.exec ();

    return success;
}

bool db_operator::update_class_info(const cclass &classes) const
{
    QString update_sql = "UPDATE class SET m_classname=?,m_leadername=? WHERE m_classid=?";
    QSqlQuery update_class;
    update_class.prepare (update_sql);
    update_class.bindValue (0, classes.classname ());
    update_class.bindValue (1, classes.leaderteacher ());
    update_class.bindValue (2, classes.classid ());

    bool success = update_class.exec ();

    return success;
}

bool db_operator::delete_class_info(const cclass &cclases) const
{
    QString delete_sql = "DELETE FROM class WHERE m_classid=?";
    QSqlQuery delete_class;
    delete_class.prepare (delete_sql);
    delete_class.bindValue (0, cclases.classid ());

    bool success = delete_class.exec ();
    return success;
}

ccourse *db_operator::get_course_by_id(QString courseid, QString classid) const
{
    QString select_sql = "SELECT * FROM course WHERE m_courseid=? AND m_classid=?";
    QSqlQuery select_course;
    select_course.prepare (select_sql);
    select_course.bindValue (0, courseid);
    select_course.bindValue (1, classid);

    if (select_course.next ())
    {
        QString courseid = select_course.value (0).toString ();
        QString coursename = select_course.value (1).toString ();
        QString teacher = select_course.value (2).toString ();
        QString classid = select_course.value (3).toString ();
        return new ccourse(courseid, coursename, teacher, classid);
    }
    return NULL;

}

bool db_operator::insert_course_info(const ccourse &course) const
{
    QString insert_sql = "INSERT INTO course VALUE(?, ?, ?,?)";
    QSqlQuery insert_course;
    insert_course.prepare (insert_sql);
    insert_course.bindValue (0, course.courseid ());
    insert_course.bindValue (1, course.coursename ());
    insert_course.bindValue (2, course.teacher ());
    insert_course.bindValue (3, course.classid ());

    bool success = insert_course.exec ();

    return success;
}

//release database
db_operator::~db_operator()
{
    db.close ();
}









