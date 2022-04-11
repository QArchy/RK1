#ifndef TENTOTWO_H
#define TENTOTWO_H

#include <QString>
#include <QDir>
#include <QFile>

class TenToTwo
{
private:
    QString binary;
    void split(int decimal);
    void write_to_file(QString binary, QDir file_path);
public:
    QString convert(int decimal, bool young_first_old_last, QDir file_path);
};

#endif // TENTOTWO_H
