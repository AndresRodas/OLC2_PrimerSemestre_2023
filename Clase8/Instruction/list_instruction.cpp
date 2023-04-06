#include "list_instruction.hpp"
#include "Instruction/inst_return.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
}

void list_instruction::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    for (int i = 0; i < this->ListInst.size(); i ++)
    {
        this->ListInst[i]->ejecutar(env, tree, gen);
        //validación return de if
        if(tree->IfReturn)
        {
            return;
        }
        //validacion return function
        inst_return* ret = dynamic_cast<inst_return*>(ListInst[i]);
        if(ret)
        {
            return;
        }
    }
}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
