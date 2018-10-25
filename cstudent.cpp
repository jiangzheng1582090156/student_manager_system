#include "cstudent.h"

CStudent::CStudent()
{

}

CStudent::CStudent(QString id, QString name, int age, QString grade, QString classid)
{
    m_stuid = id;
    m_stuname = name;
    m_age = age;
    m_grade = grade;
    m_classid = classid;
}

QString CStudent::stuid() const
{
    return m_stuid;
}

void CStudent::setStuid(const QString &stuid)
{
    m_stuid = stuid;
}

QString CStudent::stuname() const
{
    return m_stuname;
}

void CStudent::setStuname(const QString &stuname)
{
    m_stuname = stuname;
}

int CStudent::age() const
{
    return m_age;
}

void CStudent::setAge(int age)
{
    m_age = age;
}

QString CStudent::grade() const
{
    return m_grade;
}

void CStudent::setGrade(const QString &grade)
{
    m_grade = grade;
}

QString CStudent::classid() const
{
    return m_classid;
}

void CStudent::setClassid(const QString &classid)
{
    m_classid = classid;
}

bool CStudent::operator ==(const CStudent &student)
{
    if (this->m_classid == student.m_classid && this->m_stuid == student.m_stuid
       && this->m_stuname == student.m_stuname && this->m_grade == student.m_grade
       && this->m_age == student.m_age
       )
    {
        return true;
    }
    return false;
}
