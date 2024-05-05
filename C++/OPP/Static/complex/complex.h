#pragma once

class Complex{
    public:
    Complex(int real = 0, int img = 0);

    static int getNuminstance();

    private:
    static int instance_counter;
    int m_real;
    int m_img;


};