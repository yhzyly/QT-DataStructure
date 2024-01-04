#include "mainwindow.h"
#include<iostream>
// #include"arrayStack.h"
// #include"Solution.cpp"
//#include"cal.cpp"
#include<string>
using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    string str;
//    cout<<"Entering the expression you want to calculate:"<<endl;
//    cin>>str;
//    //cout<<str;
//    float result=calculate(str);
//    cout<<result<<endl;

    return a.exec();
}
