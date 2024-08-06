#include<iostream>
using namespace std;

int pivot_point(int arr[], int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int binary_search(int arr[], int s, int e, int key){
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    
    while(start < end){
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return mid;
}

int main(){
    int new_array[] = {10, 20, 30, 1, 2, 3};
    int size = sizeof(new_array) / sizeof(int);
    int key = 1;
    
    int pivot = pivot_point(new_array, size);
    if(key >= new_array[pivot] && key <= new_array[size - 1]){
        cout<<"Element Found on Index : "<<binary_search(new_array, pivot, size -1, key);
    }else{
        cout<<"Element Found on Index : "<<binary_search(new_array, 0, pivot -1, key);
    }
   
    
    return 0;
}
