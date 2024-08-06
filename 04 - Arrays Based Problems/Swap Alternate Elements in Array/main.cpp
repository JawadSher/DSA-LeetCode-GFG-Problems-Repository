#include<iostream>
using namespace std;

void print_function(int arr[], int s){
    for(int i = 0; i < s; i++){
        cout<<arr[i]<<" ";
    }
}

void swap_function(int arr[], int s){
    int new_array[s];
    
    for(int i = 0; i < s; i=i+2){
        if(i+1 < s){
            new_array[i] = arr[i+1];
            new_array[i+1] = arr[i];
        }else{
            new_array[i] = arr[i];
        }
    }
    
    print_function(new_array, s);
}
int main(){
    int even_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int odd_array[5] = {1, 2, 3, 4, 5};
    
    cout<<"Even Size of Array Swapped : ";
    swap_function(even_array, 8);
    
    cout<<endl;
    
    cout<<"Odd Size of Array Swapped : ";
    swap_function(odd_array, 5);
    return 0;
}
