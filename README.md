# InterfaceQ
A C++ Implementation of event driven InterfaceQ and QueuedInterface

##InterfaceQ
A C++ encapsulation of Linux POSIX thread with a blocking queue. The main function of the thread will be a infinit loop and blocking on receive. When a message coming, it will change the thread content.

##QueuedInterface
A interface which is the base class of all users. The users who want to use the event driven thread can inherit the interface and specialize the sengMsgActual() function