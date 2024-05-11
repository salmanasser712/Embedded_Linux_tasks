#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include "Calculator.h"

class CalculatorBase : public Calculator{
    public:

    void add() override{
        double x, y;
        std::cout << "Please Enter 2 numbers to add:\n";
        std::cin >> x >> y;
        std::cout << "The result: " << x + y << std::endl;
    }

    void sub() override{
        double x, y;
        std::cout << "Please Enter 2 numbers to subtract:\n";
        std::cin >> x >> y;
        std::cout << "The result: " << x - y << std::endl;
    }

    void Display() override{
        std::cout << "Basic Calculator operation\n";
    }

};

class ProgrammerCalculator : public CalculatorBase{
    public:
    // conversion between numbering system
    //HEX TO DECIMAL
    void hexaToDecimal() {
        std::cout << "Please enter the Hexadecimal number :\n";
        std::string hexVal;
        std::cin >> hexVal;

        int len = hexVal.size(); 
        int base = 1; 
        int dec_val = 0; 
        for (int i = len - 1; i >= 0; i--) { 
            if (hexVal[i] >= '0' && hexVal[i] <= '9') { 
                dec_val += (int(hexVal[i]) - 48) * base;
            }
            else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') { 
                dec_val += (int(hexVal[i]) - 55) * base; 
            }
            base = base * 16; 
        }

        std::cout << "The result = " << dec_val << std::endl;
    }

    //DECIMAL TO HEX

    void decimalToHexa(){

        std::cout << "Please enter the decimal number :\n";
        int num;
        std::cin >> num;

        std::string s = "";
        while (num != 0) { 
            int temp = 0; 
            temp = num % 16;
            if (temp < 10){
                char c = temp + 48;
                s += c;
            }
            else{
                char c = temp + 55;
                s += c;
            }
            num/=16;
        }
        std::reverse(s.begin(), s.end());

        std::cout << "The result = " << s << std::endl;
    }

    void Display() override{
        std::cout << "Programming Calculator operation\n";
    }

};

class ScientificCalculator : public CalculatorBase{
    public:
    void sin_ang(){
        float angle_degrees;
        std::cout << "Please enter the angle.\n";
        std::cin >> angle_degrees;
        double angle_radians = angle_degrees * M_PI / 180.0;
        std::cout << "The result: " << sin(angle_radians) << std::endl;
    }
    void cos_ang(){
        float angle_degrees;
        std::cout << "Please enter the angle.\n";
        std::cin >> angle_degrees;
        double angle_radians = angle_degrees * M_PI / 180.0;
        std::cout << "The result: " << cos(angle_radians) << std::endl;
    }

    void Display() override{
        std::cout << "Scientifinc Calculator operation\n";
    }
};

int main(){
    CalculatorBase *Cal;
    int tries = 3;
    while(tries){
        char c;
        std::cout << "Choose which calculator to use (Regular Calculator -> C, Scientific -> S, Programming -> P, Exit -> E):\n";
        std::cin >> c;
        if(c == 'C'){
            Cal = new CalculatorBase;
            std::cout << "Choose an operation (subtracting -> S, adding -> A):\n";
            std::cin >> c;
            if(c == 'S'){
                Cal->sub();
            }
            else if(c == 'A'){
                Cal->add();
            }
            else{
                tries--;
                std::cout << "Wrong choice, number of tries left = " << tries << "\n";
                continue;
            }
        }
        else if(c == 'S'){
            Cal = new ScientificCalculator;
            ScientificCalculator * Casted_Cal = dynamic_cast<ScientificCalculator *>(Cal);
            std::cout << "Choose an operation (Sin of an angle -> S, Cosine of an angle -> C):\n";
            std::cin >> c;
            if(c == 'S'){
                Casted_Cal->sin_ang();
            }
            else if(c == 'C'){
                Casted_Cal->cos_ang();
            }
            else{
                tries--;
                std::cout << "Wrong choice, number of tries left = " << tries << "\n";
                continue;
            }
        }
        else if(c == 'P'){
            Cal = new ProgrammerCalculator;
            ProgrammerCalculator * Casted_Cal = dynamic_cast<ProgrammerCalculator *>(Cal);
            std::cout << "Choose an operation (Hexa to Decimal -> H, Decimal to Hexa -> D):\n";
            std::cin >> c;
            if(c == 'H'){
                Casted_Cal->hexaToDecimal();
            }
            else if(c == 'D'){
                Casted_Cal->decimalToHexa();
            }
            else{
                tries--;
                std::cout << "Wrong choice, number of tries left = " << tries << "\n";
                continue;
            }
        }
        else if(c == 'E'){
            break;
        }
        else{
            tries--;
            std::cout << "Wrong choice, number of tries left = " << tries << "\n";
            continue;
        }

        tries = 3;
    }

    return 0;
}