#include <iostream>

#include "charfrequency.h"
#include "TenToTwo.h"
#include "doublearraymean.h"
#include "list.h"
#include "binaryhextohex.h"
#include "studentlist.h"

/* 1. Cчитать текстовый файл и определить частотность символов в этом файле
     Результат записать в файл */
void test_CharFrequency(QString file_name);
/* 2. написать функцию перевод числа в двоичный формат (желательно рекурсивно)
a. вывести результат на экран (младший первый, старший последний)
                              (старший первый младший последний)
б. записать результат в файл */
void test_TenToTwo(int decimal, bool young_first_old_last);
/* 3. Написать функцию перевода числа в бинарном формате
   (на входе последовательность символов 0х30 -"0",0x31-"1") в шестнадцатиричный формат */
QString BinaryHexToHex(QString binary_hex);
/* 5. Дан двумерный массив. Определить прототип функции и найти среднее значение
для каждой строчки. Функция должна вернуть список этих средних значений*/
void test_DoubleArrayMean();
/* 6. Написать функцию записи данных двусвязного списка в файл
        a. обход с Head
        б. обход с Tail
   7. написать функцию вставки элемента в заданное место двусвязного списка */
void test_List();
/* 8. написать класс в котором хранится информация о студенте и его отметках
   реализовать функции:
        -добавления отметки по выбранному предмету
        -добавления нового предмета
        -вычисления средней оценки по предметам
        -функции вывода информации о студенте и его средних оценках */
void add_grades(QString fio, uint grade);
void test_StudentList();

int main()
{
    //test_CharFrequency("test_cf.txt");
                     //  1   1   0   1   0   1   1   0   1
    //BinaryHexToHex("0x310x310x300x310x300x310x310x300x31");
    //test_TenToTwo(11223, false);
    //test_DoubleArrayMean();
    test_List();
    //test_StudentList();
    return 0;
}

void test_CharFrequency(QString file_name) {
    QDir dir;
    dir.cdUp();
    dir.cd("RK1");
    CharFrequency cf;
    cf.read_file(dir.absoluteFilePath(file_name));
}
void test_TenToTwo(int decimal, bool young_first_old_last) {
    QDir dir;
    dir.cdUp();
    dir.cd("RK1");
    TenToTwo obj;
    obj.convert(decimal, young_first_old_last, dir).toStdString();
}
QString BinaryHexToHex(QString binary_hex)
{
    QString str = binary_hex.replace(QRegularExpression("0x3"), "");
    uint decimal = 0;

    for (uint i = 0; i < str.size(); i++)
        decimal += (str[i].toLatin1() - 48) * pow(2, str.size() - i - 1);
    str.clear();

    while (decimal != 0) {
        uint hex = decimal % 16;

        if (hex < 10)
            str.push_front(QChar(QString::number(hex)[0]));
        str.push_front(QChar(hex + 55));

        decimal /= 16;
    }

    return str;
}
void test_DoubleArrayMean() {
    uint rows = 10;
    uint* cols = new uint[rows];
    for (uint i = 0; i < rows; i++)
        cols[i] = 10;

    DoubleArray obj = DoubleArray(rows, cols, false);

    // fill
    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < cols[i]; j++)
            obj(i, j) = i + j;
    // print
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols[i]; j++)
            std::cout << obj(i, j) << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // print means
    QList<int> lst = obj.get_means();
    for (uint i = 0; i < lst.size(); i++)
        std::cout << lst[i] << ' ';
    std::cout << std::endl;
}
void test_List() {
    List lst;
    lst.print(false);
    Data data(1);
    lst.push_front(data);
    data.setNumber(10);
    lst.push_front(data);
    data.setNumber(135);
    lst.push_back(data);
    data.setNumber(11);
    lst.insert(data, 1);
    lst.print(false);
    QDir dir;
    dir.cdUp();
    dir.cd("RK1");
    lst.print_to_file(dir, false);
}
void add_grades(StudentList& lst, QString fio, uint grade) {
    for (uint i = 0; i < 5; i++) {
        lst.add_grade(fio, "ART", grade - i);
        lst.add_grade(fio, "BIOLOGY", grade + i);
        lst.add_grade(fio, "ENGLISH", grade - i);
        lst.add_grade(fio, "MATH", grade + i);
        lst.add_grade(fio, "PHYSICS", grade - i);
        lst.add_grade(fio, "RUSSIAN", grade + i);
    }
}
void test_StudentList() {
    StudentList lst;
    QString fio_1 = "Худяков Артём Сергеевич";
    QString fio_2 = "Лобанов Денис Дмитриевич";
    QString fio_3 = "Лисунов Иван Сергеевич";
    QString fio_4 = "Архипов Данила Федорович";
    add_grades(lst, fio_1, 4);
    add_grades(lst, fio_2, 4);
    add_grades(lst, fio_3, 4);
    add_grades(lst, fio_4, 4);
    lst.show_all();
}
