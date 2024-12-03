class Solution {
  public:
    int nthFibonacci(int n) {
        vector<int> dp(n+1,  -1);
        
        if(n == 1 || n == 0) return n;
        if(dp[n] != -1) return dp[n];
        
        dp[n] = nthFibonacci(n-1) + nthFibonacci(n-2);
        
        return dp[n];
    }
};
