#ifndef FUNC_IF_HPP
#define FUNC_IF_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_if : public instruction
{
public:
    int Line;
    int Col;
    expression *Condition;
    instruction *Block;
    instruction *ElseIfBlock;
    instruction *ElseBlock;

    func_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_IF_HPP
