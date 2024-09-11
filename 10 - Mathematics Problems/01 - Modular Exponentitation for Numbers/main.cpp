class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    int result = 1;
		    
		    while(n>0){
		        
    		    if(n&1){
    		        
    		        result = (1LL * (result) * (x)%M) %M;
    		    }
    		    
    		    x = (1LL * (x)%M * (x)%M) %M;
    		    n = n >> 1;
		    }
		    
		    return result;
		}
};
