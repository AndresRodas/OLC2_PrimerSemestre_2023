#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Environment/ast.hpp"
#include "Environment/environment.hpp"
#include <QMessageBox>
#include "parserctx.hpp"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox *msg = new QMessageBox();
    QMessageBox *msg3 = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(nullptr, "Global");
    //creando ast
    ast *Root = new ast();
    //creando generador c3d
    generator_code *GeneratorC3D = new generator_code();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutando funcinoes
    if(analizador.Functions != nullptr)
    {
       analizador.Functions->ejecutar(GlobalEnv, Root, GeneratorC3D);
    }
    //ejecutar main
    GeneratorC3D->MainCode = true;
    analizador.Main->ejecutar(GlobalEnv, Root, GeneratorC3D);
    GeneratorC3D->GenerateFinalCode();
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
        ui->textEdit_2->setText(QString::fromStdString(GeneratorC3D->FinalCode));
    }
    else
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        ui->textEdit_2->setText(QString::fromStdString(Root->ErrorOut));
    }
}

