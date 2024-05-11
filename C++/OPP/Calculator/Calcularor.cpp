#include<iostream>
#include "Calculator.h"

class CalculatorBase : public Calculator{
    public:

    int add(int x, int y) override{
        return x + y;
    }

    int sub(int x, int y) override{
        return x - y;
    }

};

class ProgrammerCalculator : public CalculatorBase{
    public:
    // conversion between numbering system
    //HEX TO DECIMAL

    //DECIMAL TO HEX
};

class ScientificCalculator : public CalculatorBase{
    float sinc(float angle){

    }

    void Display() override{
        std::cout << "Scientifinc Calculator operation\n";
    }
};