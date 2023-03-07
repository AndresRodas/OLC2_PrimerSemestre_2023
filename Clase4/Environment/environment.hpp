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
    map<std::string, map<std::string, TipoDato>> TablaStructs;
    std::string Id;

    environment(environment *anterior, std::string id);
    void SaveVariable(symbol sym, std::string id, ast *tree);
    void SaveStruct(map<std::string, TipoDato> tabla, std::string id, ast *tree);
    symbol GetVariable(std::string id, environment *env, ast *tree);
    map<std::string, TipoDato> GetStruct(std::string id, environment *env, ast *tree);
};

#endif // ENVIRONMENT_HPP
