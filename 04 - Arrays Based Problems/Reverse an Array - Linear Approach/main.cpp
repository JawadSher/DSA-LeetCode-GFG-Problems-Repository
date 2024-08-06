// Linear Approach
#include<iostream>
using namespace std;

void reverse_arr(int arr[], int s){
    int start = 0;
    int end = s - 1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int my_array[] = {10, 20, 30, 40, 50, -50, -60};
    int size = sizeof(my_array) / sizeof(int);
    reverse_arr(my_array, size);
    
    for(int i = 0; i < size; i++){
        cout<<my_array[i]<<" ";
    }
    
}
