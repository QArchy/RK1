#include "TenToTwo.h"

void TenToTwo::split(int decimal) {
    static int deep = 0;
    if (decimal == 0) {
        if (deep == 0) {
            binary.append('0');
            return;
        }
        return;
    }
    deep++;
    split(decimal / 2);
    binary.push_front(QString::number(decimal % 2));
    deep--;
}

void TenToTwo::write_to_file(QString binary, QDir file_path) {
    QFile file(file_path.absolutePath() + "/output_ten_to_two.txt");
    file.open(QFile::WriteOnly);
    file.write(binary.toLatin1());
    file.close();
}

QString TenToTwo::convert(int decimal, bool young_first_old_last, QDir file_path) {
    split(decimal);
    if (young_first_old_last) {
        write_to_file(binary, file_path);
        return binary;
    }
    else {
        std::reverse(binary.begin(), binary.end());
        write_to_file(binary, file_path);
        return binary;
    }
}
