#include <iostream>
using namespace std;

string function(int n){
    return (n & 1) == 0 ? "Even" : "Odd";
}

int main() {
    int number;
    cin>> number;
    string output = function(number);
    cout<<"The number is : "<<output<<endl;

    return 0;
}

