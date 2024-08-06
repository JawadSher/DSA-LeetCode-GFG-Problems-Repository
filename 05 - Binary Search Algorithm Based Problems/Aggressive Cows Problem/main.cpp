#include<iostream>
#include<algorithm>
using namespace std;

bool is_possible(int stalls[], int s, int c, int mid){
    int cows = 1;
    int last_position = stalls[0];
    for(int i = 0; i < s; i++){
        if(stalls[i] - last_position >= mid){
            cows++;
            if(cows == c){
                return true;
            }
            last_position = stalls[i];
        }
    }
    return false;
}

int aggressive_cows(int stalls[], int s, int c){
    sort(stalls, stalls + s);
    
    int start = 0;
    int end = stalls[s - 1] - stalls[0];
    int mid = start + (end - start)/2;
    int ans = -1;
    
    while(start <= end){
        if(is_possible(stalls, s, c, mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int stalls[5] = {4, 2, 1, 3, 6};
    int cows = 2;
    int possitions = aggressive_cows(stalls, 5, cows);
    cout<<"The possible positions for Aggressive Cow' is : "<<possitions;
    return 0;
}
