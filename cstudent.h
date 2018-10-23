#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <QString>
class CStudent
{
public:
    CStudent();
    CStudent(QString id, QString name, int age, QString grade, QString classid);


    //gtetter setter
    QString stuid() const;
    void setStuid(const QString &stuid);

    QString stuname() const;
    void setStuname(const QString &stuname);

    int age() const;
    void setAge(int age);

    QString grade() const;
    void setGrade(const QString &grade);

    QString classid() const;
    void setClassid(const QString &classid);

private:
    QString m_stuid;
    QString m_stuname;
    int m_age;
    QString m_grade;
    QString m_classid;
};

#endif // CSTUDENT_H
