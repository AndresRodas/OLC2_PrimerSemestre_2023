#include "func_if.hpp"

func_if::func_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
    ElseIfBlock = elseifblock;
    ElseBlock = elseblock;
}

void func_if::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    gen->AddComment("generando instruccion if");
    value condicion = Condition->ejecutar(env, tree, gen);
    std::string newLabel = gen->newLabel(); //etiqueta de salida
    //agregando etiquetas verdaderas
    for(int i=0; i < condicion.TrueLvl.size(); i++)
    {
        gen->AddLabel(condicion.TrueLvl[i]);
    }
    //instrucción del IF
    Block->ejecutar(env, tree, gen);
    //etiqueta salida
    gen->AddGoto(newLabel);
    //agregando etiquetas falsas
    for(int i=0; i < condicion.FalseLvl.size(); i++)
    {
        gen->AddLabel(condicion.FalseLvl[i]);
    }
    //instrucción del else
    if(ElseBlock != nullptr)
    {
        ElseBlock->ejecutar(env, tree, gen);
    }
    //etiqueta salida
    gen->AddLabel(newLabel);
}
