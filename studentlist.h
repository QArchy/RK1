#ifndef STUDENTLIST_H
#define STUDENTLIST_H

typedef unsigned int uint;
#include <QString>
#include <QMap>
#include <QVector>
#include <iostream>

class StudentList
{
private:
    QMap<QString, QMap<QString, QVector<uint>>> lst;
public:
    void add_student(QString fio);
    void add_subject(QString subj_name);
    void add_grade(QString fio, QString subj_name, uint grade);
    double get_mean(QString fio, QString subj_name);
    void show_student_info(QString fio);
    void show_all();
};

#endif // STUDENTLIST_H
