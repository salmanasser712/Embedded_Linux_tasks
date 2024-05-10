#pragma once

class Complex{
    public:
    Complex(int real = 0, int img = 0);
    Complex operator +(const Complex &obj);

    friend std::ostream& operator<<(std::ostream& os, const Complex& obj);

    static int getNuminstance();

    private:
    static int instance_counter;
    int m_real;
    int m_img;


};