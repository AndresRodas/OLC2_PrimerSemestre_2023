#ifndef CALL_EXP_HPP
#define CALL_EXP_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class call_exp : public expression
{
public:
    int Line;
    int Col;
    std::string Id;
    list_expression *ExpList;

    call_exp(int, int, std::string, list_expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // CALL_EXP_HPP
