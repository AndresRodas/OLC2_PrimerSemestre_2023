#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP
#include "Interfaces/expression.hpp"

class primitive : public expression
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string strVal;
    int numVal;
    bool boolVal;

    primitive(int, int, TipoDato, std::string, int, bool);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // PRIMITIVE_HPP
