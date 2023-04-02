#ifndef INST_RETURN_HPP
#define INST_RETURN_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class inst_return : public instruction
{
public:
    int Line;
    int Col;
    expression *Exp;
    inst_return(int, int, expression*);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // INST_RETURN_HPP
