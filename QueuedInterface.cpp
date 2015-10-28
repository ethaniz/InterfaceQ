#include "QueuedInterface.h"
#include "InterfaceQ.h"
#include <string>

QueuedInterface::QueuedInterface(InterfaceQ* pIQ)
{
    _pIQ = pIQ;
}

QueuedInterface::~QueuedInterface()
{

}

void QueuedInterface::sendMsg(std::string& str)
{
    QueueMsg msg;
    msg.pInterface = this;
    msg.str = str;
    _pIQ->sendMsg(msg);
}