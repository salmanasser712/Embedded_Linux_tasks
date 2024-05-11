#include <iostream>
#include <cmath>
#include "Point.h"

void Point:: cartesianToPolar(){
    if(this->available == 1){
        this->available = 3;
        double &x = this->Cart_x, &y = this->Cart_y, &r = this->Polar_r, &q = this->Polar_q;
        r = sqrt(x * x + y * y);
        q = atan(y / x);
    }
    else{
        if(this->available == 2){
            std::cout << "You didn't set Cartesian point!\n";
        }
        else{
            std::cout << "You already converted this Cartesian point.\n";
        }
    }
}
void Point:: polarToCartesian(){
    if(this->available == 2){
        this->available = 3;
        double &x = this->Cart_x, &y = this->Cart_y, &r = this->Polar_r, &q = this->Polar_q;
        x = r * cos(q);
        y = r * sin(q);
    }
    else{
        if(this->available == 1){
            std::cout << "You didn't set Polar point!\n";
        }
        else{
            std::cout << "You already converted this Polar point.\n";
        }
    }
}

void Point:: setCartesian(double x, double y){
    this->available = 1;
    this->Cart_x = x;
    this->Cart_y = y;
}
void Point:: setPolar(double r, double q){
    this->available = 2;
    this->Polar_r = r;
    this->Polar_q = q;
}

void Point:: DisplayPoint(){
    if(this->available == 1){
        std::cout << "Cartesian point: x = " << this->Cart_x << ", y = " << this->Cart_y << ".\n";
    }
    else if(this->available == 2){
        std::cout << "Polar point: r = " << this->Polar_r << ", q = " << this->Polar_q << ".\n";
    }
    else if (this->available == 3){
        std::cout << "Cartesian point: x = " << this->Cart_x << ", y = " << this->Cart_y << ".\n";
        std::cout << "Polar point: r = " << this->Polar_r << ", q = " << this->Polar_q << ".\n";
    }
}

int Point::getaAvailable(){
    return this->available;
}

void Point::setAvailable(int num){
    this->available = num;
}


int main(){
    int tries = 3;
    Point point;
    while(tries){
        char c;
        double a, b;
        if(point.getaAvailable() == 0){
            std::cout << "choose the type of point you want to enter (C -> Cartesian, P -> Polar, E -> Exit):\n";
            std::cin >> c;

            if(c != 'C' &&  c != 'P' && c != 'E'){
                tries--;
                std::cout << "Wrong choice, number of tries left " << tries << ".\n";
                continue;
            }
            else if (c == 'E'){
                break;
            }
            std::cout << "Please enter the two coordinates: \n";
            std:: cin >> a >> b;

            if(c == 'C'){
                point.setCartesian(a, b);
            }
            else{
                point.setPolar(a, b);
            }
        }
        else{
            std::cout << "We have a stored point (Continue with it -> C, insert a new point - > I, Exit -> E):\n";
            std::cin >> c;
            if(c == 'C'){
                
            }
            else if (c == 'I'){
                point.setAvailable(0);
            }
            else if (c == 'E'){
                break;
            }
            else{
                tries--;
                std::cout << "Wrong choice, number of tries left " << tries << ".\n";
                continue;
            }
        }

        std::cout << "Please choose the type of opration (Cartesian to polar -> a, polar to Cartesian -> b, Display point -> c): \n";
        std::cin >> c;
        if(c == 'a'){
            point.cartesianToPolar();
            point.DisplayPoint();
        }
        else if(c == 'b'){
            point.polarToCartesian();
            point.DisplayPoint();
        }
        else if(c == 'c'){
            point.DisplayPoint();
        }
        else{
            tries--;
            std::cout << "Wrong choice, number of tries left " << tries << ".\n";
            continue;
        }
        tries = 3;

    } 
    return 0;
}
