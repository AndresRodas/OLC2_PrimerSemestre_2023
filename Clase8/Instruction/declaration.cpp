#include "declaration.hpp"

declaration::declaration(int line, int col, TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}
void declaration::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    symbol newVar;

    val = Valor->ejecutar(env, tree, gen);
    gen->AddComment("agregando declaración de variable");
    newVar = env->SaveVariable(Id, Tipo, tree);
    if(val.TipoExpresion == BOOL)
    {
        //si no es temporal (valor booleano)
        std::string newLabel = gen->newLabel();
        //add true labels
        for(int i=0; i < val.TrueLvl.size(); i++)
        {
            gen->AddLabel(val.TrueLvl[i]);
        }
        gen->AddSetStack(std::to_string(newVar.Posicion),"1");
        gen->AddGoto(newLabel);
        //add false labels
        for(int i=0; i < val.FalseLvl.size(); i++)
        {
            gen->AddLabel(val.FalseLvl[i]);
        }
        gen->AddSetStack(std::to_string(newVar.Posicion),"0");
        gen->AddGoto(newLabel);
        gen->AddLabel(newLabel);
    }
    else
    {
         //si es temporal (num, string, etc)
        gen->AddSetStack(std::to_string(newVar.Posicion), val.Value);
    }
    gen->AddBr();

}
