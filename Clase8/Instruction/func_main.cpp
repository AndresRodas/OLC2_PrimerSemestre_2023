#include "func_main.hpp"

func_main::func_main(int line, int col, std::string tipo, list_instruction *listainst)
{
    this->Line = line;
    this->Col = col;
    this->Tipo = tipo;
    this->ListaInstr = listainst;
}

void func_main::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    ListaInstr->ejecutar(env, tree, gen);
}
