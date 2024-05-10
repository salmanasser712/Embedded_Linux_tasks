#include <iostream>


//abstract class : it's a class that has one or more pure 
// virtual methods, can't be instantiated
class Device {
    public:
    //pure virual function, doesn't have an implementation
    virtual void setModelNumber(int num) = 0;
};

class Mobile : public Device{
    public:
    void setModelNumber(int num) override{
        this->modelNo = num;
    }

    int modelNo;
};