#include<iostream>
using namespace std;

int missing_element(int arr[], int s){
    int start = 0;
    int end = s - 1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == mid){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main(){
    int new_array[] = {0, 1, 2, 3, 5, 6};
    int size = sizeof(new_array) / sizeof(int);
    
    int missing_ele = missing_element(new_array, size); 
    cout<<"The missing Element is : "<<missing_ele;
    
    return 0;
}
