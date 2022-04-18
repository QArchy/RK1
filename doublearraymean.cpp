#include "doublearraymean.h"

void DoubleArray::_rand() {
    // заполняем матрицу случайными числами
    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < cols; j++)
            darr[i][j] = gen.bounded(-100, 100); // случайные числа от -100 до 100
}
DoubleArray::DoubleArray(uint rows, uint cols, bool rand_fill) {
    this->rows = rows;
    this->cols = cols;
    // инициализируем массив указателей
    darr = new int*[rows];
    for (uint i = 0; i < rows; i++) {
        // инициализируем массив int'ов в каждом указателе
        darr[i] = new int[cols];
    }
    if (rand_fill)
        _rand();
    means = new QList<int>();
}
int& DoubleArray::operator()(uint row, uint col) {
    if (row < this->rows)
        if (col < this->cols)
            return darr[col][row];
    throw("Index error");
}
QList<int> DoubleArray::get_means() {
    for (uint i = 0; i < rows; i++) {
        double tmp = 0;
        for (uint j = 0; j < cols; j++)
            tmp += darr[i][j];
        // добавляем в конец списка среднее значение
        means->append(tmp / cols);
    }
    return *means;
}
DoubleArray::~DoubleArray() {
    for (uint i = 0; i < rows; i++)
        // чистим каждый массив int'ов
        delete darr[i];
    // чистим массив указателей
    delete darr;
    // чистим список средних значений
    delete means;
}
