#include "print.hpp"

print::print(int line, int col, expression *valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value result = Valor->ejecutar(env, tree, gen);
    switch (result.TipoExpresion) {
    case INTEGER:
        gen->AddPrintf("d", "(int)"+ result.Value);
        gen->AddPrintf("c", "10");
        gen->AddBr();
        break;
    case STRING:
        //llamar a generar printstring
        gen->GeneratePrintString();
        //agregar codigo en el main

        break;
    }
}

std::string print::ArrayToString(QVector<symbol> Array)
{
    std::string strBuffer = "[";
    int contIndex = 0;
    for(int i=0; i < Array.size(); ++i){
        contIndex++;
        if(Array[i].Tipo == ARRAY)
        {
            if(contIndex < Array.size())
            {
                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value)) + ",";
            }
            else
            {
                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value));
            }

        }
        else
        {
            if(Array[i].Tipo == STRING)
            {
                if(contIndex < Array.size())
                {
                    strBuffer += *static_cast<std::string*>(Array[i].Value) + ",";
                }
                else
                {
                    strBuffer += *static_cast<std::string*>(Array[i].Value);
                }

            }
            else if(Array[i].Tipo == INTEGER)
            {
                if(contIndex < Array.size())
                {
                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value)) + ",";
                }
                else
                {
                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value));
                }

            }
            else if(Array[i].Tipo == BOOL)
            {
                if(contIndex < Array.size())
                {
                    if(*static_cast<bool*>(Array[i].Value))
                    {
                        strBuffer += "true,";
                    }
                    else
                    {
                        strBuffer += "false,";
                    }
                }
                else
                {
                    if(*static_cast<bool*>(Array[i].Value))
                    {
                        strBuffer += "true";
                    }
                    else
                    {
                        strBuffer += "false";
                    }
                }

            }
        }
    }
    strBuffer += "]\n";
    return strBuffer;
}





