#include "environment.hpp"

environment::environment(environment *anterior, std::string id)
{
    Anterior = anterior;
    Id = id;
    Size = 0;
}

symbol environment::SaveVariable(std::string id, TipoDato tipo, ast *tree)
{
    if (Tabla.find(id) == Tabla.end())
    {
        symbol sym (0, 0, id, tipo, Size);
        Tabla[id] = sym;
        Size += 1;
        return sym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe la variable "+id;
        return Tabla[id];
    }
}

void environment::SaveStruct(map<std::string, TipoDato> tabla, std::string id, ast *tree)
{
    if (TablaStructs.find(id) == TablaStructs.end())
    {
        TablaStructs[id] = tabla;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe el struct "+id;
    }
}

void environment::SaveFunc(func_symbol funcSym, std::string id, ast *tree)
{
    if (TablaFunctions.find(id) == TablaFunctions.end())
    {
        TablaFunctions[id] = funcSym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: ya existe la funcion "+id;
    }
}

symbol environment::GetVariable(std::string id, environment *env, ast *tree)
{
    symbol sym = *new symbol;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.Tabla.find(id) == tmpEnv.Tabla.end())
        {
            if(tmpEnv.Anterior == nullptr)
            {
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Anterior;
            }
        }
        else
        {
            symbol tempSym (tmpEnv.Tabla[id].Line,
                            tmpEnv.Tabla[id].Col,
                            tmpEnv.Tabla[id].Id,
                            tmpEnv.Tabla[id].Tipo,
                            tmpEnv.Tabla[id].Posicion);
            sym = tempSym;
            break;
        }

    }

    return sym;
}

//map<std::string, TipoDato> environment::GetStruct(std::string id, environment *env, ast *tree)
//{
//    map<std::string, TipoDato> sym_struct;
//    environment tmpEnv = *env;

//    for( ; ;)
//    {
//        if (tmpEnv.TablaStructs.find(id) == tmpEnv.TablaStructs.end())
//        {
//            if(tmpEnv.Anterior == nullptr)
//            {
//                break;
//            }
//            else
//            {
//                tmpEnv = *tmpEnv.Anterior;
//            }
//        }
//        else
//        {
//            sym_struct = tmpEnv.TablaStructs[id];
//            break;
//        }

//    }
//    return sym_struct;
//}

//func_symbol environment::GetFunc(std::string id, environment *env, ast *tree)
//{
//    func_symbol sym_func;
//    environment tmpEnv = *env;

//    for( ; ;)
//    {
//        if (tmpEnv.TablaFunctions.find(id) == tmpEnv.TablaFunctions.end())
//        {
//            if(tmpEnv.Anterior == nullptr)
//            {
//                break;
//            }
//            else
//            {
//                tmpEnv = *tmpEnv.Anterior;
//            }
//        }
//        else
//        {
//            sym_func = tmpEnv.TablaFunctions[id];
//            break;
//        }

//    }
//    return sym_func;
//}

