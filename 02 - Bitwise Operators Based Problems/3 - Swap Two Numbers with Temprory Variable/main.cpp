// Description: Write a function to swap two numbers without using a temporary variable using bitwise operators.

#include <iostream>
using namespace std;

void function(int n1, int n2){
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
   cout<<"The value of n1 is : "<<n1<<endl;
   cout<<"The value of n2 is : "<<n2<<endl;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    cout<<"------>Before Swap<------"<<endl;
    cout<<"The value of n1 is : "<<num1<<endl;
    cout<<"The value of n2 is : "<<num2<<endl;
    cout<<"------>After Swap<------"<<endl;
    function(num1, num2);
    return 0;
}



