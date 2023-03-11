#ifndef CALL_INST_HPP
#define CALL_INST_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/instruction.hpp"

class call_inst : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    list_expression *ExpList;

    call_inst(int, int, std::string, list_expression*);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // CALL_INST_HPP
