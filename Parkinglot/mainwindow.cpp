#include "mainwindow.h"
#include <QPropertyAnimation>
#include "ui_mainwindow.h"
#include "flowingtime.cpp"
#include "arrayQueue.h"
#include "Car.cpp"

#include <QTimer>
#include <QTime>

string spot[8];
int t1[8],t2[8],length=0;
QTime qt;
arrayQueue<string> q;

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
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(updateTime()));
    time->start(1000);

}

void MainWindow::updateTime(){
    ui->textEdit->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_2_clicked()
{
    Car c;
    while(1){
       int i=rand()%8;
       if(length==8){
           if(!q.IsFull()) q.EnQueue(c.getcar());
           break;
       }else{
           if(!q.IsEmpty()){
               ui->textEdit_2->setText(QString::fromStdString("From the queue is :"+q.First()));
               int j;
               for(j=0;j<8;j++){
                   if(spot[j]==""){
                       spot[j]=q.First();
                       q.DeQueue();
                       switch (j+1) {
                       case 1:ui->label_9->setText("Car 1");move(1);break;
                       case 2:ui->label_10->setText("Car 2");move(2);break;
                       case 3:ui->label_11->setText("Car 3");move(3);break;
                       case 4:ui->label_12->setText("Car 4");move(4);break;
                       case 5:ui->label_13->setText("Car 5");move(5);break;
                       case 6:ui->label_14->setText("Car 6");move(6);break;
                       case 7:ui->label_15->setText("Car 7");move(7);break;
                       case 8:ui->label_16->setText("Car 8");move(8);break;
                       }
                       length++;
                       t1[j]=qt.currentTime().second()+qt.currentTime().minute()*60;
                       break;
                   }
               }
               break;
           }
       }
       if(spot[i]==""){
           spot[i]=c.getcar();
           switch (i+1) {
           case 1:ui->label_9->setText("Car 1");move(1);break;
           case 2:ui->label_10->setText("Car 2");move(2);break;
           case 3:ui->label_11->setText("Car 3");move(3);break;
           case 4:ui->label_12->setText("Car 4");move(4);break;
           case 5:ui->label_13->setText("Car 5");move(5);break;
           case 6:ui->label_14->setText("Car 6");move(6);break;
           case 7:ui->label_15->setText("Car 7");move(7);break;
           case 8:ui->label_16->setText("Car 8");move(8);break;
           }
           length++;
           t1[i]=qt.currentTime().second()+qt.currentTime().minute()*60;
//           ui->textEdit->setText(QString::number(t1[i]));
           break;
       }
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    while(1){
        int i=rand()%8;
        if(spot[i]!=""){
            ui->textEdit_2->append(QString::fromStdString(spot[i]));
            spot[i]="";
            switch (i+1) {
            case 1:moveout(1);break;
            case 2:moveout(2);break;
            case 3:moveout(3);break;
            case 4:moveout(4);break;
            case 5:moveout(5);break;
            case 6:moveout(6);break;
            case 7:moveout(7);break;
            case 8:moveout(8);break;
            }
            length--;
            t2[i]=qt.currentTime().second()+qt.currentTime().minute()*60;
            ui->textEdit_2->append("Cost: "+QString::number(2*(t2[i]-t1[i])));
            break;
        }
    }
}

void MainWindow::move(int k){
    switch(k){
    case 1:{
        ui->label_9->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_9, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 65, 70, 50));
        animation1->setEndValue(QRect(160, 65, 70, 50));
        animation1->start();
        break;}
    case 2:{
        ui->label_10->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_10, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 65, 70, 50));
        animation1->setEndValue(QRect(440, 65, 70, 50));
        animation1->start();
        break;}
    case 3:{
        ui->label_11->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_11, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 170, 70, 50));
        animation1->setEndValue(QRect(160, 170, 70, 50));
        animation1->start();
        break;}
    case 4:{
        ui->label_12->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_12, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 170, 70, 50));
        animation1->setEndValue(QRect(440, 170, 70, 50));
        animation1->start();
        break;}
    case 5:{
        ui->label_13->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_13, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 280, 70, 50));
        animation1->setEndValue(QRect(160, 280, 70, 50));
        animation1->start();
        break;}
    case 6:{
        ui->label_14->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_14, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 280, 70, 50));
        animation1->setEndValue(QRect(440, 280, 70, 50));
        animation1->start();
        break;}
    case 7:{
        ui->label_15->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_15, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 390, 70, 50));
        animation1->setEndValue(QRect(160, 390, 70, 50));
        animation1->start();
        break;}
    case 8:{
        ui->label_16->setStyleSheet("QLabel{border:2px solid rgb(0, 255, 0);}");
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_16, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(320,5,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 390, 70, 50));
        animation1->setEndValue(QRect(440, 390, 70, 50));
        animation1->start();
        break;}
    }
}

void MainWindow::moveout(int k){
    switch(k){
    case 1:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_9, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(160,65,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 65, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        /*ui->label_9->setStyleSheet("QLabel{border:0px}");
        ui->label_9->setText("")*/;
        break;}
    case 2:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_10, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(440,65,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 65, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 3:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_11, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(160,170,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 170, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 4:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_12, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(440,170,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 170, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 5:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_13, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(160,280,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 280, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 6:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_14, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(440,280,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 280, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 7:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_15, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(160,390,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 390, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    case 8:{
        QPropertyAnimation *animation1 =new QPropertyAnimation(ui->label_16, "geometry");
        animation1->setDuration(3000);
        animation1->setStartValue(QRect(440,390,70,50));
        animation1->setKeyValueAt(0.4,QRect(320, 390, 70, 50));
        animation1->setEndValue(QRect(320, 500, 70, 50));
        animation1->start();
        break;}
    }
}
