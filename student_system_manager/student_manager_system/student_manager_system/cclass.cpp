#include "cclass.h"

cclass::cclass()
{

}

cclass::cclass(QString& id, QString& cname, QString& lname)
{
    this->m_classid = id;
    this->m_classname = cname;
    this->m_leaderteacher = lname;
}


//gettter  setter
QString cclass::classid() const
{
    return m_classid;
}

void cclass::setClassid(const QString &classid)
{
    m_classid = classid;
}

QString cclass::classname() const
{
    return m_classname;
}

void cclass::setClassname(const QString &classname)
{
    m_classname = classname;
}

QString cclass::leaderteacher() const
{
    return m_leaderteacher;
}

void cclass::setLeaderteacher(const QString &leaderteacher)
{
    m_leaderteacher = leaderteacher;
}
