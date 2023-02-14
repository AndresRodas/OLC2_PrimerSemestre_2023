#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parserctx.hpp"


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
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //despliega el mensaje
    QMessageBox *msg = new QMessageBox();
    msg->setText("Ejecución realizada");
    msg->exec();

    ui->textEdit_2->setText(QString::fromStdString( analizador.Salida));

}

