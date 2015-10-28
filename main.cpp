#include "InterfaceQ.h"
#include "QueuedInterface.h"
#include <string>
#include <iostream>
#include <unistd.h>

class MyUser : public QueuedInterface
{
public:
    MyUser(InterfaceQ *pIQ);
    ~MyUser();
    virtual void sendMsgActual(std::string& str);
};


MyUser::MyUser(InterfaceQ *pIQ):QueuedInterface(pIQ)
{

}

MyUser::~MyUser()
{

}

void MyUser::sendMsgActual(std::string& str)
{
    std::cout << "received: " << str << std::endl;
}



int main()
{
    std::cout << "Main thread start..." << std::endl;
    InterfaceQ IQ = InterfaceQ();
    IQ.setRunning(true);
    IQ.run();

    MyUser myUser = MyUser(&IQ);

    std::string str = "hello";
    myUser.sendMsg(str);

    std::string str2 = "world";
    myUser.sendMsg(str2);

    std::string str3 = "c++";
    myUser.sendMsg(str3);

    sleep(3);

}