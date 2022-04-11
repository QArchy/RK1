#ifndef DOUBLEARRAYMEAN_H
#define DOUBLEARRAYMEAN_H

typedef unsigned int uint;
#include <QList>
#include <QRandomGenerator>

class DoubleArray {
private:
    uint rows = 0;
    uint* cols = 0;
    int** darr = nullptr;
    QList<int>* means = nullptr;
    QRandomGenerator gen;
    void _rand();
public:
    DoubleArray(uint rows, uint* cols, bool rand_fill);
    int& operator()(uint row, uint col);
    QList<int> get_means();
    ~DoubleArray();
};

#endif // DOUBLEARRAYMEAN_H
