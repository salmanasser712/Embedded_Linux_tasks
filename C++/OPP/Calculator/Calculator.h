#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
    public:
    Calculator() = default;
    virtual ~Calculator() = default;
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
    virtual void Display() = 0;

};



#endif