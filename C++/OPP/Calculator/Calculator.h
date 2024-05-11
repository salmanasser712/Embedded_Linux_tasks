#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
    public:
    Calculator() = default;
    virtual ~Calculator() = default;
    virtual void add() = 0;
    virtual void sub() = 0;
    virtual void Display() = 0;

};



#endif