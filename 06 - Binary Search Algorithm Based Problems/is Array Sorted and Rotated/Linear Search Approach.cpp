#include <iostream>
using namespace std;

bool is_rotated_sorted(int arr[], int n){
    int rotation = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > arr[(i + 1)%n]){
            rotation++;
        }
        
        if(rotation > 1){
            return false;
        }
    }
    return true;
}

int main() {
    int new_array[] = {2,1,3,4};
    int size = sizeof(new_array) / sizeof(new_array[0]);
    
    bool is_true = is_rotated_sorted(new_array, size);
    string status = (is_true) ? "True" : "False";
    cout<<"Rotated & Sorted : "<<status;

    return 0;
}
