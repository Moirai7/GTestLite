
#ifndef MYTESTCLASS_H
#define MYTESTCLASS_H

class MyTestClass
{
public:
    MyTestClass();
    ~MyTestClass();
	
	void UseBadPointer() const;
    void DivideByZero() const;
    void ThrowException() const;
	
    
    static int s_currentInstances;
    static int s_instancesCreated;
    static int s_maxSimultaneousInstances;
};


#endif
