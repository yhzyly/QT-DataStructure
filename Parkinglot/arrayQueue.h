#include <stdlib.h>
#include <iostream>
#include "myExceptions.h"

template<class T>
class arrayQueue {
  private:
    int front; //one counterclockwise from first
    int rear;  // last element
    int MaxSize; // size of array queue
    T *queue;    // element array   
  public:
    arrayQueue(int MaxQueueSize = 10);
    ~arrayQueue() {delete [] queue;}
    bool IsEmpty() {return front == rear;}
    bool IsFull()  {return (rear + 1) % MaxSize == front;}
    T First(); // return front element
    T Last();  // return last element
    void EnQueue(T x);
    void DeQueue();
};

template<class T>
arrayQueue<T>::arrayQueue(int MaxQueueSize){
  MaxSize = MaxQueueSize + 1;
  queue = new T[MaxSize];
  front = rear = 0;
}

template<class T>
T arrayQueue<T>::First() {
  if (IsEmpty()) throw myException("Out of bounds");
  return queue[(front + 1) % MaxSize];
}

template<class T>
T arrayQueue<T>::Last() {
  if (IsEmpty()) throw myException("Out of bounds");
  return queue[rear];
}

template<class T>
void arrayQueue<T>::EnQueue(T x){
  if (IsFull()) throw myException("Out of space");
  rear = (rear + 1) % MaxSize;
  queue[rear] = x;
}

template<class T>
void arrayQueue<T>::DeQueue(){
  if (IsEmpty()) throw myException("Out of bounds");
  front = (front + 1) % MaxSize;
}

