#include <iostream>
#include "QueuedInterface.h"
#include "InterfaceQ.h"

InterfaceQ::InterfaceQ():_isRunning(false)
{
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_cond, NULL);
}
InterfaceQ::~InterfaceQ()
{   
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_cond); 
}

InterfaceQ::InterfaceQ(const InterfaceQ& rhs)
{
}

InterfaceQ& InterfaceQ::operator=(const InterfaceQ& rhs)
{
    return *this;
}

void InterfaceQ::setRunning(bool isRunning)
{
    _isRunning = isRunning;
}
void InterfaceQ::run()
{
    int ret = pthread_create(&_thread, NULL, (void *(*)(void *))&threadEntry, (void *)this);
}

void InterfaceQ::threadEntry(InterfaceQ* pIQ)
{
    pIQ->main_func();
}

void InterfaceQ::main_func()
{
    while(_isRunning)
    {
        pthread_mutex_lock(&_mutex);
        std::cout << "waiting for msg..." << std::endl;
        while(_messageQueue.empty())
        {
            pthread_cond_wait(&_cond, &_mutex);
        }
        QueueMsg msg = _messageQueue.front(); 
        _messageQueue.pop();
        pthread_mutex_unlock(&_mutex);
        //std::cout << "received: "<<str<<std::endl;
        (msg.pInterface)->sendMsgActual(msg.str);

    }
}



void InterfaceQ::sendMsg(QueueMsg& msg)
{
    pthread_mutex_lock(&_mutex);
    _messageQueue.push(msg);
    pthread_mutex_unlock(&_mutex);
    pthread_cond_signal(&_cond);
}