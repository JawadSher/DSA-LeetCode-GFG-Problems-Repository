#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPrimes(int L, int R) {
        if (R <= 1){
            return 0;
        }
        
        vector<bool>prime (R+1, true);
        
        prime[0] = prime[1] = false;
        
        for(int i = 2; i * i <= R; i++){
            if(prime[i]){
                for(int j = i * i; j <= R; j += i){
                    prime[j] = false;
                }
            }
        }
        
        int count = 0;
        for(int i = max(L, 2); i <= R; i++){
            if(prime[i]) count++;
        }
        
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
