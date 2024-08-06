#include<iostream>
using namespace std;

int peak_index(int arr[], int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) /2;
    int index = -1;
    
    while(start < end){
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid -1]){
            index = mid;
            return index;
        }else if(arr[mid] < arr[mid - 1]){
            end = mid -1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return index;
}


int main(){
    int new_array[] = {10, 20, 30, 50, 60, 70, 50, 40, };
    int size = sizeof(new_array) / sizeof(int);
    
    cout<<"The peak index is : "<<peak_index(new_array, size);

    
    return 0;
}
