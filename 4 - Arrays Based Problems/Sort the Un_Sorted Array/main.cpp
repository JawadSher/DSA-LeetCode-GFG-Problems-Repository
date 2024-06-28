#include<iostream>
using namespace std;

void sort_array(int arr[], int n){
    
    for(int i = 0; i < n-1; i++){
        for(int k = 0; k < n-i-1; k++){
            if(arr[k] > arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
}
int main(){
    int new_array[8] = {1, 3, 2, 5, 7, 4, 8, 6};
    sort_array(new_array, 8);
    
    for(int i = 0; i < 8; i++){
        cout<<new_array[i]<<" ";
    }
    
    return 0;
}
