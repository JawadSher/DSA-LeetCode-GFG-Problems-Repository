#include<iostream>
using namespace std;

int is_possible(int boards_arr[], int b, int p, int mid){
    int boards = 0;
    int painter = 1;
    
    for(int i = 0; i < b; i++){
        if(boards + boards_arr[i] <= mid){
            boards += boards_arr[i];
        }else{
            painter++;
            if(boards > mid || painter > p){
                return false;
            }
            boards = boards_arr[i];
        }
    }
    return true;
}

int boards_allocation(int boards_arr[], int b, int p){
    int sum = 0;
    for(int i = 0; i < b; i++){
        sum += boards_arr[i];
    }
    
    int start = 0;
    int end = sum - 1;
    int mid = start + (end - start)/2;
    int ans = -1;
    
    while(start <= end){
        if(is_possible(boards_arr, b, p, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int boards[4] = {10, 10, 10, 10};
    int painters = 2;
    int minimum_boards = boards_allocation(boards, 4, painters);
    cout<<"Minimum Number of boards asign to 1 painter : "<<minimum_boards;
    return 0;
}
