#include "print.hpp"

print::print(int line, int col, expression *valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
    switch (sym.Tipo) {
    case STRING:
        tree->ConsoleOut += *static_cast<std::string*>(sym.Value)+"\n";
        break;
    case INTEGER:
        tree->ConsoleOut += std::to_string(*static_cast<int*>(sym.Value))+ "\n";
        break;
    case BOOL:
        if(*static_cast<bool*>(sym.Value)){
            tree->ConsoleOut += "true\n";
        }
        else
        {
            tree->ConsoleOut += "false\n";
        }
        break;
    case ARRAY:
        QVector<symbol> *Arr = (QVector<symbol>*)sym.Value;
        QVector<symbol> result = *Arr;
        tree->ConsoleOut += ArrayToString(result);
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





