// Linear Approach
#include<iostream>
using namespace std;

void reverse_arr(int arr[], int s){
    int reverse_array[s];
    for(int i = 0; i < s; i++){
        reverse_array[i] = arr[s - i - 1];
    }
    
    for(int i = 0; i < s; i++){
        cout<<reverse_array[i]<<" ";
    }
}

int main(){
    int my_array[] = {10, 20, 30, 40, 50, -50, -60};
    int size = sizeof(my_array) / sizeof(int);
    reverse_arr(my_array, size);
}
