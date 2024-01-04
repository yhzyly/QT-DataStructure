#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cal.cpp"

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
    QString qs;
    qs=ui->textEdit->toPlainText();
    float x=qs.toFloat();
    x*=x;
    qs=QString("%1").arg(x);
    ui->textEdit->setText(qs);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString qs=ui->textEdit->toPlainText();
    qs.resize(qs.length()-1);
    ui->textEdit->setText(qs);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("7"));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("8"));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("9"));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("4"));
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("5"));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("6"));
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("1"));
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("2"));
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("3"));
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("0"));
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append('.'));
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("/"));
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("*"));
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("-"));
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("+"));
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText().append("%"));
}

void MainWindow::on_pushButton_20_clicked()
{
    QString qstr=ui->textEdit->toPlainText();
    string s = qstr.toStdString();
    float result = calculate(s);
    QString qs1=QString("%1").arg(result);
    ui->textEdit->setText(qs1);

    //history
    ui->textEdit_2->append(qstr+"="+qs1);
}
