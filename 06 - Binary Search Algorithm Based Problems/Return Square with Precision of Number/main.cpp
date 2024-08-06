#include<iostream>
using namespace std;

int find_sqrt(int n){
    int start = 0;
    int end = n;
    int mid = start + (end - start)/2;
    int sqr = 0;
    while(start <= end){
        int square = mid * mid;
        if(square == n){
            return mid;
        }else if(square < n){
            sqr = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return sqr;
}

double set_precision(int num, int precision, int sqr){
    double factor = 1;
    double ans = sqr;
    for(int i = 0; i < precision; i++){
        factor = factor/10;
        for(double j = ans; j*j<num; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int num = 37;
    int precision = 3;
    int sqr = find_sqrt(num);
    cout<<"The Sqrt of "<<num<<" is with precision : "<<set_precision(num, precision, sqr);
    return 0;
}
