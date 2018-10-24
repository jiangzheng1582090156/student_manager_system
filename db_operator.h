#ifndef DB_OPERATOR_H
#define DB_OPERATOR_H


#include <QString>
#include <QVector>
#include <QtSql>

#include "cclass.h"
#include "ccourse.h"
#include "cstudent.h"
class db_operator
{
public:
    db_operator();
    bool create_connect();

    QVector<cclass>* get_all_class() const;
    QVector<CStudent>* get_class_student(QString classid) const;
    QVector<ccourse> * get_class_course(QString classid) const;

    bool update_student_info(const CStudent& student);
    bool add_class_info(const cclass& class_info) const;

    bool add_student_info(const CStudent & student);

    CStudent * get_student_by_id(QString id) const;
    bool insert_student_info(const CStudent & student) const;

    cclass * get_class_by_id(QString id) const;
    bool insert_class_info(const cclass & classes) const;

    ccourse * get_course_by_id(QString courseid, QString classid) const;
    bool insert_course_info(const ccourse & course) const;

    ~db_operator();
private:
    QString sql_username;
    QString sql_pwd;
    QString sql_databasename;


    QSqlDatabase db;
};

#endif // DB_OPERATOR_H
