#include "binaryhextohex.h"

QString BinaryHexToHex::get_hex(QString binary_hex)
{
    str = binary_hex.replace(QRegularExpression("0x3"), "");
    decimal = 0;

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
