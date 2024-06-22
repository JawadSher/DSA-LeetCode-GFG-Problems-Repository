// Description: Write a function to count the number of 1s (set bits) in the binary representation of a given integer.

#include <iostream>
using namespace std;

// Approach One 
// int function(int n){
//     int count = 0;
//     while(n){
//         if (n & 1){
//             count++;
//         }
//         n = n >> 1;
//     }
//     return count;
// }

// Approach Two
int function(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n = n >> 1;
    }
    return count;
}
// # Output: 3 (binary representation: 111 of Decimal 7)

int main() {
    int number;
    cin>> number;
    int output = function(number);
    cout<<"The no of 1s in "<<number<<" in Binary : "<<output<<endl;

    return 0;
}



