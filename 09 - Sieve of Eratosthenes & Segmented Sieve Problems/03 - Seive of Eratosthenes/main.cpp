#include<bits/stdc++.h> 
using namespace std; 
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> primes(N+1, true);
        vector<int> result;
        
        primes[0] = primes[1] = false;
        
        for(int i = 2; i * i <= N; i++){
            if(primes[i]){
                
                for(int j = i*i; j <= N; j += i){
                    primes[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= N; i++){
            if(primes[i]){
                result.push_back(i);
            }
        }
        
        return result;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
