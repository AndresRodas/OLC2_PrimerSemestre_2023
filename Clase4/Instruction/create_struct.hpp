#ifndef CREATE_STRUCT_HPP
#define CREATE_STRUCT_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/instruction.hpp"

class create_struct : public instruction
{
public:
    int Line;
    int Col;
    std::string IdStruct;
    std::string Id;
    list_expression *ExpList;
    create_struct(int,int, std::string, std::string, list_expression*);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // CREATE_STRUCT_HPP
