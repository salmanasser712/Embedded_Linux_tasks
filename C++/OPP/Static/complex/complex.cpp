#include <iostream>
#include "complex.h"

int Complex::instance_counter;

Complex::Complex(int real, int img):
m_real{real}, m_img{img}{
    ++instance_counter;
}

Complex Complex:: operator +(const Complex &obj){
    Complex result;
    result.m_real = this->m_real + obj.m_real;
    result.m_img = this->m_img + obj.m_img;
    return result;
}
std::ostream& operator<<( std::ostream& os, const Complex& obj){
    os << obj.m_real << " " << obj.m_img << "\n";
    return os;
}

int Complex:: getNuminstance(){
    return instance_counter;
}

int main(){
    Complex c1(2, 37);
    Complex c2(7, 15);
    Complex c3 = c1 + c2;
    std::cout << "result " << c3 << std::endl;
    return 0;
}