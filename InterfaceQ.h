#ifndef INTERFACEQ_H
#define INTERFACEQ_H

#include <pthread.h>
#include <queue>
#include <string>

class QueuedInterface;
struct QueueMsg
{
    QueuedInterface *pInterface;
    std::string str;
};

class InterfaceQ
{
public:
    InterfaceQ();
    ~InterfaceQ();
    InterfaceQ(const InterfaceQ& rhs);
    InterfaceQ& operator=(const InterfaceQ& rhs);
    void setRunning(bool isRunning);
    void run();
    void sendMsg(QueueMsg& msg);
private:
    pthread_t _thread;
    bool _isRunning;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
    std::queue<QueueMsg> _messageQueue;
    void main_func();
    static void threadEntry(InterfaceQ* pIQ);
};

#endif