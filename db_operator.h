#ifndef DB_OPERATOR_H
#define DB_OPERATOR_H


#include <QString>
#include <QVector>
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

    bool save_student_info(const CStudent& student);
    bool add_class_info(const cclass& class_info) const;
private:
    QString sql_username;
    QString sql_pwd;
    QString sql_databasename;
};

#endif // DB_OPERATOR_H
