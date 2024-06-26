#include<iostream>
#include<climits>
using namespace std;

int totalSum(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return total;
}

int main(){
    int my_arr[] = {10, 20, 30, -50, -30, 100, 1000};
    int size = sizeof(my_arr)/sizeof(int);
    
    int sum = totalSum(my_arr, size);
    cout<<"Total Sum is : "<<sum;
    return 0;
}

