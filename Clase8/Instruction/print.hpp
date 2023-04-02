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
    std::string ArrayToString(QVector<symbol> array);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // PRINT_HPP
