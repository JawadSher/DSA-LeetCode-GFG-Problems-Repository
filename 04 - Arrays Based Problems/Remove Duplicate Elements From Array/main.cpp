// Linear Search Approach
#include<iostream>
using namespace std;

void r_duplicate(int arr[], int s) {
    int temp_array[s];
    int new_size = 0;
    
    for(int i = 0; i < s; i++){
        bool isDuplicate = false;
        
        for(int j = 0; j < new_size; j++){
            if(arr[i] == temp_array[j]){
                isDuplicate = true;
                break;
            }
        }
        
        if(!isDuplicate){
            temp_array[new_size++] = arr[i];
        }
    }
    
    int new_array[new_size];
    for(int i = 0; i < new_size; i++){
        new_array[i] = temp_array[i];
    }
    
    for(int i = 0; i < new_size; i++){
        cout<<new_array[i]<<" ";
    }
}

int main() {
    int my_array[] = {10, 20, 30, 40, 50, 10, 60};
    int size = sizeof(my_array) / sizeof(int);
    
    cout<<"Before Remove Duplicates"<<endl;
    for(int i = 0; i < size; i++){
        cout<<my_array[i]<<" ";
    }
    
    cout<<endl;
    cout<<endl;
    
    cout<<"After Remove Duplicates"<<endl;
    r_duplicate(my_array, size);
    return 0;
}
