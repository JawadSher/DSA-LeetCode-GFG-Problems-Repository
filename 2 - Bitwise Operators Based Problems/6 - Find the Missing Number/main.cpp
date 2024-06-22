// Description: Given an array containing n distinct numbers taken from the range [0, n], find the one number that is missing from the array using bitwise operators.

#include <iostream>
using namespace std;

int find_missing_number(int nums[], int n) {
    int xor_sum = 0;
    
    for (int i = 0; i <= n; i++){
        xor_sum ^= i;
    }
    for (int i = 0; i < n; i++){
        xor_sum ^= nums[i];
    }
    return xor_sum;
}

int main() {
    int nums[] = {3, 0, 1, 4}; // Array with one number missing
    int size = sizeof(nums) / sizeof(nums[0]);
    int missing_number = find_missing_number(nums, size);
    cout << "The missing number is: " <<missing_number << endl;
    return 0;
}
