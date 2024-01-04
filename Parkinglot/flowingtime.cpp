#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;

class TimeCounter{
    private:
    // time_t now=time(0);

    public:
    string t="";

    string gettime(time_t t){
        char* dt=ctime(&t);//There is an EnterSpace at the end of this string
        return dt;
    }

    void printtime(){
            time_t now=time(0);
            tm* localtm = localtime(&now);
            t="Time: "+to_string(localtm->tm_hour)+":"+to_string(localtm->tm_min)+":"+to_string(localtm->tm_sec);
    }
};


