#include <string>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){this->data = value;};
};
//创建一个约瑟夫环的类
class JosephCircle{
private:
    Node* tail;	//尾结点
    //Node* eliminate;	//淘汰结点
public:
    JosephCircle():tail(NULL){}
    ~JosephCircle(){delete tail;}
    void Add(int num);
    void Eliminate(int step);
    void Print();
    int getData();
};

void JosephCircle::Add(int num){
    if(tail == NULL){
        tail = new Node(num);
        tail->next = tail;
    }
    else{
        Node* new_node = new Node(num);
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
}

void JosephCircle::Eliminate(int step){
    Node* p = tail;
    while(p != NULL && p != p->next){
        for(int i = 0;i < step-1;i++){
            p = p->next;
        }
        Node* eliminate = p->next;
        p->next = eliminate->next;
        if(eliminate == tail){
            tail = p;
        }
        cout<<"deleting"<<eliminate->data<<endl;
        delete eliminate;
        Print();
    }
}

void JosephCircle::Print(){		//这打印还是有点说法的
    Node* cur = tail;
    while(cur != NULL){
        cur = cur->next;
        cout<<cur->data<<"  ";
        if(cur == tail)
            break;
    }
    cout<<endl;
}

int JosephCircle::getData(){
    return tail->data;
}
