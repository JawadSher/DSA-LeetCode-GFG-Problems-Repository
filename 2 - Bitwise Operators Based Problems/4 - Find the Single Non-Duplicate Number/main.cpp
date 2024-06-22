// Description: Given a list of integers where every element appears twice except for one, find the single element that appears only once using bitwise operators.

#include <iostream>
using namespace std;

int singleNonDuplicate(int arr[], int s) {
    int result = 0;
    for (int i = 0; i < s; i++) {
        result = result ^ arr[i];
    }
    return result;
}

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int size = sizeof(arr) / sizeof(int);
    int result = singleNonDuplicate(arr, size);
    cout << "The single non-duplicate element is: " << result << endl;
    return 0;
}
