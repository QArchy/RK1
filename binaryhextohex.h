#ifndef BINARYHEXTOHEX_H
#define BINARYHEXTOHEX_H

typedef unsigned int uint;
#include <QString>
#include <QtMath>
#include <QRegularExpression>

class BinaryHexToHex
{
private:
    QString str;
    uint decimal;
    QChar get_hex_char(uint hex);
    void convert_binary_to_decimal();
public:
    QString get_hex(QString binary_hex);
};

#endif // BINARYHEXTOHEX_H
