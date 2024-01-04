#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ComAndEx.cpp"
#include <QApplication>
#include<iostream>
#include<io.h>
#include<fstream>
#include<stdio.h>

//ComAndEx *comandex = new ComAndEx;

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

//E:\\Qt\\project\\pic.bmp
//E:\Qt\project\\pic.huff
void MainWindow::on_pushButton_clicked()
{
    ComAndEx *comandex = new ComAndEx;
    QString qstr1=ui->lineEdit->text(),qstr2=ui->lineEdit_2->text();
    string s1=qstr1.toStdString(),s2=qstr2.toStdString();
    comandex->Compress(s1,s2);

    const char* f1=s1.c_str(),*f2=s2.c_str();

    FILE* fp1=fopen(f1,"r");
    fseek(fp1, 0L, SEEK_END);
    long size1 = ftell(fp1);

    FILE* fp2=fopen(f2,"r");
    fseek(fp2, 0L, SEEK_END);
    long size2 = ftell(fp2);

    fclose(fp1);
    fclose(fp2);

    ui->textEdit->setText("压缩完成..."+QString::number(size1));
    ui->textEdit->append("压缩前:"+QString::number(size1)+" 压缩后:"+QString::number(size2)+"   byte.");
}


void MainWindow::on_pushButton_2_clicked()
{
    ComAndEx *comandex = new ComAndEx;
    QString qstr1=ui->lineEdit->text(),qstr2=ui->lineEdit_2->text();
    string s1=qstr1.toStdString(),s2=qstr2.toStdString();
    ui->textEdit->append("解压中...");
    comandex->Extract(s1,s2);
}
