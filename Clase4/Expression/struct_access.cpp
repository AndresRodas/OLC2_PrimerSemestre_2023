#include "struct_access.hpp"

struct_access::struct_access(int line,int col, expression* structexp, std::string id)
{
    Line = line;
    Col = col;
    StructExp = structexp;
    Id = id;
}

symbol struct_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);

    //recuperar struct
    symbol symStruct = StructExp->ejecutar(env, tree);
    environment *envStruct = (environment *)symStruct.Value;

    sym = envStruct->GetVariable(Id, envStruct,tree);
    return sym;
}
