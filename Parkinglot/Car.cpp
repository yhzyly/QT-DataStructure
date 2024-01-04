#include<iostream>
#include<vector>
using namespace std;

class Car{
private:
    vector<string> number1={"京","闵","浙","津","沪","湘","冀"};
    vector<string> number2={"A","B","C","D"};
    vector<string> number3={"803L5","511E0","50X55","831A9","253B7","652C2","66C66"};
    vector<string> brand={"比亚迪","吉利","东风","一汽","荣威","长安"};

public:
    string getcar(){
        return brand[rand()%6]+": "+number1[rand()%7]+number2[rand()%4]+number3[rand()%7];
    }
};
