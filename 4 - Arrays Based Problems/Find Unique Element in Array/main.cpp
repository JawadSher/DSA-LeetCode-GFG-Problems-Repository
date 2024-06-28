#include<iostream>
using namespace std;

int unique_element(int arr[], int n){
    int element = 0;
    for(int i = 0; i < n; i++){
        element = element ^ arr[i];
    }
    
    return element;
}
int main(){
    int new_array[5] = {10, 20, 30, 20, 10};
    int unique_num = unique_element(new_array, 5);
    cout<<"Unique Element in array is : "<<unique_num;
    
    return 0;
}
