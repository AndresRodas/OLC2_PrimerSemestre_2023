#include "mainwindow.hpp"
#include "Environment/ast.hpp"
#include "ui_mainwindow.h"
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


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox *msg = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment();
    //creando ast
    ast *Root = new ast();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutar main
    analizador.Main->ejecutar(GlobalEnv, Root);
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
        ui->textEdit_2->setText(QString::fromStdString(Root->ConsoleOut));
    }
    else
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        ui->textEdit_2->setText(QString::fromStdString(Root->ErrorOut));
    }

}


















