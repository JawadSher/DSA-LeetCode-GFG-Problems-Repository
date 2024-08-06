#include <iostream>
using namespace std;

int kth_number(int arr[], int n, int k){
    int num = 1;
    int i = 0;
    
    while(i <= n && k > 0){
        if(arr[i] == num){
            i++;
        }else{
            k--;
        }
        num++;
    }
    
    while(k--){
        num++;
    }
    return num-1;
}

int main() {
    int new_array[] = {2,3,4,7,11};
    int k = 5;
    
    int size = sizeof(new_array) / sizeof(new_array[0]);
    int number = kth_number(new_array, size, k);
    cout<<"The missing kth Number is : "<<number<<endl;
    
    return 0;
}
