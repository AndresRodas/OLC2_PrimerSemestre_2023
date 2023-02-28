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
    switch (sym.Tipo) {
    case STRING:
        tree->ConsoleOut += *static_cast<std::string*>(sym.Value)+"\n";
        break;
    case INTEGER:
        tree->ConsoleOut += std::to_string(*static_cast<int*>(sym.Value))+ "\n";
        break;
    case BOOL:
        if(*static_cast<bool*>(sym.Value)){
            tree->ConsoleOut += "true\n";
        }
        else
        {
            tree->ConsoleOut += "false\n";
        }
        break;
    default:
        break;
    }

}
