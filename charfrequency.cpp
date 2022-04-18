#include "charfrequency.h"

void CharFrequency::collect_data(QString str) {
    // идем по строке содержащей данные файла
    for (int i = 0; i < str.size(); i++)
        // не берем символ переноса строки
        if (str[i] != '\n') {
            // записываем букву QMap если ее нет
            // а если есть, увеличиваем счетчик встреч на 1
            map->operator[](str[i].toLatin1()) = map->operator[](str[i].toLatin1()) + 1;
        }
}
void CharFrequency::print_data(QDir file_path)
{
    QFile file(file_path.absolutePath() + "/output_cf.txt");
    file.open(QFile::WriteOnly);
    QByteArray arr;
    // идем по QMap
    for (auto i = map->begin(); i != map->end(); i++) {
        // берем букву (key) и количество ее встреч (value)
        QString tmp = QString('{') + i.key() + QString("} - ") +
                      QString::number(i.value()) + "\n";
        // и добавляем в конец массива для записи в файл
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
    // если вызываем функцию не первый раз, надо почистить ранее собранные данные
    if (data->size() != 0) {
        data->clear();
        map->clear();
    }
    // открываем файл
    file->setFileName(file_path.absolutePath());
    file->open(QFile::ReadOnly);
    // собираем данные
    collect_data(QString(file->readAll()));
    file->close();
    file_path.cdUp();
    // записываем данные в файл
    print_data(file_path.absolutePath());
}
CharFrequency::~CharFrequency() {
    delete file;
    delete map;
}
