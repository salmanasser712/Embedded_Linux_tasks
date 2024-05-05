

#include <iostream>
#include "Oven.h"

static int global_var = 10;  //.data

int main(){
    while(1){
        int t = 0;
        std::cin >> t;
        int maxTemp = MaxTemperature(t);
        std::cout << "max temperture is " << maxTemp << std::endl;
    }
}