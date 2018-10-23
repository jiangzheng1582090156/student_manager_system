#include "ccourse.h"

ccourse::ccourse()
{

}

ccourse::ccourse(QString courseid, QString coursename, QString teacher, QString classid)
{
    m_courseid = courseid;
    m_coursename = coursename;
    m_teacher = teacher;
    m_classid = classid;
}

QString ccourse::courseid() const
{
    return m_courseid;
}

void ccourse::setCourseid(const QString &courseid)
{
    m_courseid = courseid;
}

QString ccourse::coursename() const
{
    return m_coursename;
}

void ccourse::setCoursename(const QString &coursename)
{
    m_coursename = coursename;
}

QString ccourse::teacher() const
{
    return m_teacher;
}

void ccourse::setTeacher(const QString &teacher)
{
    m_teacher = teacher;
}

QString ccourse::classid() const
{
    return m_classid;
}

void ccourse::setClassid(const QString &classid)
{
    m_classid = classid;
}
