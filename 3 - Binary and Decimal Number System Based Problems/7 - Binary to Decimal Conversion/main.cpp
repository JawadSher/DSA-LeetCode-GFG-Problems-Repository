#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int binary = -10101;
    bool isNegative = binary < 0;
    if(isNegative){
        binary = -binary;
    }
    
    int decimal = 0;
    int i = 0;
    while(binary){
        int digit = binary % 10;
        if(digit == 1){
            
            decimal += pow(2, i);
        }
        binary = binary / 10;
        i++;
    }
    
    if(isNegative){
        decimal = -decimal;
    }
    cout<<"The Decimal is : "<<decimal;

    return 0;
}
