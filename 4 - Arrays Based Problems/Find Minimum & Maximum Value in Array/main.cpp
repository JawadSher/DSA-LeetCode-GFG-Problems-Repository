// Linear Search Approach
#include<iostream>
using namespace std;

int maxValue(int arr[], int n){
    int value = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > value){
            value = arr[i];
        }
    }
    return value;
}

int minValue(int arr[], int n){
    int value = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < value){
            value = arr[i];
        }
    }
    return value;
}

int main(){
    int my_arr[] = {10, 20, 30, -50, -30, 100, 1000};
    int size = sizeof(my_arr)/sizeof(int);
    
    int max_val = maxValue(my_arr, size);
    int min_val = minValue(my_arr, size);
    cout<<"Max value is : "<<max_val<<endl;
    cout<<"Min value is : "<<min_val;
    return 0;
}

