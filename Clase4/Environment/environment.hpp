#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <map>
#include "Environment/symbol.hpp"
using std::map;

class environment
{
public:
    environment *Anterior;
    map<std::string, symbol> Tabla;
    std::string Id;

    environment();
};

#endif // ENVIRONMENT_HPP
