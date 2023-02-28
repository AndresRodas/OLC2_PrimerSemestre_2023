#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <map>
#include "Environment/ast.hpp"
#include "Environment/symbol.hpp"
using std::map;

class environment
{
public:
    environment *Anterior;
    map<std::string, symbol> Tabla;
    std::string Id;

    environment();
    void SaveVariable(symbol sym, std::string id, ast *tree);
    symbol GetVariable(std::string id, ast *tree);
};

#endif // ENVIRONMENT_HPP
