#ifndef QUEUEDINTERFACE_H
#define QUEUEDINTERFACE_H

#include <string>

class InterfaceQ;

class QueuedInterface
{
public:
    QueuedInterface(InterfaceQ * pIQ);
    virtual ~QueuedInterface();
    virtual void sendMsg(std::string& str);
    virtual void sendMsgActual(std::string& str)=0;
protected:
    InterfaceQ* _pIQ;
};

#endif

