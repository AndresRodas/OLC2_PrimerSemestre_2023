#ifndef MAP_STRUCT_DEC_HPP
#define MAP_STRUCT_DEC_HPP
#include "Interfaces/expression.hpp"

class map_struct_dec : public expression
{
public:
    map<std::string, TipoDato> ListDec;
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
    void newMap(std::string, TipoDato);
    map_struct_dec();
};

#endif // MAP_STRUCT_DEC_HPP
