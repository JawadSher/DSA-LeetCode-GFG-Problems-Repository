#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

bool can_ship(int weights[],int n, int t_days, int mid){
    int days = 1;
    int current_load = 0;
    for(int i = 0; i < n; i++){
        if(current_load + weights[i] > mid){
            days++;
            current_load = 0;
            
            if(days > t_days){
                return false;
            }
        }
        current_load += weights[i];
    }
    return true;
}

int ship_with_days(int weights[], int n, int days ){
    int max_weight = *max_element(weights, weights + n);
    int sum_weight = accumulate(weights, weights + n, 0);
    
    int start = max_weight;
    int end = sum_weight;
    
    while(start < end){
        int mid = start + (end - start)/2;
        if(can_ship(weights, n, days, mid)){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    
    int w_length = sizeof(weights) / sizeof(weights[0]);
    int minimum_Capcity = ship_with_days(weights, w_length, days);
    cout<<"Minimum Capacity with "<<days<< " Days : "<<minimum_Capcity;
    
    return 0;
}
