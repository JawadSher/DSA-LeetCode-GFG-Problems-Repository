#include<iostream>
using namespace std;

int pivot_index(int arr[], int n){
    int index = -1;
    int total_sum = 0;
    int left_sum = 0;
    
    for(int i = 0; i < n; i++){
        total_sum += arr[i];
    }
    
    for(int i = 0; i < n; i++){
        int right_sum = (total_sum - left_sum) - arr[i];
        
        if(left_sum == right_sum){
            return i;
        }
        left_sum += arr[i];
    }
    
    return index;
}

int main(){
    int new_array[] = {10, 20, 30, 60, 40, 5, 5, 10};
    int size = sizeof(new_array) / sizeof(int);
    
    int index = pivot_index(new_array, size);
    cout<<"The Pivot Index is : "<<index;
    return 0;
}
