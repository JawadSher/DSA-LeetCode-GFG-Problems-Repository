#include<iostream>
using namespace std;

int pivot_index(int arr[], int n){
    int start = 0;
    int end =  n - 1;
    int mid = start + (end - start)/2;
    
    while(start < end){
        if(arr[mid] >= arr[0]){
            start = mid + 1; 
        }else{
            end = mid;
        }
        
        mid = start + (end - start)/2;
    }
    return start;
}

int main(){
    int new_array[] = {10, 20, 30, 1, 2, 3};
    int size = sizeof(new_array) / sizeof(int);
    
    int index = pivot_index(new_array, size);
    cout<<"The Pivot Point Index is : "<<index;
    return 0;
}
