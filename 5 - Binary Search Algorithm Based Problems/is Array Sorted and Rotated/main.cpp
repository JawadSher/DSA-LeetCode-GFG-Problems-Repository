// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool is_rotated_sorted(int arr[], int n){
    int start = 0;
    int end = n - 1;
    
    while(start <= end){
        int mid = start + (end - start)/2;
        
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    
    int rotation = 0;
    
    for(int i = 0; i < n-1; i++){
        if(arr[(rotation + i)%n] > arr[(rotation + i + 1)%n]){
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
