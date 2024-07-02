#include<iostream>
using namespace std;

int find_sqrt(int num){
    int start = 0;
    int end = num;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end){
        int sqr = mid * mid;
        if(sqr == num){
            return mid;
        }else if (sqr > num){
            end = mid - 1;
        }else{
            start = mid + 1;
            ans = mid;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}


int main(){
    int num = 8;
    int sqrt_num = find_sqrt(num);
    cout<<"Square Root of "<<num<<" is : "<<sqrt_num;
   
    return 0;
}
