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
    std::cout << "execute\n";
}
