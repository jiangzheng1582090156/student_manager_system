#ifndef CCOURSE_H
#define CCOURSE_H

#include <QString>
class ccourse
{
public:
    ccourse();
    ccourse(QString courseid, QString coursename, QString teacher, QString classid);

    ///getter setter
    QString courseid() const;
    void setCourseid(const QString &courseid);

    QString coursename() const;
    void setCoursename(const QString &coursename);

    QString teacher() const;
    void setTeacher(const QString &teacher);

    QString classid() const;
    void setClassid(const QString &classid);

private:
    QString m_courseid;
    QString m_coursename;
    QString m_teacher;
    QString m_classid;
};

#endif // CCOURSE_H
