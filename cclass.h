#ifndef CCLASS_H
#define CCLASS_H

#include <QString>
class cclass
{
public:
    cclass();
    cclass(QString& id, QString& cname, QString& lname);

    //getter setter


    QString classid() const;
    void setClassid(const QString &classid);

    QString classname() const;
    void setClassname(const QString &classname);

    QString leaderteacher() const;
    void setLeaderteacher(const QString &leaderteacher);


    //operator
    bool operator==(const cclass & c);

private:
    QString m_classid;
    QString m_classname;
    QString m_leaderteacher;
};

#endif // CCLASS_H
