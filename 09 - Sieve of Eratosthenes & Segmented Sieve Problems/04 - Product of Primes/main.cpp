class Solution{
private :
    vector<int> sieve(int n){
        vector<bool> isPrime(n+1, true);
        
        isPrime[0] = isPrime[1] = false;
        
        vector<int> primes;
        
        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        return primes;
        
    }
public:
    long long primeProduct(long long L, long long R){
        const long long MOD = 1e9 + 7;
        
        int limit = sqrt(R);
        vector<int> primes = sieve(limit);
        
        vector<bool> isPrime(R - L + 1, true);
        long long result = 1;
        
        if (L == 1) isPrime[0] = false;
        
        for(int prime : primes){
            long long start = max((long long) (prime * prime), (L + prime - 1) / prime * prime);
            
            for(long long i = start; i <= R; i += prime){
                isPrime[i - L] = false;
            }
        }
        
        for(int i = 0; i <= R - L; i++){
            if(isPrime[i]){
                result = (result * (L + i)) % MOD;
            }
        }
        
        
        return result;
    }
};
