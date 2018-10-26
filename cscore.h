#ifndef CSCORE_H
#define CSCORE_H

#include <QString>

class cscore
{
public:
    cscore();
    cscore(QString stuid, QString courseid,  QString score);

    QString stuid() const;
    void setStuid(const QString &stuid);


    QString score() const;
    void setScore(const QString &score);

    QString courseid() const;
    void setCourseid(const QString &courseid);

    QString coursename() const;
    void setCoursename(const QString &coursename);

private:
    QString m_stuid;
    QString m_courseid;
    QString m_coursename;
    QString m_score;

};

#endif // CSCORE_H
