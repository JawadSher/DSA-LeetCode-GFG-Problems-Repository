// Linear Approach
#include<iostream>
using namespace std;

void sec_element(int arr[], int s){
    int first_element = 0;
    int sec_element = 0;
    for(int i = 0; i < s; i++){
        if(arr[i] > first_element){
            sec_element = first_element;
            first_element = arr[i];
        }
    }
    cout<<"The First Largest Element is : "<<first_element<<endl;
    cout<<"The second Largest Element is : "<<sec_element;
}

int main(){
    int my_array[] = {10, 20, 30, 40, 50, -50};
    int size = sizeof(my_array) / sizeof(int);
    sec_element(my_array, size);
}
