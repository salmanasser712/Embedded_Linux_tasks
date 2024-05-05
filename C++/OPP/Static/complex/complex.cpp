#include <iostream>
#include "complex.h"

int Complex::instance_counter;

Complex::Complex(int real, int img):
m_real{real}, m_img{img}{
    ++instance_counter;
}

int Complex:: getNuminstance(){
    return instance_counter;
}

int main(){
    Complex c1(2, 3);
    Complex c2(4, 6);
    std::cout << "instances " << Complex::getNuminstance() << std::endl;
    return 0;
}