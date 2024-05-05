#include "Oven.h"

static int MaxTemperature(int temp){
    static int max = 0;  // static local variable
    max = (max > temp? max: temp);
    return max;
}