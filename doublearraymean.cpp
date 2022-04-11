#include "doublearraymean.h"

void DoubleArray::_rand() {
    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < cols[i]; j++)
            darr[i][j] = gen.bounded(-100, 100);
}
DoubleArray::DoubleArray(uint rows, uint* cols, bool rand_fill) {
    this->rows = rows;
    this->cols = new uint[rows];
    darr = new int*[rows];
    for (uint i = 0; i < rows; i++) {
        this->cols[i] = cols[i];
        darr[i] = new int[cols[i]];
    }
    if (rand_fill)
        _rand();
    means = new QList<int>();
}
int& DoubleArray::operator()(uint row, uint col) {
    if (row < this->rows)
        if (col < this->cols[col])
            return darr[col][row];
    throw("Index error");
}
QList<int> DoubleArray::get_means() {
    for (uint i = 0; i < rows; i++) {
        double tmp = 0;
        for (uint j = 0; j < cols[i]; j++)
            tmp += darr[i][j];
        means->append(tmp);
    }
    return *means;
}
DoubleArray::~DoubleArray() {
    for (uint i = 0; i < rows; i++)
        delete darr[i];
    delete darr;
    delete cols;
    delete means;
}
