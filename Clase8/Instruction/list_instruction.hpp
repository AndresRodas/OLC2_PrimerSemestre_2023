#ifndef LIST_INSTRUCTION_HPP
#define LIST_INSTRUCTION_HPP
#include "Interfaces/instruction.hpp"
#include "QVector"

class list_instruction : public instruction
{
public:
    QVector<instruction*> ListInst;
    list_instruction();
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
    void newInst(instruction *inst);
};

#endif // LIST_INSTRUCTION_HPP
