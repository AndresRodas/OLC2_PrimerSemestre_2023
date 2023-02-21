#ifndef PRINT_HPP
#define PRINT_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class print : public instruction
{
public:
    int Line;
    int Col;
    expression *Valor;

    print(int line, int col, expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // PRINT_HPP
