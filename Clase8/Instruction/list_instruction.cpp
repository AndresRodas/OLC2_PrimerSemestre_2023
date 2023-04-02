#include "list_instruction.hpp"
#include "Instruction/inst_return.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
}

void list_instruction::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    std::cout << "execute\n";
}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
