#include "print.hpp"

print::print(int line, int col, expression *valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree)
{
    symbol sym = this->Valor->ejecutar(env, tree);
    if(sym.Tipo == STRING)
    {
        tree->ConsoleOut += sym.StrVal+"\n";
    }
    else
    {
        tree->ConsoleOut += std::to_string(sym.NumVal)+"\n";
    }
}
