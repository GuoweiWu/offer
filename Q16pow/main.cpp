#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;


double powerWithUnsignedExponent(double base , unsigned int exponent){
    if (exponent == 0)  
    {
        return 1;
    }
    if (exponent == 1)
    {
        return base;
    }
    // >>1 = /2
    double result = powerWithUnsignedExponent(base , exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1){
        result *= base;
    }
    return result;
    
}
int main(){
    
}