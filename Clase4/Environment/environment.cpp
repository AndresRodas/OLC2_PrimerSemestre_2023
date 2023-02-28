#include "environment.hpp"

environment::environment()
{

}

void environment::SaveVariable(symbol sym, std::string id, ast *tree)
{
    if (Tabla.find(id) == Tabla.end())
    {
        Tabla[id] = sym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe la variable "+id;
    }
}

symbol environment::GetVariable(std::string id, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    //return sym;
    if (Tabla.find(id) == Tabla.end())
    {
        //se reporta un error
        tree->ErrorOut += "No existe la variable "+id;
    }
    else
    {
        symbol tempSym (Tabla[id].Line,
                        Tabla[id].Col,
                        Tabla[id].Id,
                        Tabla[id].Tipo,
                        Tabla[id].Value);
        sym = tempSym;
    }
    return sym;
}
