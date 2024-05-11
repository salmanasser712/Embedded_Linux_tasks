#include <iostream>
#include <cmath>
#include "Point.h"

void Point:: cartesianToPolar(){
    if(this->availabe == 1){
        this->availabe = 3;
        double &x = this->Cart_x, &y = this->Cart_y, &r = this->Polar_r, &q = this->Polar_q;
        r = sqrt(x * x + y * y);
        q = atan(y / x);
    }
    else{
        if(this->availabe == 2){
            std::cout << "You didn't set Cartesian point!\n";
        }
        else{
            std::cout << "You already converted this Cartesian point.\n";
        }
    }
}
void Point:: polarToCartesian(){
    if(this->availabe == 2){
        this->availabe = 3;
        double &x = this->Cart_x, &y = this->Cart_y, &r = this->Polar_r, &q = this->Polar_q;
        x = r * cos(q);
        y = r * sin(q);
    }
    else{
        if(this->availabe == 1){
            std::cout << "You didn't set Polar point!\n";
        }
        else{
            std::cout << "You already converted this Polar point.\n";
        }
    }
}

void Point:: setCartesian(double x, double y){
    this->availabe = 1;
    this->Cart_x = x;
    this->Cart_y = y;
}
void Point:: setPolar(double r, double q){
    this->availabe = 2;
    this->Polar_r = r;
    this->Polar_q = q;
}

void Point:: DisplayPoint(){
    if(this->availabe == 1){
        std::cout << "Cartesian point: x = " << this->Cart_x << ", y = " << this->Cart_y << ".\n";
    }
    else if(this->availabe == 2){
        std::cout << "Polar point: r = " << this->Polar_r << ", q = " << this->Polar_q << ".\n";
    }
    else{
        std::cout << "Cartesian point: x = " << this->Cart_x << ", y = " << this->Cart_y << ".\n";
        std::cout << "Polar point: r = " << this->Polar_r << ", q = " << this->Polar_q << ".\n";
    }
}


int main(){
    Point a;
    a.setPolar(16, 30);
    a.polarToCartesian();
    a.DisplayPoint();
    return 0;
}
