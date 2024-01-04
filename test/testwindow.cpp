#include "testwindow.h"
#include "ui_testwindow.h"
//#include <string>
#include "solution.cpp"
//#include <iostream>
//using namespace std;

TestWindow::TestWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestWindow)
{
    ui->setupUi(this);
}

TestWindow::~TestWindow()
{
    delete ui;
}


void TestWindow::on_pushButton_clicked()
{
    //ui->label->setText(tr("World!"));
    QImage *icon=new QImage("E:\\Qt\\project\\test\\1.jpg");
    /*ui->label_4->setPixmap(icon);
    //ui->label_4->setWindowIcon(QIconsize);
    ui->label_4->setFixedSize(icon.size());*/
    QImage *scaled_img =new QImage();
    *scaled_img=icon->scaled(230,500,Qt::KeepAspectRatio);
    ui->label_4->setPixmap(QPixmap::fromImage(*scaled_img));

    QString m,n;
    m=ui->textEdit->toPlainText();
    int a=m.toInt();//amount
    n=ui->textEdit_2->toPlainText();
    int b=n.toInt();//num.

    JosephCircle jc;
    for(int i=1;i<=a;i++){
        jc.Add(i);
    }
    jc.Eliminate(b);
    jc.Print();

    QString str=QString::number(jc.getData());
    ui->label->setText(str);
}

void TestWindow::on_pushButton2_clicked(bool checked)
{
    if(checked){
        ui->label->setText(tr("SB!"));
    }
    //ui->label->setText(tr("SB!"));
}
