#ifndef OPERATION_HPP
#define OPERATION_HPP
#include "Interfaces/expression.hpp"

class operation: public expression
{
public:
    int Line;
    int Col;
    expression *Op_izq;
    expression *Op_der;
    std::string Operator;

    operation(int line, int col, expression *op_izq, expression *op_der, std::string operador);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // OPERATION_HPP
