#include<iostream>
#include<sstream>
#include"arrayStack.h"
// #include"Calculator.cpp"
using namespace std;

arrayStack<float> s1;
arrayStack<char> s2;

//Define the priority level of the operator
int instack(char ch){//inner stack
    switch(ch){
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 3;
        case '*':
        case '/':
        case '%':return 5;
        case ')':return 6;//just used in suffix expression
        default :return -1;
    }
}

int outstack(char ch){//out of the stack
    switch(ch){
        case '#':return 0;
        case '(':return 6;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 4;
        case ')':return 1;
        default :return -1;
    }
}

//Basic calculation method
//These methods do not pop the operator character
void add(){
    float left,right;
    right=s1.top();
    s1.pop();
    left=s1.top();
    s1.pop();                       
    s1.push(left+right);
}

void minuss(){
    float left,right;
    right=s1.top();
    s1.pop();
    left=s1.top();
    s1.pop();                       
    s1.push(left-right);
}

void multiply(){
    float left,right;
    right=s1.top();
    s1.pop();
    left=s1.top();
    s1.pop();                       
    s1.push(left*right);
}

void divide(){
    float left,right;
    right=s1.top();
    s1.pop();
    left=s1.top();
    s1.pop();                       
    s1.push(left/right);
}

void count(){
    switch(s2.top()){
        //s2.pop();
        case '+':
        add();
        break;
        case '-':
        minuss();
        break;
        case '*':
        multiply();
        break;
        case '/':
        divide();
        break;
    }
}

void braket(){
    while(s2.top()!='('){
        count();
        if(s2.empty()){
            cout<<"Invalid braket was used."<<endl;
        }
        s2.pop();
    }
}

float calculate(string str){
    // sta.pop();
    s2.push('#');
    //s2.pop();
    float num=0;
    string s="";
    int j=str.length();
    for(int i=0;i<=j;i++){
        if(isdigit(str[i])||str[i]=='.'){
            s=s+str[i];
        }else if(isspace(str[i])){
            continue;
        }else{
            num=atof(s.c_str());
            s="";
            s1.push(num);
            //switch(str[i]){
            if(instack(s2.top())>outstack(str[i])){
                switch(s2.top()){
                    case '+':
                    add();
                    break;
                    case '-':
                    minuss();
                    break;
                    case '*':
                    multiply();
                    break;
                    case '/':
                    divide();
                    break;
                    case '%':
                    break;
                    case ')':
                    braket();
                }
                s2.pop();
            }
            if(instack(s2.top())<outstack(str[i])){
                s2.push(str[i]);
                cout<<s2.top();
            }
        }
    }
    float res=0;
    while(!s2.empty()){
        count();
        if(s2.top()=='#'){
            res=s1.top();
            // s1.pop();
            // if(!s1.empty()){
            //     cout<<"Error in operand!"<<endl;
            //     return 0;
            }
        s2.pop();
        // return res;
    }
    //float res2=res;
    s1.pop();
    // if(!s1.empty()){
    //     cout<<"Error in operand!"<<endl;
    //     return 0;
    // }
    return res;
}
