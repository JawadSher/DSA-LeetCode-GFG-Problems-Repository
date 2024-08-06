// Linear Search Approach
#include<iostream>
using namespace std;

void duplicates(int arr[], int s) {
    int d_size = 0;
    int addr[s];
    
    for(int i = 0; i < s; i++){
        for(int j = i+1; j<s; j++){
            if(arr[i] == arr[j]){
                addr[d_size++] = j;
                break;
            }
        }
    }
    for(int i = 0; i < d_size; i++){
        cout<<arr[addr[i]]<<" value at address "<<addr[i]<<endl;
    }
}

int main() {
    int my_array[] = {10, 20, 30, 40, 50, 10, 60, 20};
    int size = sizeof(my_array) / sizeof(int);
    duplicates(my_array, size);
   
    return 0;
}
