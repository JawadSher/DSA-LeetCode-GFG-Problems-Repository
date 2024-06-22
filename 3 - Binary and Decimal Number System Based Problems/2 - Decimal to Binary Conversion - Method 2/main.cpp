// Approach two
#include <iostream>
#include <string>
using namespace std;

string decimal_to_binary(int n) {
    string binary = "";
    while(n){
        int bit = n & 1;
        binary = to_string(bit) + binary;
        n = n >> 1;
    }
    return binary;
}

int main() {
    int decimal = 10000;
    string output = decimal_to_binary(decimal);
    cout << "Binary of " << decimal << " is : " << output << endl;
    return 0;
}
