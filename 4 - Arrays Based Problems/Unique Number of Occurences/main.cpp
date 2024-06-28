// Brute Force Approach
#include<iostream>
using namespace std;

void sort_function(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int k = i+1; k < n; k++){
            if(arr[k] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
}

bool unique_occurences(int arr[], int n){
    bool unique_occurences = true;
    int new_arr[100] = {0};
    for(int i = 0; i < n; i++){
        new_arr[arr[i] + 20]++;
    }
    
    sort_function(new_arr, 100);
    
    for(int i = 0; i < 99; i++){
        if(new_arr[i] != 0 && new_arr[i] == new_arr[i+1]){
            unique_occurences = false;
            break;
        }
    }

    return unique_occurences;
}
int main(){
    int new_array[6] = {1, 2, 2, 1, 1, 3};
    bool status = unique_occurences(new_array, 6);
    
    if(status){
        cout<<"Unique Occerences";
    }else{
        cout<<"Duplicate Occerences";
    }
    
    return 0;
}
