// Description: Write a function to check if a given integer is a power of two using bitwise operators.

#include <iostream>
using namespace std;

string power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0 ? "True" : "False";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    string output = power_of_two(n);
    cout << "Is the number a power of two: " << output << endl;
    return 0;
}
