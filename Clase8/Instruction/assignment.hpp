
#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class assignment : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;

    assignment(int line, int col, std::string Id, expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // ASSIGNMENT_HPP
