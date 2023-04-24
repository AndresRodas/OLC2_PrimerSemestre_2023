
#include "func_while.hpp"

func_while::func_while(int line, int col, expression *condition, instruction *block)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
}

void func_while::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    gen->AddComment("generando instruccion while");
    value condicion;
    //etiqueta de retorno
    std::string RetLvl = gen->newLabel();
    gen->AddLabel(RetLvl);
    //ejecutando expresion
    condicion = Condition->ejecutar(env, tree, gen);
    //aqui se agregarian etiquetas break y continue
    //agregando etiquetas verdaderas
    for(int i=0; i < condicion.TrueLvl.size(); i++)
    {
        gen->AddLabel(condicion.TrueLvl[i]);
    }
    //ejecutando instrucciones
    Block->ejecutar(env, tree, gen);
    //retorno
    gen->AddGoto(RetLvl);
    //agregando etiquetas falsas
    for(int i=0; i < condicion.FalseLvl.size(); i++)
    {
        gen->AddLabel(condicion.FalseLvl[i]);
    }
}
