// Approach 1 : Division Method
#include <iostream>
#include <math.h>
using namespace std;

int decimal_to_binary(int n){
    int binary = 0;
    int i = 0;
    while(n){
        int bit = n & 1;
        binary = (bit * pow(10, i)) + binary;
        n = n >> 1;
        i = i + 1;
    }
    return binary;
}

int main() {
    int decimal = 13;
    int output = decimal_to_binary(decimal);
    cout<<"Binary of "<<decimal<<" is : "<<output;
    return 0;
}


