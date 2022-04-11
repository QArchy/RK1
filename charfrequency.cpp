#include "charfrequency.h"

void CharFrequency::collect_data(QString str) {
    for (int i = 0; i < str.size(); i++)
        if (str[i] != '\n') {
            map->operator[](str[i].toLatin1()) = map->operator[](str[i].toLatin1()) + 1;
        }
}
void CharFrequency::print_data(QDir file_path)
{
    QFile file(file_path.absolutePath() + "/output_cf.txt");
    file.open(QFile::WriteOnly);
    QByteArray arr;
    for (auto i = map->begin(); i != map->end(); i++) {
        QString tmp = QString('{') + i.key() + QString("} - ") +
                      QString::number(i.value()) + "\n";
        arr.append(tmp.toLatin1());
    }
    file.write(arr);
    file.close();
}
CharFrequency::CharFrequency() {
    file = new QFile();
    data = new QString();
    map = new QMap<char, int>();
}
void CharFrequency::read_file(QDir file_path) {
    if (data->size() != 0) {
        data->clear();
        map->clear();
    }
    file->setFileName(file_path.absolutePath());
    file->open(QFile::ReadOnly);
    collect_data(QString(file->readAll()));
    file->close();
    file_path.cdUp();
    print_data(file_path.absolutePath());
}
CharFrequency::~CharFrequency() {
    delete file;
    delete map;
}
