// array implementation of a stack

#include "myExceptions.h"
#include <sstream>

template<class T>
class arrayStack {
   public:
      arrayStack(int initialCapacity = 10);
      ~arrayStack() {delete [] stack;}
      bool empty() const {return stackTop == -1;}
      int size() const {return stackTop + 1;}
      T& top() {
	 if (stackTop == -1) throw myException("stack empty");
         return stack[stackTop];
      }
      void pop() {
         if (stackTop == -1) throw myException("stack empty");
         stackTop--;  
      }
      void push(const T& theElement);
   private:
      int stackTop;         // current top of stack
      int arrayLength;      // stack capacity
      T *stack;             // element array
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1) throw myException("illegal Parameter Value");
   arrayLength = initialCapacity;
   stack = new T[arrayLength];
   stackTop = -1;
}

template<class T>
void arrayStack<T>::push(const T& theElement)
{// Add theElement to stack.
   if (stackTop == arrayLength - 1) throw myException("stack full");
   stack[++stackTop] = theElement;
}
