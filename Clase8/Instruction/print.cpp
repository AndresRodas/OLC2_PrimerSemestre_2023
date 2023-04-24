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

    if(result.TipoExpresion == INTEGER)
    {
        gen->AddComment("************imprimiendo numero************");
        gen->AddPrintf("d", "(int)"+ result.Value);
        gen->AddPrintf("c", "10");
        gen->AddBr();
    }
    else if(result.TipoExpresion == STRING)
    {
        gen->AddComment("************imprimiendo string************");
        //llamar a generar printstring
        gen->GeneratePrintString();
        //agregar codigo en el main
        std::string NewTemp1 = gen->newTemp();
        std::string NewTemp2 = gen->newTemp();
        int size = env->Size;
        gen->AddComment("nuevo temporal en pos vacia");
        gen->AddExpression(NewTemp1, "P", std::to_string(size), "+");
        gen->AddComment("se deja espacio de retorno");
        gen->AddExpression(NewTemp1, NewTemp1, "1", "+");
        gen->AddComment("se coloca string en parametro que se manda");
        gen->AddSetStack("(int)"+ NewTemp1, result.Value);
        gen->AddComment("cambio de entorno");
        gen->AddExpression("P", "P", std::to_string(size), "+");
        gen->AddComment("Llamada");
        gen->AddCall("olc3d_printString");
        gen->AddComment("obtencion retorno");
        gen->AddGetStack(NewTemp2, "(int)P");
        gen->AddComment("regreso del entorno");
        gen->AddExpression("P", "P", std::to_string(size), "-");
        gen->AddComment("salto de linea");
        gen->AddPrintf("c", "10");
        gen->AddBr();
    }
    else if(result.TipoExpresion == BOOL)
    {
        gen->AddComment("************imprimiendo bool************");
        std::string newLabel = gen->newLabel();
        std::string newFalseLabel = gen->newLabel();
        if(result.IsTemp)
        {
            gen->AddIf(result.Value, "1", "!=", newFalseLabel);
        }
        //add true labels
        for(int i=0; i < result.TrueLvl.size(); i++)
        {
            gen->AddLabel(result.TrueLvl[i]);
        }
        gen->AddPrintf("c", "(char)116");
        gen->AddPrintf("c", "(char)114");
        gen->AddPrintf("c", "(char)117");
        gen->AddPrintf("c", "(char)101");
        gen->AddGoto(newLabel);
        //add false labels
        for(int j=0; j < result.FalseLvl.size(); j++)
        {
            gen->AddLabel(result.FalseLvl[j]);
        }
        gen->AddLabel(newFalseLabel);
        gen->AddPrintf("c", "(char)102");
        gen->AddPrintf("c", "(char)97");
        gen->AddPrintf("c", "(char)108");
        gen->AddPrintf("c", "(char)115");
        gen->AddPrintf("c", "(char)101");
        gen->AddLabel(newLabel);
        gen->AddPrintf("c", "10");
        gen->AddBr();
    }
}

//std::string print::ArrayToString(QVector<symbol> Array)
//{
//    std::string strBuffer = "[";
//    int contIndex = 0;
//    for(int i=0; i < Array.size(); ++i){
//        contIndex++;
//        if(Array[i].Tipo == ARRAY)
//        {
//            if(contIndex < Array.size())
//            {
//                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value)) + ",";
//            }
//            else
//            {
//                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value));
//            }

//        }
//        else
//        {
//            if(Array[i].Tipo == STRING)
//            {
//                if(contIndex < Array.size())
//                {
//                    strBuffer += *static_cast<std::string*>(Array[i].Value) + ",";
//                }
//                else
//                {
//                    strBuffer += *static_cast<std::string*>(Array[i].Value);
//                }

//            }
//            else if(Array[i].Tipo == INTEGER)
//            {
//                if(contIndex < Array.size())
//                {
//                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value)) + ",";
//                }
//                else
//                {
//                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value));
//                }

//            }
//            else if(Array[i].Tipo == BOOL)
//            {
//                if(contIndex < Array.size())
//                {
//                    if(*static_cast<bool*>(Array[i].Value))
//                    {
//                        strBuffer += "true,";
//                    }
//                    else
//                    {
//                        strBuffer += "false,";
//                    }
//                }
//                else
//                {
//                    if(*static_cast<bool*>(Array[i].Value))
//                    {
//                        strBuffer += "true";
//                    }
//                    else
//                    {
//                        strBuffer += "false";
//                    }
//                }

//            }
//        }
//    }
//    strBuffer += "]\n";
//    return strBuffer;
//}





