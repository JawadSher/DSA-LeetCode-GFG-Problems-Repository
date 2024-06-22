// Approach three
#include <iostream>
using namespace std;

int decimal_to_binary(int n) {
    if (n == 0){
        return -1;
    }
    cout << "Binary of " << n << " is : ";
    
    int binary[32];
    int index = 0;
    while(n){
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }
    for(int i = index - 1; i >= 0; i--){
        cout<<binary[i];
    }
    return 0;
}

int main() {
    int decimal = 10000;
    decimal_to_binary(decimal);
    return 0;
}
