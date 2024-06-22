#include <iostream>
#include <string>
using namespace std;

int main() {
 int n;
 cin>>n;
 n = n * - 1;
 string binary = "";
 
 while(n){
     int bit = n & 1;
     binary = to_string(bit) + binary;
     n = n >> 1;
 }
 string oneComp = "";
 for(char c : binary){
     int bit = c - '0';
     oneComp += (bit == 0 ? '1' : '0');
 }
 int carry = 1;
 for (int i = oneComp.size() - 1; i >= 0; i--){
     int bit = oneComp[i] - '0' + carry;
     oneComp[i] = (bit % 2) + '0';
     carry = bit / 2;
 }
 cout<<oneComp;
   
    return 0;
}
