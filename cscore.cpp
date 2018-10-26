#include "cscore.h"

cscore::cscore()
{

}

cscore::cscore(QString stuid, QString courseid, QString score)
{
    m_stuid = stuid;
    m_courseid = courseid;
    m_score = score;
}

QString cscore::stuid() const
{
    return m_stuid;
}

void cscore::setStuid(const QString &stuid)
{
    m_stuid = stuid;
}

QString cscore::score() const
{
    return m_score;
}

void cscore::setScore(const QString &score)
{
    m_score = score;
}

QString cscore::courseid() const
{
    return m_courseid;
}

void cscore::setCourseid(const QString &courseid)
{
    m_courseid = courseid;
}

QString cscore::coursename() const
{
    return m_coursename;
}

void cscore::setCoursename(const QString &coursename)
{
    m_coursename = coursename;
}
