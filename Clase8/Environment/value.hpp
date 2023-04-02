#ifndef VALUE_HPP
#define VALUE_HPP
#include <iostream>
#include "type.h"
#include "QVector"

class value
{
public:
    std::string Value;
    bool IsTemp;
    TipoDato TipoExpresion;
    QVector<std::string> TrueLvl;
    QVector<std::string> FalseLvl;

    value();
};

#endif // VALUE_HPP
