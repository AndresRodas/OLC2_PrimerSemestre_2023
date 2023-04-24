#ifndef FUNC_WHILE_HPP
#define FUNC_WHILE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_while : public instruction
{
public:
    int Line;
    int Col;
    expression *Condition;
    instruction *Block;

    func_while(int line, int col, expression *condition, instruction *block);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_WHILE_HPP
