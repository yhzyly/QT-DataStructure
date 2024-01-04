#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Floyed.cpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
//using namespace std;
//#include "myglwidget.h"

Mg g;
string* spot;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Read file and create the graph
    ifstream data("E:\\Qt\\data.txt"); //待读取文件的目录
       vector<int> res;
       string line;
       while (getline(data, line)) {
           stringstream ss; //输入流
           ss << line; //向流中传值
           if (!ss.eof()) {
               int temp;
               while (ss >> temp) //提取int数据
                   res.push_back(temp); //保存到vector
           }
       }
    //赋值
    int len=1;
    g.n=res[0];
    g.e=res[1];
    int i,j;
    for(i=0; i<g.n; i++)
        for(j=0; j<g.n; j++)
        {
            if(i==j)
                A[i][j]=0;
            else
                A[i][j]=INF;
        }
    for(i=g.e; i>0; i--)
    {
        int v1,v2,Q;
        v1=res[++len];
        v2=res[++len];
        Q=res[++len];
        g.edges[v1][v2]=Q;
    }
    floyd(g);

//Read the information file for every scene
    spot=new string[3*g.n+1];
    int cou=0;
    ifstream infile("E:\\Qt\\scene.txt",ios::in);
    while(cou<3*g.n){
        infile>>spot[++cou];
    }
    infile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    QString str1=ui->textEdit->toPlainText();
    QString str2=ui->textEdit_2->toPlainText();

    int start= str1.toInt()-1;
    int end= str2.toInt()-1;

    ppath(start,end);
    ui->textEdit_3->setText(str1);
    for(int i=1;i<=flag;++i){
        ui->textEdit_3->append("->" + QString::number(c[i]+1));
    }
    ui->textEdit_3->append("->"+str2);
    ui->textEdit_3->append("最短路径长度: "+QString::number(A[start][end]));
    flag=0;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_3->setText("地点详情:"+QString::fromStdString(spot[1]));
    ui->textEdit_3->append("推荐活动:"+QString::fromStdString(spot[2]));
    ui->textEdit_3->append("星级评价:"+QString::fromStdString(spot[3]));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_3->setText("地点详情:"+QString::fromStdString(spot[4]));
    ui->textEdit_3->append("推荐活动:"+QString::fromStdString(spot[5]));
    ui->textEdit_3->append("星级评价:"+QString::fromStdString(spot[6]));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_3->setText("地点详情:"+QString::fromStdString(spot[7]));
    ui->textEdit_3->append("推荐活动:"+QString::fromStdString(spot[8]));
    ui->textEdit_3->append("星级评价:"+QString::fromStdString(spot[9]));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit_3->setText("地点详情:"+QString::fromStdString(spot[10]));
    ui->textEdit_3->append("推荐活动:"+QString::fromStdString(spot[11]));
    ui->textEdit_3->append("星级评价:"+QString::fromStdString(spot[12]));
}

void MainWindow::on_pushButton_6_clicked()
{
    QString str=ui->textEdit->toPlainText();
    int start=str.toInt()-1;
    ui->textEdit_3->setText(QString::fromStdString(Prim(g,start)));
}
