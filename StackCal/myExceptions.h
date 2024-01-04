// exception classes
#ifndef myExceptions_
#define myExceptions_

#include <string>
using namespace std;

class myException{
   public:
      myException(string theMessage = "Exception occurred.")
          {message = theMessage;}
      string eMessage() {return message;}
   private:
      string message;
};
#endif
