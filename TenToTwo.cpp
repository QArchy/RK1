#include "TenToTwo.h"

void TenToTwo::split(int decimal) {
    // счетчик глубины рекурсии
    static int deep = 0; // статическая переменная общая для любого вызова функции
    // она инициализируется 1 раз при первом вызове функции
    // если число ноль
    if (decimal == 0) {
        if (deep == 0) {
            // если мы еще не входили в рекурсию, то десятичное число изначално равно 0
            binary.append('0');
            return;
        }
        // то мы дошли до конца рекурсии
        return;
    }
    // увеличиваем счетчик глубины на 1
    deep++;
    // и входим в рекурсию
    split(decimal / 2);
    // при выходе из рекурсии добавляем остаток от деления на 2 в конец стоки
    binary.push_front(QString::number(decimal % 2));
    // уменьшаем счетчик глубины рекурсии на 1
    deep--;
}

void TenToTwo::write_to_file(QString binary, QDir file_path) {
    QFile file(file_path.absolutePath() + "/output_ten_to_two.txt");
    file.open(QFile::WriteOnly);
    file.write(binary.toLatin1());
    file.close();
}

QString TenToTwo::convert(int decimal, bool young_first_old_last, QDir file_path) {
    // конвертируем десятичное число decimal в двоичное
    split(decimal);
    if (young_first_old_last) {
        std::reverse(binary.begin(), binary.end());
        write_to_file(binary, file_path);
        return binary;
    }
    else {
        write_to_file(binary, file_path);
        return binary;
    }
}
